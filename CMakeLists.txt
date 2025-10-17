
cmake_minimum_required(VERSION 3.10) # Minimum required version of CMake

project(MyProject) # Name of the project

# CMake / C++ settings
set(CMAKE_CXX_STANDARD 17)          # Use C++17 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Enforce C++17 (no older standard allowed)

# Library definition
add_library(mylib STATIC
    libs/platform/platform.cpp
)

target_include_directories(mylib PUBLIC
    libs/platform/
)

# Main program
add_executable(main main.cpp) # Create an executable from main.cpp

# Link the main program with the library
target_link_libraries(main PRIVATE mylib)

# Include directories used by the main program
target_include_directories(main PRIVATE
    libs/platform
)

