cmake_minimum_required(VERSION 3.17)
project(
    RType
    VERSION 0.0.1
    DESCRIPTION
    "Epitech Project"
)



# Build OtterLib
set(OTTERLIB_DIR ${CMAKE_SOURCE_DIR}/../../OtterLib)
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

include_directories(${OTTERLIB_DIR}/core/include)
include_directories(${OTTERLIB_DIR}/graphic/include)
include_directories(${OTTERLIB_DIR}/network/include)

file(GLOB CLIENT_FILES src/*.cpp)
file(GLOB SERVER_FILES src/*.cpp)

# build client
add_executable(r-type_client ${CLIENT_FILES})
target_compile_definitions(r-type_client PUBLIC TARGET_CLIENT)
target_link_libraries(r-type_client OtterCore)
target_link_libraries(r-type_client OtterNetwork)

# build server
add_executable(r-type_server ${SERVER_FILES})
target_compile_definitions(r-type_server PUBLIC TARGET_SERVER)
target_link_libraries(r-type_server OtterCore)
target_link_libraries(r-type_server OtterNetwork)
target_link_libraries(r-type_server OtterGraphic)
