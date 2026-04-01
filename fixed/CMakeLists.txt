cmake_minimum_required(VERSION 3.10)
project(LicensingSystem)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_WINSOCK_DEPRECATED_NO_WARNINGS")
endif()

add_executable(LicensingSystem
    main.cpp
    HardwareID.cpp
    LicenseKey.cpp
    LicenseManager.cpp
)

if(WIN32)
    target_link_libraries(LicensingSystem PRIVATE
        iphlpapi
        wbemuuid
        ws2_32
    )
endif()