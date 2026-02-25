cmake_minimum_required(VERSION 3.22)

project(IClicker C CXX ASM)

# Create firmware target first
add_executable(${PROJECT_NAME})

# Set standards
enable_language(C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Include CubeMX-generated build logic
add_subdirectory(cmake/stm32cubemx)