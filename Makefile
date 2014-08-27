CC=g++
CFLAGS=-std=c++11 -w -g -Wall -lSDL2 -lSDL2_image -lSDL2_ttf
LDFLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf
SOURCES = \
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
    src/Player.cpp \
    src/HUD.cpp \
    src/Button.cpp \
    src/gui/TopBar.cpp \
    src/gui/SideBar.cpp \
    src/gui/BottomBar.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=occupy

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	find . -name \*.o -type f -delete
