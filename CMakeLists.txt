cmake_minimum_required(VERSION 3.10)
project(ti-final-lab-revision VERSION 1.0.0)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall")
# set(GCC_COVERAGE_LINK_FLAGS    "-lm")

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
# set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

# select example to compile, only one option can have state ON
option(LAB3_ZAD1_SOLUTION "Build solution for zad1 from lab3" ON)

if(LAB3_ZAD1_SOLUTION)
  add_subdirectory(solutions/lab3z1)
  list(APPEND EXTRA_LIBS lab3z1)
endif()

add_executable(ti-final-lab-revision main.c)

target_link_libraries(ti-final-lab-revision PUBLIC ${EXTRA_LIBS}
                                            PRIVATE m) # math.h

target_include_directories(ti-final-lab-revision PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}"
                           )

configure_file(ProjectConfig.h.in ProjectConfig.h)  