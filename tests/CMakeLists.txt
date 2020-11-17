cmake_minimum_required(VERSION 3.10)

enable_testing()

set(TEST_SOURCES
  test.cpp
  components.cpp
  
  game-object.cpp

  scene.cpp
  scene-list.cpp
)

include_directories("../src/Engine")

add_executable(tp1_ui_test ${TEST_SOURCES})
target_link_libraries(tp1_ui_test PRIVATE Catch2::Catch2 tp_ui_lib)
add_test(tp1_ui_test ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tp1_ui_test)
set_target_properties(tp1_ui_test PROPERTIES CXX_STANDARD 17)

# catch_discover_tests(tp1_ui_test)