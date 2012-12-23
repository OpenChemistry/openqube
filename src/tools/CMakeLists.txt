include_directories(..)

add_executable(qube qube.cpp)
target_link_libraries(qube OpenQube ${QT_QTCORE_LIBRARY})

install(TARGETS qube DESTINATION "${BIN_INSTALL_DIR}")
