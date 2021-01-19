add_library(lab3z1b Lab3_z1b.c)

target_include_directories(lab3z1b
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(lab3z1b PUBLIC
                           "${PROJECT_BINARY_DIR}")