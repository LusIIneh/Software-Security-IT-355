cmake_minimum_required(VERSION 3.10)
project(ProtectUSB)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(protectusb
    main.cpp
    cipher.cpp
    file_operations.cpp
    usb_detector.cpp
    utils.cpp
)
