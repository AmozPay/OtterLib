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

option(BUILD_RELEASE "Build project for release" OFF)
if(BUILD_RELEASE) # when overriden by cli
    message("Building project for release")
    set(CONFIG_VALUE "--config Release")
    set(BUILD_TESTING "-DBUILD_TESTING=OFF")
else()
    message("Building project for debug, with tests")
    set(CONFIG_VALUE "--config Debug")
    set(BUILD_TESTING "-DBUILD_TESTING=ON")
endif()

# Build OtterLib
set(OTTERLIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../OtterLib)

add_definitions("-D_GLIBCXX_USE_CXX11_ABI=0")


file(COPY ${OTTERLIB_DIR}/scripting/OtterLib.lua DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/src/scripts)

include(ExternalProject)

ExternalProject_Add(OtterLib_simulator

    SOURCE_DIR ${OTTERLIB_DIR}
    BINARY_DIR ${OTTERLIB_DIR}/build

    # BUILD_COMMAND ${CMAKE_COMMAND} --build <BINARY_DIR> --target OtterLib
    CMAKE_ARGS ${BUILD_TESTING}
    BUILD_COMMAND ${CMAKE_COMMAND} --build <BINARY_DIR> --target OtterLib ${CONFIG_VALUE}
    INSTALL_DIR ${OTTERLIB_DIR}/build
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)

if(WIN32)
    set(prefix "")
    set(suffix ".dll")
    set(CMAKE_SHELL "powershell.exe")
else()
    set(prefix "lib")
    set(suffix ".so")
    set(CMAKE_SHELL bash -c)
endif()

# Check if conan is installed
if(EXISTS ${OTTERLIB_DIR}/conanbuildinfo.cmake)
    include(${OTTERLIB_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    # If not, install conan dependencies
    message(STATUS "[Conan] Conan dependencies not installed, installing dependencies...")
    execute_process(
        COMMAND ${CMAKE_SHELL} "conan install ${OTTERLIB_DIR} --build=missing -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=true"
        OUTPUT_VARIABLE result
        WORKING_DIRECTORY ${OTTERLIB_DIR}
    )

    if(EXISTS ${OTTERLIB_DIR}/conanbuildinfo.cmake)
        message(STATUS "[Conan] Conan dependencies installed!")
        include(${OTTERLIB_DIR}/conanbuildinfo.cmake)
        conan_basic_setup()
    else()
        message(FATAL_ERROR "[Conan] Conan install error: ${result}")
    endif()
endif()


file(
    GLOB CLIENT_FILES
    src/*.cpp
    )
    file(
        GLOB SERVER_FILES
        src/*.cpp
        )

        # build client
        add_executable(simulator_client ${CLIENT_FILES})
        target_compile_definitions(simulator_client PUBLIC TARGET_CLIENT)
        target_compile_features(simulator_client PUBLIC cxx_std_20)
        target_include_directories(
            simulator_client
            PUBLIC
            include/
            ${OTTERLIB_DIR}/build/include
)

target_link_libraries(simulator_client
    ${OTTERLIB_DIR}/build/lib/${prefix}OtterCore${suffix}
    ${OTTERLIB_DIR}/build/lib/${prefix}OtterNetwork${suffix}
    ${OTTERLIB_DIR}/build/lib/${prefix}OtterGraphic${suffix}
    ${OTTERLIB_DIR}/build/lib/${prefix}OtterScripting${suffix}
    ${CONAN_LIBS}
)

file(COPY src/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY src/scripts DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY src/entities DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# build server
add_executable(simulator_server ${SERVER_FILES})
target_compile_definitions(simulator_server PUBLIC TARGET_SERVER)
target_compile_features(simulator_server PUBLIC cxx_std_20)
target_include_directories(
    simulator_server
    PUBLIC
    include/
    ${OTTERLIB_DIR}/build/include
)
target_link_libraries(simulator_server
    ${OTTERLIB_DIR}/build/lib/${prefix}OtterCore${suffix}
    ${OTTERLIB_DIR}/build/lib/${prefix}OtterNetwork${suffix}
    ${OTTERLIB_DIR}/build/lib/${prefix}OtterGraphic${suffix}
    ${OTTERLIB_DIR}/build/lib/${prefix}OtterScripting${suffix}
    ${CONAN_LIBS}
)

# Does not compile tests
add_custom_target(simulator)
add_dependencies(simulator simulator_server simulator_client OtterLib)


install(
    TARGETS simulator_server simulator_client
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
