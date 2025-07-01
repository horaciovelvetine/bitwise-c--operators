cmake_minimum_required(VERSION 3.10)
project(bitwise_operators)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(bitwise_operators src/main.cpp src/bitwise_utils.cpp)

# Include directories
target_include_directories(bitwise_operators PRIVATE include)

# Set compiler flags
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(bitwise_operators PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install target
install(TARGETS bitwise_operators DESTINATION bin) 