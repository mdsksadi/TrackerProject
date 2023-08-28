cmake_minimum_required(VERSION 3.0)
project(TrackerProject)

#set the C++ standard
set(CMAKE_CXX_STANDARD)

# Include OpenCV package
find_package(OpenCV REQUIRED)

# Include directories for the project
include_directories(${OpenCV_INCLUDE_DIRS})

# Add source files
set(SOURCES 
    src/tracker.cc 
    src/main.cc
)

# Add an executable target
add_executable(Tracker ${SOURCES})

# Link against the OpenCV Libraries
target_link_libraries(Tracker ${OpenCV_LIBS})