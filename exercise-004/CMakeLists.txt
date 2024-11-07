cmake_minimum_required(VERSION 3.10.2)

# Set the project name
project(exercise-004 VERSION 0.0.1 LANGUAGES CXX)
string(TIMESTAMP BUILD_DATE "%Y-%m-%dT%H:%M:%S")

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include dependencies
find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(Catch2 3 REQUIRED)

# Configure the header file
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/config.h.in" "${CMAKE_CURRENT_BINARY_DIR}/include/config.h" @ONLY)
include_directories("${CMAKE_CURRENT_BINARY_DIR}/include") # Add the output path to the include path

# Add the executable
add_executable(${PROJECT_NAME} main.cpp myVector.cpp)

# Add libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    fmt::fmt
    CLI11::CLI11
    nlohmann_json::nlohmann_json  # Falls nlohmann_json verwendet wird
    Catch2::Catch2)                # Falls Catch2 verwendet wird
