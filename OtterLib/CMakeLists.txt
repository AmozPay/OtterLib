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

find_program(CONAN conan)
if (NOT CONAN)
    message(FATAL_ERROR "Conan not found!")
endif()

# Check if conan is installed
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_CURRENT_SOURCE_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    # If not, install conan
    execute_process(
            COMMAND conan install ${CMAKE_CURRENT_SOURCE_DIR} --build=missing
            RESULT_VARIABLE result
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/conanbuildinfo.cmake)
        include(${CMAKE_CURRENT_SOURCE_DIR}/conanbuildinfo.cmake)
        conan_basic_setup()
    else()
        message(FATAL_ERROR "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
    endif()
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
add_library(OtterGraphic STATIC ${GRAPHIC_FILES} graphic/include)
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
    DESTINATION lib
)

if(WIN32)
    set(CPACK_GENERATOR "ZIP")
else()
    set(CPACK_GENERATOR "TGZ")
endif()

# Bundle output with cpack
include(CPack)