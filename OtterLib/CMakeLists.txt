cmake_minimum_required(VERSION 3.17)
project(
    OtterLib
    VERSION 0.0.1
    DESCRIPTION
    "Otter Game Engine"
)


file(GLOB CORE_FILES core/src/*.cpp)
add_library(OtterCore STATIC ${CORE_FILES})
target_compile_features(OtterCore PUBLIC cxx_std_20)

file(GLOB NETWORK_FILES network/src/*.cpp)
add_library(OtterNetwork STATIC ${NETWORK_FILES})
target_compile_features(OtterNetwork PUBLIC cxx_std_20)

file(GLOB GRAPHIC_FILES graphic/src/*.cpp)
add_library(OtterGraphic STATIC ${GRAPHIC_FILES})
target_compile_features(OtterGraphic PUBLIC cxx_std_20)
