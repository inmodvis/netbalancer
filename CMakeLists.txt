cmake_minimum_required(VERSION 3.5)

project(netbalancer)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_HOME_DIRECTORY}/out")

set(SOURCE_FILES
        src/main.cpp
        src/networkbalancer.h
        src/networkbalancer.cpp
        src/configsgetter.h
        src/configsgetter.cpp
        src/tinyxml2/tinyxml2.h
        src/tinyxml2/tinyxml2.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

