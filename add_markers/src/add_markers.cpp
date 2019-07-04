#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include<nav_msgs/Odometry.h>

class AddMarker
{
public:
  AddMarker()
  {
    pub_ = n_.advertise<visualization_msgs::Marker>("visualization_marker", 1);

    sub_ = n_.subscribe("/odom", 1, &AddMarker::callback, this);

  }
  void callback(const nav_msgs::Odometry odom)
  {  
    
    marker_info();
    double base_x = odom.pose.pose.position.x;
    double base_y = odom.pose.pose.position.y;
    //ROS_INFO("odom callback x: %1.2f, y: %1.2f", base_x, base_y);
    double dist_to_pickup = sqrt(pow(base_x -2.5, 2) + pow(base_y - 2.5, 2));
    double dist_to_dropoff = sqrt(pow(base_x + 2, 2) + pow(base_y + 2, 2));   
    double epsilon = 0.5;
    if (!itemCarried && dist_to_pickup > epsilon)
    {
      marker.action = visualization_msgs::Marker::ADD;
      marker.pose.position.x = 2.5;
      marker.pose.position.y = 2.5;
    } 
    else if (!itemCarried && dist_to_pickup <= epsilon)
    {
      ROS_INFO("reach the pickup zone");
      sleep(5);
      itemCarried = true;
      marker.action = visualization_msgs::Marker::DELETE;
    }
    else if (itemCarried && dist_to_dropoff > epsilon)
    {
      marker.action = visualization_msgs::Marker::DELETE;
    }
    else
    { 
      ROS_INFO("reach the dropoff zone");
      sleep(5);
      marker.action = visualization_msgs::Marker::ADD;
      marker.pose.position.x = -2.0;
      marker.pose.position.y = -2.0;
    }
    pub_.publish(marker);    
  }
private:
  ros::NodeHandle n_;
  ros::Publisher pub_;
  ros::Subscriber sub_;
  visualization_msgs::Marker marker;
  static bool itemCarried;
  void marker_info()
  {
       marker.header.frame_id = "/map";
       marker.header.stamp = ros::Time::now();
       marker.ns = "add_marker";
       marker.id = 0;
       marker.type = visualization_msgs::Marker::CUBE;
       marker.pose.position.z = 0;
       marker.pose.orientation.x = 0.0;
       marker.pose.orientation.y = 0.0;
       marker.pose.orientation.z = 0.0;
       marker.pose.orientation.w = 1.0;
       marker.scale.x = 0.2;
       marker.scale.y = 0.2;
       marker.scale.z = 0.2;
       marker.color.r = 0.0f;
       marker.color.g = 1.0f;
       marker.color.b = 0.0f;
       marker.color.a = 1.0;
       marker.lifetime = ros::Duration();
  }
};
bool AddMarker::itemCarried =false;
int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_markers");
  AddMarker amObject;
  ros::spin();
  return 0;
}
