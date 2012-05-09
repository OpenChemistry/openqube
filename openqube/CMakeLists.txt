find_package(Qt4 4.6 REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(SYSTEM ${QT_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIR})

# Headers for our public API
set(openqube_HDRS
  atom.h
  basisset.h
  basissetloader.h
  cube.h
  gamessukout.h
  gamessus.h
  gaussianset.h
  molecule.h
  openqubeabi.h
  slaterset.h
)

# Source files for our data.
set(openqube_SRCS
  atom.cpp
  basisset.cpp
  basissetloader.cpp
  cube.cpp
  gamessukout.cpp
  gamessus.cpp
  gaussianfchk.cpp
  gaussianset.cpp
  molden.cpp
  molecule.cpp
  mopacaux.cpp
  slaterset.cpp
)

qt4_wrap_cpp(openqubeMocSrcs basisset.h gaussianset.h slaterset.h)

add_library(OpenQube ${openqube_SRCS} ${openqubeMocSrcs})

set_target_properties(OpenQube PROPERTIES
  VERSION ${OpenQube_VERSION}
  LINK_INTERFACE_LIBRARIES ""
  SOVERSION 0
  LABELS openqube)

target_link_libraries(OpenQube ${QT_QTCORE_LIBRARY})

# Install the library
install(TARGETS OpenQube
  EXPORT "OpenQubeTargets"
  DESTINATION "${INSTALL_LIBRARY_DIR}")
install(EXPORT OpenQubeTargets DESTINATION
  "${INSTALL_LIBRARY_DIR}/cmake/openqube")
# Install the headers for the public API
install(FILES ${openqube_HDRS} DESTINATION "${INSTALL_INCLUDE_DIR}/openqube")

add_subdirectory(testing)
