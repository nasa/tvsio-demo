cmake_minimum_required(VERSION 2.6)
project(PROTOBETTER_TEST CXX)

find_package(Threads REQUIRED)
find_package(PythonInterp 2.7 REQUIRED)
find_package(GTest REQUIRED)

set(PROTOBETTER_TEST_INCLUDE_DIRS
    ${GTEST_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}    
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    compile_prototypes ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/protobetter_generated.c ${CMAKE_CURRENT_BINARY_DIR}/protobetter_generated.h mybogusfile.h
    COMMENT "Generate protobetter serialization code during build"
)

# had to add "mybogusfile.h" which is never generated so the custom target above would always force this command to run...
# runs everytime no matter the state of prototype files and works with older cmake versions...
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/protobetter_generated.c ${CMAKE_CURRENT_BINARY_DIR}/protobetter_generated.h mybogusfile.h
    COMMAND ${PYTHON_EXECUTABLE} "${CMAKE_CURRENT_SOURCE_DIR}/generate_test_code.py" 
)

set(PROTOBETTER_GENERATED_LIB_SRC
    ${CMAKE_CURRENT_BINARY_DIR}/protobetter_generated.c
    ${CMAKE_CURRENT_SOURCE_DIR}/test_stubs.cpp
)

set_source_files_properties(${PROTOBETTER_GENERATED_LIB_SRC} PROPERTIES LANGUAGE CXX)

add_library(protobetter_generated_lib SHARED ${PROTOBETTER_GENERATED_LIB_SRC})
set_target_properties(protobetter_generated_lib PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(protobetter_generated_lib PRIVATE ${PROTOBETTER_TEST_INCLUDE_DIRS})
add_dependencies(protobetter_generated_lib compile_prototypes)

add_executable(protobetter_amps_test ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_include_directories(protobetter_amps_test PRIVATE ${PROTOBETTER_TEST_INCLUDE_DIRS})
target_link_libraries(protobetter_amps_test protobetter_generated_lib ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
