cmake_minimum_required(VERSION 3.16)

include(Sdk/pico-sdk/pico_sdk_init.cmake)

project(PicoSdkStartTemplate)

# Pico platform - rp2040 default
# set(PICO_PLATFORM "rp2040")

# Pico compiler - pico_arm_gcc default
# set(PICO_COMPILER "pico_arm_gcc")

# Set PICO_BOARD to pico_w. Comment it to leave default pico.
# set(PICO_BOARD pico_w)

# Set build type - release default
# set(CMAKE_BUILD_TYPE "Release")

pico_sdk_init()

add_link_options("-Wl,--print-memory-usage")

set(SOURCES)
set(INCLUDE_DIRS)

# To use Regex
# file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "Source/*.c")
# file(GLOB_RECURSE INCLUDES RELATIVE ${CMAKE_SOURCE_DIR} "Source/*.h")

add_subdirectory("Source")

message(Sources -> ${SOURCES})
message(Includes -> ${INCLUDES})
message(IncludeDirs -> ${INCLUDE_DIRS})

add_executable(PicoSdkStartTemplate ${SOURCES} ${INCLUDES})

target_link_libraries(PicoSdkStartTemplate pico_stdlib)

include_directories(${INCLUDE_DIRS})

if(${PICO_BOARD} STREQUAL "pico_w")
    target_link_libraries(PicoSdkStartTemplate pico_cyw43_arch_none)
endif()

pico_enable_stdio_usb(PicoSdkStartTemplate 1)
pico_enable_stdio_uart(PicoSdkStartTemplate 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(PicoSdkStartTemplate)
