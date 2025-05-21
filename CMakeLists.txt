cmake_minimum_required(VERSION 3.15)
project(Rock_Paper_Scissors_Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# Add the executable from the src folder
add_executable(Rock_Paper_Scissors_Game src/main.cpp)