
find_package(Qt 4.6.0 REQUIRED)

message(STATUS "QT: ${QT_USE_FILE}")
include(${QT_USE_FILE})
message(STATUS "QT: ${QT_LIBRARIES}")
include_directories(..)


add_executable(makecube makecube.cpp)
target_link_libraries(makecube OpenQube ${QT_LIBRARIES})


