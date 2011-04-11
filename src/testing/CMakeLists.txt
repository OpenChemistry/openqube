include_directories(..)

set(MyTests
  testatom
  testmolecule
  )

create_test_sourcelist(Tests OpenQubeTests.cxx ${MyTests})

add_executable(OpenQubeTests ${Tests})
target_link_libraries(OpenQubeTests OpenQube)

foreach(test ${MyTests})
  message("Adding test ${test}...")
  add_test(NAME openqube-${test}
    COMMAND OpenQubeTests ${test})
endforeach()

