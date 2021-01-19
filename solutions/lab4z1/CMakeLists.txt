add_library(lab4z1 Lab4_z1.c)

target_include_directories(lab4z1
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(lab4z1 PUBLIC
                           "${PROJECT_BINARY_DIR}")