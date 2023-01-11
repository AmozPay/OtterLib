cmake_minimum_required(VERSION 3.17)

# define project version with CI build
if(DEFINED ENV{PROJECT_VERSION})
    project(
        OtterLib
        VERSION $ENV{PROJECT_VERSION}
        DESCRIPTION "Otter Game Engine"
    )
else()
    project(
        OtterLib
        VERSION 0.1.0
        DESCRIPTION "Otter Game Engine"
    )
endif()

# Create Static Libraries

file(GLOB CORE_FILES core/src/*.cpp)
add_library(OtterCore STATIC ${CORE_FILES})
target_compile_features(OtterCore PUBLIC cxx_std_20)
target_include_directories(OtterCore PUBLIC core/include)

file(GLOB NETWORK_FILES network/src/*.cpp)
add_library(OtterNetwork STATIC ${NETWORK_FILES})
target_compile_features(OtterNetwork PUBLIC cxx_std_20)
target_include_directories(OtterNetwork PUBLIC network/include)


file(GLOB GRAPHIC_FILES graphic/src/*.cpp)
add_library(OtterGraphic STATIC ${GRAPHIC_FILES})
target_compile_features(OtterGraphic PUBLIC cxx_std_20)
target_include_directories(OtterGraphic PUBLIC graphic/include)

# Find headers
file(GLOB CORE_HEADERS core/include/*.hpp)
file(GLOB NETWORK_HEADERS network/include/*.hpp)
file(GLOB GRAPHIC_HEADERS graphic/include/*.hpp)

# Add headers to installed elements
install(FILES 
    ${GRAPHIC_HEADERS}
    ${NETWORK_HEADERS}
    ${CORE_HEADERS}
    DESTINATION "include")

# Add static libraries to installed elements
# Export them for use in other CMakes
install(TARGETS
    OtterGraphic
    OtterNetwork
    OtterCore
    EXPORT OtterLib
    DESTINATION lib)

# Bundle output with cpack
include(CPack)