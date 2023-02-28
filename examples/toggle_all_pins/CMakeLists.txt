# Specify required cmake version
cmake_minimum_required(VERSION 3.20)
cmake_policy(VERSION 3.20)

# Fix to deal with potential compile problems
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

# Export a json containing the build commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set a default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Include the pico sdk
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Define the project
project(mcp23017_lib_example_toggle_all_pins C CXX ASM)

# Initialize the pico sdk
pico_sdk_init()

# Add the source files
add_executable(${PROJECT_NAME}
    main.c
)

# Include the MCP23017 library
add_subdirectory(src)

# Link the needed libraries
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    hardware_i2c
    mcp23017_lib
)

# Enable most warnings
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -W -Wconversion -Wshadow -Wcast-qual -Wwrite-strings)

# Set and enforce the C standards
set_target_properties(${PROJECT_NAME} PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED On
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED On
)

# Add optimizations based on the build level
if (CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_options(${PROJECT_NAME} PRIVATE -O2)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Og)
endif()

# Use USB for printf
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# Generate the needed output files
pico_add_extra_outputs(${PROJECT_NAME})
