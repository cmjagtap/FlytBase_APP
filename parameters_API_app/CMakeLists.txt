cmake_minimum_required(VERSION 2.8.3)
project(parameters_API_app)

SET(CMAKE_INSTALL_PREFIX /usr/local/flytos/userapps CACHE PATH "Cmake install prefix path for flytapps" FORCE)

add_definitions(-std=c++11)

cmake_minimum_required(VERSION 2.8.3)
find_package(catkin REQUIRED COMPONENTS cpp_api)
find_package(Boost REQUIRED COMPONENTS system python)
find_package(PythonLibs 2.7 REQUIRED)
include_directories(${catkin_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})

add_executable(parameters_API_app parameters_API_app.cpp)
target_link_libraries(parameters_API_app ${catkin_LIBRARIES} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

install(TARGETS parameters_API_app
  DESTINATION /flyt/userapps/onboard_user/install COMPONENT Runtime
)
