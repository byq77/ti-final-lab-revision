cmake_minimum_required(VERSION 3.10)
project(ti-final-lab-revision VERSION 1.0.0)

set(CMAKE_C_STANDARD 99)

set(SYSTEM_DATA_SETS_ABS_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(SYSTEM_DATA_SETS_REL_PATH "test_data")


set(GCC_COVERAGE_COMPILE_FLAGS "-Wall")
# set(GCC_COVERAGE_LINK_FLAGS    "-lm")

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
# set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

# select example to compile, only one option can have state ON
option(LAB3_ZAD1_SOLUTION "Build solution for zad1 from lab3" OFF)
option(LAB3_ZAD1A_SOLUTION "Build solution for zad1a" OFF)
option(LAB3_ZAD1B_SOLUTION "Build solution for zad1b" OFF)
option(LAB3_ZAD2_SOLUTION "Build solution for zad2 from lab3" OFF)
option(LAB3_ZAD3_SOLUTION "Build solution for zad3 from lab3" ON)
option(LAB3_ZAD4_SOLUTION "Build solution for zad4 from lab3" OFF)
option(LAB3_ZAD5_SOLUTION "Build solution for zad5 from lab3" OFF)
option(LAB4_ZAD1_SOLUTION "Build solution for zad1 from lab4" OFF)
option(LAB4_ZAD2_SOLUTION "Build solution for zad2 from lab4" OFF)
option(LAB4_ZAD3_SOLUTION "Build solution for zad3 from lab4" OFF)
option(LAB4_ZAD4_SOLUTION "Build solution for zad4 from lab4" OFF)

if(LAB3_ZAD1_SOLUTION)
  add_subdirectory(solutions/lab3z1)
  list(APPEND EXTRA_LIBS lab3z1)
  set(TEST_DATA_REL_PATH "test_data/lab3z1_dane.txt")
  get_filename_component(TEST_DATA_ABS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${TEST_DATA_REL_PATH} ABSOLUTE)
elseif(LAB3_ZAD1A_SOLUTION)
  add_subdirectory(solutions/lab3z1a)
  list(APPEND EXTRA_LIBS lab3z1a)
  set(TEST_DATA_REL_PATH "test_data/lab3z1ab_dane.bin")
  get_filename_component(TEST_DATA_ABS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${TEST_DATA_REL_PATH} ABSOLUTE)
elseif(LAB3_ZAD1B_SOLUTION)
  add_subdirectory(solutions/lab3z1b)
  list(APPEND EXTRA_LIBS lab3z1b)
  set(TEST_DATA_REL_PATH "test_data/lab3z1ab_dane.bin")
  get_filename_component(TEST_DATA_ABS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${TEST_DATA_REL_PATH} ABSOLUTE)
elseif(LAB3_ZAD2_SOLUTION)
  add_subdirectory(solutions/lab3z2)
  list(APPEND EXTRA_LIBS lab3z2)
  set(TEST_DATA_REL_PATH "test_data/lab3z2_dane.txt")
  get_filename_component(TEST_DATA_ABS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${TEST_DATA_REL_PATH} ABSOLUTE)
elseif(LAB3_ZAD3_SOLUTION)
  add_subdirectory(solutions/lab3z3)
  list(APPEND EXTRA_LIBS lab3z3)
  set(TEST_DATA_REL_PATH "test_data/lab3z3_dane.txt")
  get_filename_component(TEST_DATA_ABS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${TEST_DATA_REL_PATH} ABSOLUTE)
elseif(LAB3_ZAD4_SOLUTION)
  add_subdirectory(solutions/lab3z4)
  list(APPEND EXTRA_LIBS lab3z4)
elseif(LAB3_ZAD5_SOLUTION)
  add_subdirectory(solutions/lab3z5)
  list(APPEND EXTRA_LIBS lab3z5)
elseif(LAB4_ZAD1_SOLUTION)
  add_subdirectory(solutions/lab4z1)
  list(APPEND EXTRA_LIBS lab4z1)
  set(TEST_DATA_REL_PATH "test_data/lab4z1_dane.txt")
  get_filename_component(TEST_DATA_ABS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${TEST_DATA_REL_PATH} ABSOLUTE)
elseif(LAB4_ZAD2_SOLUTION)
  add_subdirectory(solutions/lab4z2)
  list(APPEND EXTRA_LIBS lab4z2)
elseif(LAB4_ZAD3_SOLUTION)
  add_subdirectory(solutions/lab4z3)
  list(APPEND EXTRA_LIBS lab4z3)
elseif(LAB4_ZAD4_SOLUTION)
  add_subdirectory(solutions/lab4z4)
  list(APPEND EXTRA_LIBS lab4z4)
endif()

add_executable(ti-final-lab-revision main.c)

target_link_libraries(ti-final-lab-revision PUBLIC ${EXTRA_LIBS}
                                            PRIVATE m) # math.h

target_include_directories(ti-final-lab-revision PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}"
                           )

configure_file(ProjectConfig.h.in ProjectConfig.h @ONLY)  