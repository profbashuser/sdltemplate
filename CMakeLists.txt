cmake_minimum_required(VERSION 3.24)
project(Doomer LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(vendor)
add_subdirectory(src)

# Optionally run the project after build
add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)