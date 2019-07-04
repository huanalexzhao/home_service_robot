## home_service_robot ##
_Make sure the path of the workspace is "/home/robond/Desktop/catkin_ws/src"_
- ### turtlebot_gazebo ###
  With the **turtlebot_world.launch** you can deploy a turtlebot in a gazebo environment by linking a predefined world file to it. With the **amcl_demo.launch** you can perform a amcl algorithm to localizing your robot's position in the pre-built map and you can use the "2D Nav Goal" in the rviz to manually set the goal for your robot.

- ### turtlebot_teleop ###
  With the **keyboard_teleop.launch** file, you can manually control a robot using keyboard commands. You will use this package to drive robot arround the environment to collect sensor data during mapping process.
  
- ### gmapping ###
  With the **gmapping_demo.launch** file, you can easily perform SLAM and build a map of the environment with a robot equipped with laser range finder sensors or RGB-D cameras. Once the map was generated, open a new terminal and use command "rosrun map_server map_saver -f {YOUR_MAP_NAME}" to save the map.
  
- ### turtlebot_rviz_launchers ###
  With the **view_navigation.launch**file, you can load a preconfigured rviz workspace. You’ll save a lot of time by launching this file, because it will automatically load the robot model, trajectories, and map for you.
  
- ### pick_objects ##
  With the **pick_objects** node, you can communicate with the ROS navigation stack and autonomously send successive goals for your robot to reach. The ROS navigation stack creates a path for your robot based on Dijkstra's algorithm.
  
- ### add_markers ##
  With the **add_markers** node, you can visualize a mark in the rviz to simulate the item which your robot tries to carry from pickup zone to dropoff zone. 
