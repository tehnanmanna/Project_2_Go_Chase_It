# Project_2_Go_Chase_It

Project 2 of Udacity Robotics Software Engineer Nanodegree Program

## Overview  
In this project you'll create two ROS packages inside your `catkin_ws/src`: the `drive_bot` and the `ball_chaser` which will be used in Gazebo for all your upcoming projects in the [Udacity Robotics Software Engineer Nanodegree Program](https://www.udacity.com/course/robotics-software-engineer--nd209). Here are the steps to design the robot, house it inside your world, and program it to chase white-colored balls:  
1. `drive_bot`:  
* Create a `my_robot` ROS package to hold your robot, the white ball, and the world.
* Design a differential drive robot with the Unified Robot Description Format. Add two sensors to your robot: a lidar and a camera. Add Gazebo plugins for your robot’s differential drive, lidar, and camera. The robot you design should be significantly different from the one presented in the project lesson. Implement significant changes such as adjusting the color, wheel radius, and chassis dimensions. Or completely redesign the robot model! After all you want to impress your future employers :-D
* House your robot inside the world you built in the **Build My World** project.
* Add a white-colored ball to your Gazebo world and save a new copy of this world.
* The `world.launch` file should launch your world with the white-colored ball and your robot.
2. `ball_chaser`:
* Create a `ball_chaser` ROS package to hold your C++ nodes.
* Write a `drive_bot` C++ node that will provide a `ball_chaser/command_robot` service to drive the robot by controlling its linear x and angular z velocities. The service should publish to the wheel joints and return back the requested velocities.
* Write a `process_image` C++ node that reads your robot’s camera image, analyzes it to determine the presence and position of a white ball. If a white ball exists in the image, your node should request a service via a client to drive the robot towards it.
* The `ball_chaser.launch` should run both the `drive_bot` and the `process_image` nodes.  
## Prerequisites/Dependencies  
* Gazebo >= 7.0  
* ROS Kinetic  
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
## Setup Instructions (abbreviated)  
1. Meet the `Prerequisites/Dependencies`  
2. Open Ubuntu Bash and clone the project repository  
3. On the command line execute  
```bash
sudo apt-get update && sudo apt-get upgrade -y
```
4. Build and run your code.  
## Project Description  
Directory Structure  
```
Project_2                                   # Go Chase It Project
├── Project_2                                  # Catkin workspace
│   ├── src
│   │   ├── ball_chaser                        # ball_chaser package        
│   │   │   ├── launch                         # launch folder for launch files
│   │   │   │   ├── ball_chaser.launch
│   │   │   ├── src                            # source folder for C++ scripts
│   │   │   │   ├── drive_bot.cpp
│   │   │   │   ├── process_images.cpp
│   │   │   ├── srv                            # service folder for ROS services
│   │   │   │   ├── DriveToTarget.srv
│   │   │   ├── CMakeLists.txt                 # compiler instructions
│   │   │   ├── package.xml                    # package info
│   │   ├── my_robot                           # my_robot package        
│   │   │   ├── launch                         # launch folder for launch files   
│   │   │   │   ├── robot_description.launch
│   │   │   │   ├── world.launch
│   │   │   ├── meshes                         # meshes folder for sensors
│   │   │   │   ├── hokuyo.dae
│   │   │   ├── urdf                           # urdf folder for xarco files
│   │   │   │   ├── my_robot.gazebo
│   │   │   │   ├── my_robot.xacro
│   │   │   ├── worlds                         # world folder for world files
│   │   │   │   ├── tehnanworld.world
│   │   │   ├── CMakeLists.txt                 # compiler instructions
│   │   │   ├── package.xml                    # package info

```
- [drive_bot.cpp](/Project_2/src/ball_chaser/src/drive_bot.cpp): ROS service C++ script, command the robot with specify speeds.  
- [process_images.cpp](/Project_2/src/ball_chaser/src/process_images.cpp): ROS service C++ script, process the camera image and return requested speeds.  
- [robot_description.launch](/Project_2/src/my_robot/launch/robot_description.launch): Create robot model in Gazebo world.  
- [world.launch](/Project_2/src/my_robot/launch/world.launch): Launch my_robot mode in Gazebo world with building and plugins.  
- [tehnanworld.world](/Project_2/src/my_robot/worlds/myoffice.world): Gazebo world file that includes the models.  
- [CMakeLists.txt](/Project_2/src/my_robot/CMakeLists.txt): File to link the C++ code to libraries.  
- [robot_description.launch](/Project_2/src/my_robot/launch/robot_description.launch): Create robot model in Gazebo world.  
- [hokuyo.dae](/Project_2/src/my_robot/meshes/hokuyo.dae): Hokuyo LiDAR sensor mesh model.  
- [my_robot.gazebo](/Project_2/src/my_robot/URDF/my_robot.gazebo): Define my_robot URDF model plugins.  
- [my_robot.xacro](/Project_2/src/my_robot/URDF/my_robot.xacro): Define my_robot URDF model.  

## Run the project  
* Clone this repository
* Open the repository and make  
```
cd /home/Project_2/
catkin_make
```
* Launch my_robot/my_robot in Gazebo to load both the world and plugins  
```
roslaunch my_robot world.launch
```  
```  
* Launch ball_chaser and process_image nodes  
```
cd /home/Project_2/
source devel/setup.bash
roslaunch ball_chaser ball_chaser.launch
```  
* Visualize  
```
cd /home/Project_2/
source devel/setup.bash
rosrun rqt_image_view rqt_image_view  
```  

## Tips  
1. It's recommended to update and upgrade your environment before running the code.  
```bash
sudo apt-get update && sudo apt-get upgrade -y
```

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Rubric  
### 1. Basic Requirements  
#### 1.1 Does the submission include the my_robot and the ball_chaser ROS packages?  
Yes, it does.  
### 1.2 Do these packages follow the directory structure detailed in the project description section?
Yes, it does.  
### 2. Robot Design
#### 2.1 Does the submission include a design for a differential drive robot, using the Unified Robot Description Format?  
Yes, it does.  
### 3. Gazebo World  
#### 3.1 Does the my_robot ROS package contain the Gazebo world?  
Yes, it does.  
### 4. Ball Chasing  
#### 4.1 Does the ball_chaser ROS package contain two C++ ROS nodes to interact with the robot and make it chase a white-colored ball?  
Yes, it does.  
### 5. Launch Files  
#### 5.1 Does the submission include world.launch and ball_chaser.launch files that launch all the nodes in this project?  
Yes, it does.  
