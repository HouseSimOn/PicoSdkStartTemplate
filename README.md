[![Build](https://github.com/HouseSimOn/PicoSdkTests/actions/workflows/build_cmake.yml/badge.svg)](https://github.com/HouseSimOn/PicoSdkTests/actions/workflows/build_cmake.yml)

# PicoSdkTests
Repo used to perform tests with Pi Pico SDK

# Documentation
https://raspberrypi.github.io/pico-sdk-doxygen/modules.html

## Performed steps

Platform: Ubuntu

Based on: https://github.com/raspberrypi/pico-sdk

1. Repository created and cloned `git clone https://github.com/HouseSimOn/PicoSdkTests.git`.
2. Added submodule using `git submodule add https://github.com/raspberrypi/pico-sdk.git pico-sdk` command.
3. Commit: `git commit -m "Added pico-sdk submodule"`.
4. Call `git submodule update --init` in the main directory and then go to the pico-sdk and call this command again.
5. Create settings.json for intellisense work with following content
    ```json
    { 
        "C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools" 
    } 
    ```

### printf - via USB
1. To CMakeLists.txt add following lines:
    ```
    pico_enable_stdio_usb(PicoSdkTests 1)
    pico_enable_stdio_uart(PicoSdkTests 0)
    ```
2. Find connected device: `ls -l /dev/ttyUSB* /dev/ttyACM*`
3. Start minicom: `sudo minicom -b 115200 -o -D /dev/ttyACM0` 

