/*
 *  myFirstApp.cpp
 *  @Created on: 27-June-2020
 *  @Author: Chandramohan Jagtap
 *  @Email:  cmjagtap1@gmail.com
 *  @Description:
 *		This is basic application of Parameters API.
 */
#include <cpp_api/param_bridge.h>

int main(int argc, char *argv[])
{

    Param param;


    std::string param_id = "RTL_ALT"; 

    std::string param_value = "5";
    param.param_set(param_id, param_value); // Here we have set RTL altitude = 5
    
    param.param_get(param_id, param_value);
    std::cout << "Parameter value: " << param_value << std::endl; // we have requested RTL altitude from vecicle
    
    std::string param_value1 = "";
    param.param_get("RTL_LOIT_TIME",param_value1);
    std::cout << "Parameter value: " << param_value1 << std::endl; // we have requested RTL loiter time from vecicle

}