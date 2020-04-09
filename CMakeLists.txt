cmake_minimum_required(VERSION 3.4)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.251.tar.gz"
    SHA1 "5659b15dc0884d4b03dbd95710e6a1fa0fc3258d"
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



project(logger)
set(LOGGER_VERSION_MAJOR 0)
set(LOGGER_VERSION_MINOR 1)
set(LOGGER_VERSION_PATCH 0)
set(LOGGER_VERSION_TWEAK 0)
set(LOGGER_VERSION
  ${LOGGER_VERSION_MAJOR}.${LOGGER_VERSION_MINOR}.${LOGGER_VERSION_PATCH}.${LOGGER_VERSION_TWEAK})
set(LOGGER_VERSION_STRING "v${LOGGER_VERSION}")

hunter_add_package(nlohmann_json)
find_package(nlohmann_json CONFIG REQUIRED)

add_library(logger INTERFACE)
target_include_directories(logger $CMAKE_CURRENT_SOURCE_DIR/include)

add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/demo/main.cpp)
target_link_libraries(demo logger nlohmann_json::nlohmann_json)
install(TARGETS demo RUNTIME DESTINATION bin)
install(TARGETS logger
    EXPORT logger-config
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT logger-config DESTINATION cmake)


include(CPackConfig.cmake)
