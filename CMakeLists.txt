cmake_minimum_required(VERSION 3.16)

include(pico-sdk/pico_sdk_init.cmake)

project(PicoSdkTests)

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

add_executable(PicoSdkTests main.c)

target_link_libraries(PicoSdkTests pico_stdlib)

pico_enable_stdio_usb(PicoSdkTests 1)
pico_enable_stdio_uart(PicoSdkTests 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(PicoSdkTests)
