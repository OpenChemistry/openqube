
find_package(Qt 4.6.0 REQUIRED)

message(STATUS "QT: ${QT_USE_FILE}")
include(${QT_USE_FILE})
message(STATUS "QT: ${QT_LIBRARIES}")
include_directories(..)


add_executable(qube qube.cpp)
target_link_libraries(qube OpenQube ${QT_LIBRARIES})


