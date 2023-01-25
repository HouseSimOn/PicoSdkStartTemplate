cmake_minimum_required(VERSION 3.16)

include(Sources/Sdk/pico-sdk/pico_sdk_init.cmake)

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

add_executable(PicoSdkStartTemplate Sources/main.c)

target_link_libraries(PicoSdkStartTemplate pico_stdlib)

if(${PICO_BOARD} STREQUAL "pico_w")
    target_link_libraries(PicoSdkStartTemplate pico_cyw43_arch_none)
endif()

# list(APPEND SOURCES_LIST_REGEX *.c *.h)
# list(APPEND SOURCES_DIRS ${CMAKE_CURRENT_LIST_DIR}/Sources/)

pico_enable_stdio_usb(PicoSdkStartTemplate 1)
pico_enable_stdio_uart(PicoSdkStartTemplate 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(PicoSdkStartTemplate)
