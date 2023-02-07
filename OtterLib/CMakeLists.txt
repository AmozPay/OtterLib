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

if (WIN32)
    set(CMAKE_SHELL "powershell.exe")
else()
    set(CMAKE_SHELL bash -c)
endif()

# Find Conan
find_program(CONAN conan)
if (NOT CONAN)
    message(FATAL_ERROR "[Conan] Conan not found!")
endif()


# Check if conan is installed
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/conanbuildinfo.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
else()
    # If not, install conan dependencies
    message(STATUS "[Conan] Conan dependencies not installed, installing dependencies...")
    execute_process(
            COMMAND ${CMAKE_SHELL} "conan install ${CMAKE_CURRENT_SOURCE_DIR} --build=missing -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=true"
            OUTPUT_VARIABLE result
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/conanbuildinfo.cmake)
        message(STATUS "[Conan] Conan dependencies installed!")
        include(${CMAKE_CURRENT_SOURCE_DIR}/conanbuildinfo.cmake)
        conan_basic_setup()
    else()
        message(FATAL_ERROR "[Conan] Conan install error: ${result}")
    endif()
endif()



# CREATE STATIC LIBRARIES
# OtterCore
file(GLOB CORE_FILES core/src/*.cpp)
list(REMOVE_ITEM CORE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/core/src/main.cpp)
add_library(OtterCore STATIC ${CORE_FILES} ${CMAKE_CURRENT_SOURCE_DIR}/core/src/main.cpp)
target_compile_features(OtterCore PUBLIC cxx_std_20)
target_include_directories(OtterCore PUBLIC core/include)



# OtterNetwork
file(GLOB NETWORK_FILES network/src/*.cpp)
add_library(OtterNetwork STATIC ${NETWORK_FILES})
target_compile_features(OtterNetwork PUBLIC cxx_std_20)
target_include_directories(OtterNetwork PUBLIC network/include)

# OtterScript
file(GLOB SCRIPT_FILES script/src/*.cpp)
add_library(OtterScript STATIC ${SCRIPT_FILES})
target_compile_features(OtterScript PUBLIC cxx_std_20)
target_include_directories(OtterScript PUBLIC script/include)


# OtterGraphic
file(GLOB GRAPHIC_FILES graphic/src/*.cpp)
add_library(OtterGraphic STATIC ${GRAPHIC_FILES} graphic/include)
target_compile_features(OtterGraphic PUBLIC cxx_std_20)
target_include_directories(OtterGraphic PUBLIC graphic/include)

include(CTest)
option(BUILD_TESTING ON)
if(BUILD_TESTING) # ... CMake code to create tests ...
    # Add google tests
    include(FetchContent)
    FetchContent_Declare(
        googletest

        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )

    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    enable_testing()

    # OtterGraphic tests
    file(GLOB GRAPHIC_TESTS graphic/tests/*.cpp)
    add_executable(OtterGraphicTests ${GRAPHIC_FILES} ${GRAPHIC_TESTS})
    target_compile_features(OtterGraphicTests PUBLIC cxx_std_20)
    target_include_directories(OtterGraphicTests PUBLIC graphic/include)
    target_link_libraries(OtterGraphicTests gtest_main ${CONAN_LIBS})
    add_test(NAME OtterGraphicTests COMMAND OtterGraphicTests)

    # OtterNetwork tests
    file(GLOB NETWORK_TESTS network/tests/*.cpp)
    add_executable(OtterNetworkTests ${NETWORK_FILES} ${NETWORK_TESTS})
    target_compile_features(OtterNetworkTests PUBLIC cxx_std_20)
    target_include_directories(OtterNetworkTests PUBLIC network/include)
    target_link_libraries(OtterNetworkTests gtest_main)
    add_test(NAME OtterNetworkTests COMMAND OtterNetworkTests)

    # OtterCore tests
    file(GLOB CORE_TESTS core/tests/*.cpp)
    add_executable(OtterCoreTests ${CORE_FILES} ${CORE_TESTS})
    target_compile_features(OtterCoreTests PUBLIC cxx_std_20)
    target_include_directories(OtterCoreTests PUBLIC core/include)
    target_link_libraries(OtterCoreTests gtest_main)
    add_test(NAME OtterCoreTests COMMAND OtterCoreTests)

    # OtterScript tests
    file(GLOB SCRIPT_TESTS script/tests/*.cpp)
    add_executable(OtterScriptTests ${SCRIPT_FILES} ${SCRIPT_TESTS})
    target_compile_features(OtterScriptTests PUBLIC cxx_std_20)
    target_include_directories(OtterScriptTests PUBLIC script/include)
    target_link_libraries(OtterScriptTests gtest_main lua)
    add_test(NAME OtterScriptTests COMMAND OtterScriptTests)
    file(COPY script/tests/test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


    # Compile tests only
    add_custom_target(OtterLibTests)
    add_dependencies(OtterLibTests OtterCoreTests OtterNetworkTests OtterGraphicTests)
endif()



# Does not compile tests
add_custom_target(OtterLib)
add_dependencies(OtterLib OtterCore OtterNetwork OtterGraphic OtterScript)


# Find headers
file(GLOB CORE_HEADERS core/include/*.hpp)
file(GLOB NETWORK_HEADERS network/include/*.hpp)
file(GLOB GRAPHIC_HEADERS graphic/include/*.hpp)
file(GLOB SCRIPT_HEADERS script/include/*.hpp)

# Add headers to installed elements
install(FILES
    ${GRAPHIC_HEADERS}
    ${NETWORK_HEADERS}
    ${CORE_HEADERS}
    ${SCRIPT_HEADERS}
    DESTINATION "include"
)

# Add static libraries to installed elements
# Export them for use in other CMakes
install(TARGETS
    OtterGraphic
    OtterNetwork
    OtterScript
    OtterCore
    EXPORT OtterLib
    DESTINATION lib
)

if(WIN32)
    set(CPACK_GENERATOR "ZIP")
    # target_link_options(OtterCore PUBLIC "-NODEFAULTLIB:library")
else()
    set(CPACK_GENERATOR "TGZ")
endif()

# Bundle output with cpack
include(CPack)


