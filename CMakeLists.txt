cmake_minimum_required(VERSION 3.16)

include(pico-sdk/pico_sdk_init.cmake)

project(PicoSdkTests)

pico_sdk_init()

add_link_options("-Wl,--print-memory-usage")

add_executable(PicoSdkTests main.c)

target_link_libraries(PicoSdkTests pico_stdlib)

pico_enable_stdio_usb(PicoSdkTests 1)
pico_enable_stdio_uart(PicoSdkTests 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(PicoSdkTests)
