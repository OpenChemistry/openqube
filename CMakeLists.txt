cmake_minimum_required(VERSION 2.8)

project(OpenQube)

set(CMAKE_MODULE_PATH "${OpenQube_SOURCE_DIR}/cmake")

include(CTest)
enable_testing()

# Set up our installation directories, version etc.
set(OpenQube_VERSION_MAJOR   "0")
set(OpenQube_VERSION_MINOR   "1")
set(OpenQube_VERSION_PATCH   "0")
set(OpenQube_VERSION
  "${OpenQube_VERSION_MAJOR}.${OpenQube_VERSION_MINOR}.${OpenQube_VERSION_PATCH}")

set(INC_INSTALL_DIR          "include")
set(LIB_INSTALL_DIR          "lib")
set(BIN_INSTALL_DIR          "bin")

# Use an exports file for Libraries targets
set(OpenQube_EXPORTS_NAME OpenQubeExports)
set(OpenQube_EXPORTS_FILE "${OpenQube_BINARY_DIR}/${Libraries_EXPORTS_NAME}.cmake")
file(REMOVE "${Libraries_EXPORTS_FILE}")

add_subdirectory(src)
#add_subdirectory(tools)

configure_file("${OpenQube_SOURCE_DIR}/cmake/OpenQubeConfig.cmake.in"
  "${OpenQube_BINARY_DIR}/OpenQubeConfig.cmake" @ONLY)
install(FILES "${OpenQube_BINARY_DIR}/OpenQubeConfig.cmake"
  DESTINATION "${LIB_INSTALL_DIR}/openqube")

configure_file("${OpenQube_SOURCE_DIR}/cmake/OpenQubeConfigVersion.cmake.in"
  "${OpenQube_BINARY_DIR}/OpenQubeConfigVersion.cmake" @ONLY)
install(FILES "${OpenQube_BINARY_DIR}/OpenQubeConfigVersion.cmake"
  DESTINATION "${LIB_INSTALL_DIR}/openqube")
