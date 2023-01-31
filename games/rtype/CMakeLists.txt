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

# Build OtterLib
set(OTTERLIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../OtterLib)
file(MAKE_DIRECTORY ${OTTERLIB_DIR}/build)
execute_process(
    COMMAND ${CMAKE_COMMAND} -G ${CMAKE_GENERATOR} ..
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${OTTERLIB_DIR}/build
)

if(result)
    message(FATAL_ERROR "CMake step for deps failed: ${result}")
endif()

execute_process(
    COMMAND ${CMAKE_COMMAND} --build .
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

file(GLOB CLIENT_FILES src/*.cpp src/system/*.cpp)
file(GLOB SERVER_FILES src/*.cpp)

# build client
add_executable(r-type_client ${CLIENT_FILES})
target_compile_definitions(r-type_client PUBLIC TARGET_CLIENT)
target_include_directories(r-type_client PUBLIC include/ include/system/)
target_link_libraries(r-type_client
    OtterCore
    OtterNetwork
    OtterGraphic
    ${CONAN_LIBS}
)

# build server
add_executable(r-type_server ${SERVER_FILES})
target_compile_definitions(r-type_server PUBLIC TARGET_SERVER)
target_include_directories(r-type_server PUBLIC include/)
target_link_libraries(r-type_server
    OtterCore
    OtterNetwork
    OtterGraphic
    ${CONAN_LIBS}
)

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
