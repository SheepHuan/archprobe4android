# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.

project("archprobe" LANGUAGES C CXX)




message("-- Looking for libopencl-stub")
if (EXISTS "${PROJECT_SOURCE_DIR}/third/libopencl-stub")
    add_compile_definitions(CL_VERSION_2_0)
    add_subdirectory(third/libopencl-stub)
    set(OpenCL_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/third/libopencl-stub/include")
    message("-- OpenCL context enabled")
else()
    message("")
    message("-- OpenCL not found! OpenCL context is disabled")
    message("")
endif()
set(LINK_LIBS
        OpenCL
        )
set(INC_DIRS
        "${PROJECT_SOURCE_DIR}/include"
        ${OpenCL_INCLUDE_DIR}
        ${CMAKE_SOURCE_DIR}/third/OpenCL-SDK/external/OpenCL-CLHPP/include
        )

include_directories(${INC_DIRS})
file(GLOB SRCS "${PROJECT_SOURCE_DIR}/src/*")
file(GLOB INCS "${PROJECT_SOURCE_DIR}/include/*")
add_library( # Sets the name of the library.
        archprobe

        # Sets the library as a shared library.
        SHARED

        ${SRCS}
        ${INCS}
        apps/archprobe/env.hpp
        apps/archprobe/env.cpp
        apps/archprobe/app.cpp



        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        archprobe
        ${LINK_LIBS}
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})