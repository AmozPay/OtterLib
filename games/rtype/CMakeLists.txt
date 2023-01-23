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

# Check if conan is installed
find_program(CONAN "conan")
if(NOT CONAN)
    message(FATAL_ERROR "Conan is not installed")
endif()

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

file(GLOB CLIENT_FILES src/*.cpp)
file(GLOB SERVER_FILES src/*.cpp)

# build client
add_executable(r-type_client ${CLIENT_FILES})
target_compile_definitions(r-type_client PUBLIC TARGET_CLIENT)
target_link_libraries(r-type_client
    OtterCore
    OtterNetwork
    ${CONAN_LIBS}
)

# build server
add_executable(r-type_server ${SERVER_FILES})
target_compile_definitions(r-type_server PUBLIC TARGET_SERVER)
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