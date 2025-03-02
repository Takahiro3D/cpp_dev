
cmake_minimum_required(VERSION 3.14)
project(example_googletest_on_cmake)

set(CMAKE_CXX_STANDARD 20)
option(COVERAGE "Enable coverage reporting" OFF)
if(COVERAGE)
    if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(FATAL_ERROR "Code coverage requires Debug build")
    endif()
    message(STATUS "Enabling code coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(test_myabs 
${CMAKE_SOURCE_DIR}/src/myabs.cpp
${CMAKE_SOURCE_DIR}/test/gtest_main.cpp
)
target_include_directories(test_myabs PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(test_myabs gtest_main)

add_test(NAME test COMMAND test_myabs)
enable_testing()
