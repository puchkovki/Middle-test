cmake_minimum_required(VERSION 3.4)

# include HunterGate
include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.251.tar.gz"
    SHA1 "5659b15dc0884d4b03dbd95710e6a1fa0fc3258d"
)

# add minimum required standards
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# name the project
project(log)

# add hunter package
hunter_add_package(nlohmann_json)
find_package(nlohmann_json CONFIG REQUIRED)

# add libraries
add_library(logger INTERFACE)
target_include_directories(logger INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# add source files
add_executable(demo demo/main.cpp)
target_link_libraries(demo logger nlohmann_json::nlohmann_json)
