/*
 *  myFirstApp.cpp
 *  @Created on: 27-June-2020
 *  @Author: Chandramohan Jagtap
 *  @Email:  cmjagtap1@gmail.com
 *  @Description:
 *		This is basic application of telemetry API.
 */
#include <cpp_api/navigation_bridge.h>
#include <iostream>

Navigation nav;
sensor_msgs::Imu att_quat;
geometry_msgs::TwistStamped att_euler;
geometry_msgs::TwistStamped lpos;
mavros_msgs::State vehicle_state;


void attitudeQuatCb(void *_att_quat)
{
    att_quat = * (sensor_msgs::Imu*)(_att_quat);
}


void attitudeEulerCb(void *_att_euler)
{
    att_euler = * (geometry_msgs::TwistStamped*)(_att_euler);
    std::cout<<"\nroll \t\tpitch \t\tyaw \t\trollspeed \tpitchspeed \tyawspeed";
    std::cout<<"\n"<<att_euler.twist.linear.x<<"\t"<<att_euler.twist.linear.y<<"\t"<<att_euler.twist.linear.z;
    std::cout<<"\t"<<att_euler.twist.angular.x<<"\t"<<att_euler.twist.angular.y<<"\t"<<att_euler.twist.angular.z;
    fflush(stdout);
}


void lposCb(void *_lpos)
{
    lpos = * (geometry_msgs::TwistStamped*)(_lpos);
}


void vehicleModeCb(void *_vehicle_state)
{
    vehicle_state = * (mavros_msgs::State*)(_vehicle_state);
}
int main(int argc, char *argv[])
{

    nav.sysSubscribe(Navigation::vehicle_attitude_quat,attitudeQuatCb);
    std::cout << att_quat << std::endl;
    
    nav.sysSubscribe(Navigation::vehicle_attitude_euler,attitudeEulerCb);
    while(ros::ok())
    {
        sleep(0.2);
    }

    nav.sysSubscribe(Navigation::local_position,lposCb);
    std::cout << lpos << std::endl;

    nav.sysSubscribe(Navigation::vehicle_state,vehicleModeCb);
    std::cout << vehicle_state << std::endl;
}