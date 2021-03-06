#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "FileUtils.h"
#include <vector>

class GameState;

class Game {

	public:
		Game();
		void init(const char* title, int width, int height);
		void changeState(GameState* state);
		void pushState(GameState* state);
		void popState();
		void handleEvents();
		void update();
		void render();
		void clean();
		int getWidth();
		int getHeight();
		bool running() { return isRunning; }
		void quit() { isRunning = false; }
		SDL_Window* getScreen() { return window; }
		SDL_Renderer* getRenderer() {return renderer; }
		SDL_Event* getMainEvent() { return mainEvent; }

	private:
		std::vector<GameState*> states;
		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Event* mainEvent;
		//SDL_Joystick* stick;
		int w;
		int h;
		bool isRunning;
		bool isFullscreen;
		SDL_Surface* icon;
};
