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

# set(OTTERLIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../OtterLib)
# execute_process(
#     COMMAND ${CMAKE_COMMAND} ${BUILD_TESTING} -S . -B build -G ${CMAKE_GENERATOR}
#     RESULT_VARIABLE result
#     WORKING_DIRECTORY ${OTTERLIB_DIR}
# )

# if(result)
#     message(FATAL_ERROR "CMake step for deps failed: ${result}")
# endif()


# execute_process(
#     COMMAND ${CMAKE_COMMAND} --build . --target OtterLib ${CONFIG_VALUE}
#     RESULT_VARIABLE result
#     WORKING_DIRECTORY ${OTTERLIB_DIR}/build
# )

# add_subdirectory(${OTTERLIB_DIR} ${OTTERLIB_DIR}/build)

# Call CMakes List.txt in the subdirectories
add_subdirectory(rtype)
add_subdirectory(networkSimulator)
