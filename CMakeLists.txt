cmake_minimum_required(VERSION 3.14.0)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

add_subdirectory(vendor/yaml-cpp)
add_subdirectory(inventory-manager)

set_property(TARGET inventory-manager PROPERTY CXX_STANDARD 17)
