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

option(BUILD_TESTING "Build OtterLib tests" OFF)
if(BUILD_TESTING) # when overriden by cli
    message("Building OtterLib without tests")
    set(BUILD_TESTING "-DBUILD_TESTING=ON")
else()
    set(BUILD_TESTING "-DBUILD_TESTING=OFF")
    message("Building OtterLib with tests")
endif()

option(BUILD_RELEASE "Build OtterLib tests" OFF)
if(BUILD_RELEASE) # when overriden by cli
    message("Building OtterLib for release")
    set(CONFIG_VALUE "--config Release")
else()
    message("Building OtterLib for debug")
    set(CONFIG_VALUE "--config Debug")
endif()

# Build OtterLib
set(OTTERLIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../OtterLib)


file(COPY ${OTTERLIB_DIR}/scripting/OtterLib.lua DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/src/scripts)

include(ExternalProject)

ExternalProject_Add(OtterLib

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
  set(suffix ".lib")
  set(CMAKE_SHELL "powershell.exe")
  set(LINUX_CONAN_FLAGS "")
  add_definitions("-D_WIN32_WINNT=0x0601")
  add_link_options("-NODEFAULTLIB:library" "-SUBSYSTEM:CONSOLE")
else()
  set(prefix "lib")
  set(suffix ".a")
  set(CMAKE_SHELL bash -c)
  set(LINUX_CONAN_FLAGS "-c tools.system.package_manager:sudo=true")
  add_definitions("-D_GLIBCXX_USE_CXX11_ABI=0")
endif()

# Check if conan is installed
if(EXISTS ${OTTERLIB_DIR}/conanbuildinfo.cmake)
    include(${OTTERLIB_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    # If not, install conan dependencies
    message(STATUS "[Conan] Conan dependencies not installed, installing dependencies...")
    execute_process(
        COMMAND ${CMAKE_SHELL} "conan install ${CMAKE_CURRENT_SOURCE_DIR} --build=missing -c tools.system.package_manager:mode=install ${LINUX_CONAN_FLAGS}"
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
    src/Init/GameClient/*.cpp
    src/Init/GameServer/*.cpp
    src/Game/*.cpp
    src/System/*.cpp
    src/System/GameClient/*.cpp
    src/System/GameServer/*.cpp
    src/System/Collisions/*.cpp
)
file(
    GLOB SERVER_FILES
    src/*.cpp
    src/Init/GameClient/*.cpp
    src/Init/GameServer/*.cpp
    src/Game/*.cpp
    src/System/*.cpp
    src/System/GameClient/*.cpp
    src/System/GameServer/*.cpp
    src/System/Collisions/*.cpp
)

# build client
add_executable(r-type_client ${CLIENT_FILES})
target_compile_features(r-type_client PUBLIC cxx_std_20)
target_compile_definitions(r-type_client PUBLIC TARGET_CLIENT)
target_include_directories(
    r-type_client
    PUBLIC
    include/
    include/Utils
    include/Component
    include/Init/GameClient
    include/Init/GameServer
    include/Game
    include/System
    include/System/GameClient
    include/System/GameServer
    include/System/Collisions
    ${OTTERLIB_DIR}/build/include
)

target_link_libraries(r-type_client
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
add_executable(r-type_server ${SERVER_FILES})
target_compile_definitions(r-type_server PUBLIC TARGET_SERVER)
target_compile_features(r-type_server PUBLIC cxx_std_20)
target_include_directories(
    r-type_server
    PUBLIC
    include/
    include/Utils
    include/Component
    include/Init/GameClient
    include/Init/GameServer
    include/Game
    include/System
    include/System/GameClient
    include/System/GameServer
    include/System/Collisions
    ${OTTERLIB_DIR}/build/include
)
target_link_libraries(r-type_server
    ${OTTERLIB_DIR}/build/lib/${prefix}OtterCore${suffix}
    ${OTTERLIB_DIR}/build/lib/${prefix}OtterNetwork${suffix}
    ${OTTERLIB_DIR}/build/lib/${prefix}OtterGraphic${suffix}
    ${OTTERLIB_DIR}/build/lib/${prefix}OtterScripting${suffix}
    ${CONAN_LIBS}
)

# Does not compile tests
add_custom_target(r-type)
add_dependencies(r-type r-type_server r-type_client OtterLib)


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
