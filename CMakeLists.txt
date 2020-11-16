cmake_minimum_required (VERSION 3.11)

project(tp1_ui
  LANGUAGES CXX
  VERSION 0.1.0
)

# --- Fetch      --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.2)

FetchContent_MakeAvailable(Catch2)
# ------------------------------------------------------------------------------

set(ENGINE_SOURCES
  src/Engine/Camera.cpp
  src/Engine/Component.cpp
  src/Engine/Game.cpp
  src/Engine/GameObject.cpp
  src/Engine/Light.cpp
  src/Engine/Mesh.cpp
  src/Engine/Scene.cpp
  src/Engine/Transform.cpp
  
  src/Engine/Node.hpp
  src/Engine/List.hpp
  src/Engine/ComponentList.cpp
  src/Engine/GameObjectList.cpp
  src/Engine/SceneList.cpp
)

set(LIBRARY_NAME tp_ui_lib)
add_library(${LIBRARY_NAME} OBJECT ${ENGINE_SOURCES})
set_target_properties(${LIBRARY_NAME} PROPERTIES CXX_STANDARD 17)

include_directories("${CMAKE_SOURCE_DIR}/src/Engine" "${CMAKE_SOURCE_DIR}/deps")
target_include_directories(${LIBRARY_NAME} PUBLIC src/Engine deps)


add_executable(tp1_ui
  src/main.cpp
)
target_include_directories(tp1_ui PRIVATE src deps)

target_link_libraries(tp1_ui
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
  PUBLIC ${LIBRARY_NAME}
)

# C++17 is used. We requires fold expressions at least.
set_target_properties(tp1_ui PROPERTIES CXX_STANDARD 17)

# install(TARGETS tp1_ui RUNTIME DESTINATION "bin")

include(CTest)
if (BUILD_TESTING)
  add_subdirectory(tests)
endif ()