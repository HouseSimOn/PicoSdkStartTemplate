cmake_minimum_required(VERSION 3.16)

include(pico-sdk/pico_sdk_init.cmake)

project(PicoSdkTests)

pico_sdk_init()

add_executable(PicoSdkTests main.c)

target_link_libraries(PicoSdkTests pico_stdlib)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(PicoSdkTests)