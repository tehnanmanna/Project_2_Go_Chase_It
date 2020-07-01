  
#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lx, float az)
{
    // Request a service and pass the velocities to it to drive the robot
    ball_chaser::DriveToTarget service;
    service.request.linear_x = lx;
    service.request.angular_z = az;
    // Call command_robot service
    if (!client.call(service)) {
        ROS_ERROR("Failed to call service command_robot");
    }
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    // Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera

    int white_pixel = 255;
    bool is_ball_found = false;
    float lx = 0;
    float az = 0;
    for (int i = 0; i < img.height * img.step; i += 3) {
	if (img.data[i] == white_pixel && img.data[i + 1] == white_pixel && img.data[i + 2] == white_pixel) {
	    is_ball_found = true;
	    int row_found = i % img.step;
	    if (row_found < img.step / 3) {
            // Turn Left
            lx = 0.0;
            az = 0.2;
	    }
	    else if (row_found > img.step * 2 / 3) {
            // Turn Right
            lx = 0.0;
            az = -0.2;
	    }
	    else {
            // Move Forward
            lx = 0.5;
    	    az = 0.0;
	    
}
	        break;
        }
    }	
    drive_robot(lx, az);
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
