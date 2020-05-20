project(occupy)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

add_executable(${PROJECT_NAME}
  src/Resistance.cpp
  src/Game.cpp
  src/MenuState.cpp
  src/PlayState.cpp
  src/FileUtils.cpp
  src/Sprite.cpp
  src/Tile.cpp
  src/Map.cpp
  src/Selector.cpp
  src/Text.cpp
  src/Player.cpp
  src/HUD.cpp
  src/Button.cpp
  src/gui/TopBar.cpp
  src/gui/SideBar.cpp
  src/gui/BottomBar.cpp
)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES})
