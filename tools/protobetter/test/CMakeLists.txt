cmake_minimum_required(VERSION 2.6)
project(PROTOBETTER_TEST C CXX)

find_package(Threads REQUIRED)
find_package(PythonInterp 2.7 REQUIRED)
find_package(GTest REQUIRED)

set(PROTOTYPE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/test_a/*
    ${CMAKE_CURRENT_SOURCE_DIR}/test_b/*
    ${CMAKE_CURRENT_SOURCE_DIR}/test_c/*    
)

set(PROTOBETTER_TEST_INCLUDE_DIRS
    ${GTEST_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}    
    ${CMAKE_CURRENT_SOURCE_DIR}/test_a
    ${CMAKE_CURRENT_SOURCE_DIR}/test_b
    ${CMAKE_CURRENT_SOURCE_DIR}/test_c    
)

add_custom_target(
    compile_prototypes ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/protobetter_generated.c ${CMAKE_CURRENT_BINARY_DIR}/protobetter_generated.h mybogusfile.h
    COMMENT "Generate code from *.ptype files during protobetter build"
)

# had to add "mybogusfile.h" which is never generated so the custom target above would always force this command to run...
# runs everytime no matter the state of prototype files and works with older cmake versions...
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/protobetter_generated.c ${CMAKE_CURRENT_BINARY_DIR}/protobetter_generated.h mybogusfile.h
    COMMAND ${PYTHON_EXECUTABLE} "${CMAKE_CURRENT_SOURCE_DIR}/../src/protobetter_compiler.py" ${PROTOTYPE_FILES}
)

set(PROTOBETTER_GENERATED_LIB_SRC
    ${CMAKE_CURRENT_BINARY_DIR}/protobetter_generated.c
)

add_compile_options(-DARRAY_NAME=12)
add_compile_options(-DINT8_LEN=12)
add_compile_options(-DINT32_LEN=12)
add_compile_options(-DVECTORC_LEN=3)
add_compile_options(-DLILBITY_LEN=2)

add_library(protobetter_generated_lib SHARED ${PROTOBETTER_GENERATED_LIB_SRC})

target_include_directories(protobetter_generated_lib PRIVATE ${PROTOBETTER_TEST_INCLUDE_DIRS})
add_dependencies(protobetter_generated_lib compile_prototypes)

add_executable(protobetter_test ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_include_directories(protobetter_test PRIVATE ${PROTOBETTER_TEST_INCLUDE_DIRS})
target_link_libraries(protobetter_test protobetter_generated_lib ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
