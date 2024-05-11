add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
    WADReader.cpp
    WADLoader.cpp
    Main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE vendor)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)