cmake_minimum_required(VERSION 3.17)

# define project version with CI build
if(DEFINED ENV{PROJECT_VERSION})
    project(
        RType
        VERSION $ENV{PROJECT_VERSION}
        DESCRIPTION "Epitech Project"
    )
else()
    project(
        RType
        VERSION 0.1.0
        DESCRIPTION "Epitech Project"
    )
endif()

option(BUILD_RELEASE OFF)
if(BUILD_RELEASE) # when overriden by cli
    message(WARNING "Building project for release")
    set(CONFIG_VALUE "--config Release")
    add_definitions("-DBUILD_TESTING=OFF")
endif()

# Build OtterLib
set(OTTERLIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../OtterLib)

add_definitions("-D_GLIBCXX_USE_CXX11_ABI=0")


file(COPY ${OTTERLIB_DIR}/scripting/OtterLib.lua DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/src/scripts)

add_subdirectory(${OTTERLIB_DIR} ${OTTERLIB_DIR}/build)

# Check if conan dependencies are installed
if(EXISTS ${OTTERLIB_DIR}/conanbuildinfo.cmake)
    include(${OTTERLIB_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(FATAL_ERROR "Conan dependencies not installed, please run 'conan install' in OtterLib directory")
endif()

file(
    GLOB CLIENT_FILES
    src/*.cpp
    src/Game/*.cpp
    src/System/*.cpp
    src/System/Collisions/*.cpp
)
file(
    GLOB SERVER_FILES
    src/*.cpp
    src/Game/*.cpp
    src/System/*.cpp
    src/System/Collisions/*.cpp
)

# build client
add_executable(r-type_client ${CLIENT_FILES})
target_compile_definitions(r-type_client PUBLIC TARGET_CLIENT)
target_include_directories(
    r-type_client
    PUBLIC
    include/
    include/Utils
    include/Component
    include/Game
    include/System
    include/System/Collisions
)

target_link_libraries(r-type_client
    OtterGraphic
    OtterCore
    OtterNetwork
    OtterScripting
    ${CONAN_LIBS}
)

file(COPY src/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY src/scripts DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY src/entities DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# build server
add_executable(r-type_server ${SERVER_FILES})
target_compile_definitions(r-type_server PUBLIC TARGET_SERVER)
target_include_directories(
    r-type_server
    PUBLIC
    include/
    include/Utils
    include/Component
    include/Game
    include/System
    include/System/Collisions
)
target_link_libraries(r-type_server
    OtterCore
    OtterNetwork
    OtterGraphic
    OtterScripting
    ${CONAN_LIBS}
)

# Does not compile tests
add_custom_target(r-type)
add_dependencies(r-type r-type_server r-type_client)


install(
    TARGETS r-type_server r-type_client
    RUNTIME
    DESTINATION bin
    COMPONENT release
)

if(WIN32)
    set(CPACK_GENERATOR "ZIP;NSIS")
else()
    set(CPACK_GENERATOR "TGZ")
endif()

# only install this project, do not include OtterLib in the package
set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)
set(CPACK_COMPONENTS_ALL release)
include(CPack)
