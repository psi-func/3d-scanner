cmake_minimum_required(VERSION 3.16)
project(3D-scanning)

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS program_options REQUIRED)

if (DEFINED ENV{IVP_3D_CAMERA})
    set(IVP_LIB $ENV{IVP_3D_CAMERA}icon)
    message("Found ivc: " ${IVP_LIB})
else()
    message(SEND_ERROR "IVP camera API is not installed in your system")
endif ()

add_executable(${PROJECT_NAME} main.cpp ThreadSafePrint.h cmake-build-debug/setup.h)
target_include_directories(${PROJECT_NAME} BEFORE PUBLIC ${IVP_LIB}/inc ${Boost_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} BEFORE PUBLIC ${IVP_LIB}/lib)
target_link_libraries(${PROJECT_NAME} PUBLIC ${Boost_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED yes
        )

target_link_libraries(${PROJECT_NAME}
        PUBLIC ${CMAKE_THREAD_LIBS_INIT})