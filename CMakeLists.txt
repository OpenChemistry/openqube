cmake_minimum_required(VERSION 2.8)

project(OpenQube)

message(FATAL_ERROR "error: WIP - testing CDash@home builds from gerrit")

set(CMAKE_MODULE_PATH "${OpenQube_SOURCE_DIR}/cmake")

include(BuildType)
include(BuildLocation)
include(CompilerFlags)
include(InstallLocation)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

option(ENABLE_TESTING "Enable testing and building the tests." OFF)

if(ENABLE_TESTING)
  include(CTest)
  enable_testing()
endif()

# Set up our installation directories, version etc.
set(OpenQube_VERSION_MAJOR   "0")
set(OpenQube_VERSION_MINOR   "1")
set(OpenQube_VERSION_PATCH   "0")
set(OpenQube_VERSION
  "${OpenQube_VERSION_MAJOR}.${OpenQube_VERSION_MINOR}.${OpenQube_VERSION_PATCH}")

option(BUILD_SHARED_LIBS "Build with shared libraries" ON)

# Use an exports file for Libraries targets
set(OpenQube_EXPORTS_NAME OpenQubeExports)
set(OpenQube_EXPORTS_FILE "${OpenQube_BINARY_DIR}/${Libraries_EXPORTS_NAME}.cmake")
file(REMOVE "${Libraries_EXPORTS_FILE}")

add_subdirectory(openqube)
#add_subdirectory(tools)

option(BUILD_DOCUMENTATION "Build project documentation" OFF)

if(BUILD_DOCUMENTATION)
  add_subdirectory(docs)
endif()

configure_file("${OpenQube_SOURCE_DIR}/cmake/OpenQubeConfig.cmake.in"
  "${OpenQube_BINARY_DIR}/OpenQubeConfig.cmake" @ONLY)
install(FILES "${OpenQube_BINARY_DIR}/OpenQubeConfig.cmake"
  DESTINATION "${INSTALL_LIBRARY_DIR}/cmake/openqube")

configure_file("${OpenQube_SOURCE_DIR}/cmake/OpenQubeConfigVersion.cmake.in"
  "${OpenQube_BINARY_DIR}/OpenQubeConfigVersion.cmake" @ONLY)
install(FILES "${OpenQube_BINARY_DIR}/OpenQubeConfigVersion.cmake"
  DESTINATION "${INSTALL_LIBRARY_DIR}/cmake/openqube")
