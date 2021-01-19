add_library(lab3z3 Lab3_z3.c)

target_include_directories(lab3z3
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(lab3z3 PUBLIC
                           "${PROJECT_BINARY_DIR}")