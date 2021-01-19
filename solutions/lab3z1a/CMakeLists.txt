add_library(lab3z1a Lab3_z1a.c)

target_include_directories(lab3z1a
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(lab3z1a PUBLIC
                           "${PROJECT_BINARY_DIR}")