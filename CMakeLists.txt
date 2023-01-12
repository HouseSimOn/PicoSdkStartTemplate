cmake_minimum_required(VERSION 3.16)

include(pico-sdk/pico_sdk_init.cmake)

project(PicoSdkTests)

pico_sdk_init()

add_executable(PicoSdkTests main.c)

target_link_libraries(PicoSdkTests pico_stdlib)

pico_add_extra_outputs(PicoSdkTests)