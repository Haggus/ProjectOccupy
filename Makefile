OBJS = \
	src/Resistance.cpp \
	src/Game.cpp \
	src/MenuState.cpp \
	src/PlayState.cpp \
	src/FileUtils.cpp \
	src/Sprite.cpp \
	src/Tile.cpp \
	src/Map.cpp \
	src/Selector.cpp \
	src/Text.cpp \
	src/Agent.cpp \
	src/Player.cpp \
	src/HUD.cpp \
	src/Mission.cpp \
	src/Tooltip.cpp \
	src/Button.cpp

OBJ_NAME = resistance

all: $(OBJS)
	g++ $(OBJS) -std=c++11 -w -g -Wall -lSDL2 -lSDL2_image -lSDL2_ttf -o $(OBJ_NAME)
