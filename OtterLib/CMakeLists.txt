cmake_minimum_required(VERSION 3.17)
project(
    OtterLib
    VERSION 0.0.1
    DESCRIPTION
    "Otter Game Engine"
)

file(GLOB CORE_FILES core/src/*.cpp)
add_library(OtterCore STATIC ${CORE_FILES})

file(GLOB NETWORK_FILES network/src/*.cpp)
add_library(OtterNetwork STATIC ${NETWORK_FILES})

file(GLOB GRAPHIC_FILES graphic/src/*.cpp)
add_library(OtterGraphic STATIC ${GRAPHIC_FILES})
