#!/bin/sh
xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/robond/Desktop/catkin_ws/src/map/test.world" &
sleep 5
xterm -e "source /opt/ros/kinetic/setup.bash; source /home/robond/Desktop/catkin_ws/devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/robond/Desktop/catkin_ws/src/map/map.yaml" &
sleep 5
xterm -e "source /opt/ros/kinetic/setup.bash; source /home/robond/Desktop/catkin_ws/devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch"  &
sleep 5
xterm -e "source /opt/ros/kinetic/setup.bash; source /home/robond/Desktop/catkin_ws/devel/setup.bash; rosrun add_markers add_markers" 
