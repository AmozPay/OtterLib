# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "/home/nicolas/bouli/rtype/OtterLib/OtterLib;/home/nicolas/bouli/rtype/OtterLib/OtterLib")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/usr/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "OtterLib built using CMake")
set(CPACK_GENERATOR "TGZ")
set(CPACK_INSTALL_CMAKE_PROJECTS "/home/nicolas/bouli/rtype/OtterLib/OtterLib;OtterLib;ALL;/")
set(CPACK_INSTALL_PREFIX "/usr/local")
set(CPACK_MODULE_PATH "/home/nicolas/.conan/data/raylib/4.0.0/_/_/package/04719ec759afa1097ab507fe72d2049710c7d154/;/home/nicolas/.conan/data/raylib/4.0.0/_/_/package/04719ec759afa1097ab507fe72d2049710c7d154/lib/cmake;/home/nicolas/.conan/data/asio/1.24.0/_/_/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/;/home/nicolas/.conan/data/libudev/system/_/_/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/;/home/nicolas/.conan/data/freetype/2.12.1/_/_/package/081e568bb8bac3eeda85a8634d642a47e3f5c966/;/home/nicolas/.conan/data/stb/cci.20220909/_/_/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/;/home/nicolas/.conan/data/openal/1.22.2/_/_/package/8afac580db1d21c8a00258fb1aa2bf59f9a16248/;/home/nicolas/.conan/data/glfw/3.3.6/_/_/package/512bb29988f40138a14eb398f896585a5af5ec83/;/home/nicolas/.conan/data/libbacktrace/cci.20210118/_/_/package/2a19826344ff00be1c04403f2f8e7008ed3a7cc6/;/home/nicolas/.conan/data/opengl/system/_/_/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/;/home/nicolas/.conan/data/xorg/system/_/_/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/;/home/nicolas/.conan/data/libpng/1.6.39/_/_/package/c50ec4bac288fa759d0037cc4023b4bbefd75ad4/;/home/nicolas/.conan/data/bzip2/1.0.8/_/_/package/3cfc45772763dad1237052f26c1fe8b2bae3f7d2/;/home/nicolas/.conan/data/libalsa/1.2.7.2/_/_/package/bff4e519ddeceb9c14aa49414e88f976ff8057c2/;/home/nicolas/.conan/data/zlib/1.2.13/_/_/package/2a19826344ff00be1c04403f2f8e7008ed3a7cc6/")
set(CPACK_NSIS_DISPLAY_NAME "OtterLib 0.1.0")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "OtterLib 0.1.0")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJCOPY_EXECUTABLE "/usr/bin/objcopy")
set(CPACK_OBJDUMP_EXECUTABLE "/usr/bin/objdump")
set(CPACK_OUTPUT_CONFIG_FILE "/home/nicolas/bouli/rtype/OtterLib/OtterLib/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/usr/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Otter Game Engine")
set(CPACK_PACKAGE_FILE_NAME "OtterLib-0.1.0-Linux")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "OtterLib 0.1.0")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "OtterLib 0.1.0")
set(CPACK_PACKAGE_NAME "OtterLib")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Humanity")
set(CPACK_PACKAGE_VERSION "0.1.0")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_READELF_EXECUTABLE "/usr/bin/readelf")
set(CPACK_RESOURCE_FILE_LICENSE "/usr/share/cmake/Templates/CPack.GenericLicense.txt")
set(CPACK_RESOURCE_FILE_README "/usr/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "/usr/share/cmake/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TBZ2;TGZ;TXZ;TZ")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/home/nicolas/bouli/rtype/OtterLib/OtterLib/CPackSourceConfig.cmake")
set(CPACK_SOURCE_RPM "OFF")
set(CPACK_SOURCE_TBZ2 "ON")
set(CPACK_SOURCE_TGZ "ON")
set(CPACK_SOURCE_TXZ "ON")
set(CPACK_SOURCE_TZ "ON")
set(CPACK_SOURCE_ZIP "OFF")
set(CPACK_SYSTEM_NAME "Linux")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Linux")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/home/nicolas/bouli/rtype/OtterLib/OtterLib/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()