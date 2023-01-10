cmake_minimum_required(VERSION 3.17)
project(
    OtterLib
    VERSION 0.0.1
    DESCRIPTION
    "Otter Game Engine"
)


file(GLOB CORE_FILES core/src/*.cpp)
file(GLOB CORE_HEADERS core/include/*.hpp)

add_library(OtterCore STATIC ${CORE_FILES})
target_compile_features(OtterCore PUBLIC cxx_std_20)
install(TARGETS OtterCore RUNTIME DESTINATION bin)
install(FILES ${CORE_HEADERS} DESTINATION "include")

file(GLOB NETWORK_FILES network/src/*.cpp)
file(GLOB NETWORK_HEADERS network/include/*.hpp)

add_library(OtterNetwork STATIC ${NETWORK_FILES})
target_compile_features(OtterNetwork PUBLIC cxx_std_20)
install(TARGETS OtterNetwork RUNTIME DESTINATION bin)
install(FILES ${NETWORK_HEADERS} DESTINATION "include")


file(GLOB GRAPHIC_FILES graphic/src/*.cpp)
file(GLOB GRAPHIC_HEADERS graphic/include/*.hpp)

add_library(OtterGraphic STATIC ${GRAPHIC_FILES})
target_compile_features(OtterGraphic PUBLIC cxx_std_20)
install(TARGETS OtterGraphic RUNTIME DESTINATION bin)
install(FILES ${GRAPHIC_HEADERS} DESTINATION "include")

# CPack allows automatic target bundling (create archive with installable libraries)
include(CPack)