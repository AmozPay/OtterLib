cmake_minimum_required(VERSION 3.17)

# define project version with CI build
if(DEFINED ENV{PROJECT_VERSION})
    project(
        NetworkSimulator
        VERSION $ENV{PROJECT_VERSION}
        DESCRIPTION "Epitech Project"
    )
else()
    project(
        NetworkSimulator
        VERSION 0.1.0
        DESCRIPTION "Epitech Project"
    )
endif()

option(BUILD_RELEASE OFF)
if(BUILD_RELEASE) # when overriden by cli
    message(WARNING "Building project for release")
    set(CONFIG_VALUE "--config Release")
    set(BUILD_TESTING "-DBUILD_TESTING=OFF")
else()
    set(CONFIG_VALUE "")
    set(BUILD_TESTING "")
endif()

# Build OtterLib
set(OTTERLIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../OtterLib)
execute_process(
    COMMAND ${CMAKE_COMMAND} ${BUILD_TESTING} -S . -B build -G ${CMAKE_GENERATOR}
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${OTTERLIB_DIR}
)

if(result)
    message(FATAL_ERROR "CMake step for deps failed: ${result}")
endif()


execute_process(
    COMMAND ${CMAKE_COMMAND} --build . --target OtterLib ${CONFIG_VALUE}
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${OTTERLIB_DIR}/build
)

add_subdirectory(${OTTERLIB_DIR} ${OTTERLIB_DIR}/build)

# Check if conan dependencies are installed
if(EXISTS ${OTTERLIB_DIR}/conanbuildinfo.cmake)
    include(${OTTERLIB_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(FATAL_ERROR "Conan dependencies not installed, please run 'conan install' in OtterLib directory")
endif()

add_definitions("-D_GLIBCXX_USE_CXX11_ABI=0")

file(GLOB NETWORK_FILE src/*.cpp src/System/*.cpp)

# build SIMULATOR
add_executable((networkSimulator ${NETWORK_FILE})
target_compile_definitions(networkSimulator PUBLIC TARGET_CLIENT)
target_include_directories(networkSimulator PUBLIC include/ include/Component include/System)
target_link_libraries(networkSimulator
    OtterCore
    OtterNetwork
    OtterGraphic
    OtterScripting
    ${CONAN_LIBS}
)

file(COPY src/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY src/scripts DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY src/entities DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


# Does not compile tests
add_custom_target(simulator)
add_dependencies(simulator networkSimulator)


install(
    TARGETS networkSimulator
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
