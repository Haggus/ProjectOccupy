#include "Game.h"
#include "GameState.h" //<< THIS HAS TO BE HERE!
#include <iostream>

Game::Game() {
}

void Game::init(const char* title, int width, int height) {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = NULL;
	window = SDL_CreateWindow(title, 0, 0, width, height, SDL_WINDOW_SHOWN);
	if(window == NULL) {
		std::cout << "Window couldnt be created!" << std::endl;
		isRunning = false;
	}

	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL) {
		std::cout << "Renderer couldnt be initialized!" << std::endl;
		isRunning = false;
	}

	if(TTF_Init() == -1) {
		std::cout << "TTF couldnt be initialized!" << std::endl;
	}

	std::string iconLocation = FileUtils::getImagePath() + "icon.png";
	icon = IMG_Load(iconLocation.c_str());
	if(icon == NULL) {
		std::cout << "Icon couldnt be loaded!" << std::endl;
	}
	SDL_SetWindowIcon(window, icon);

	mainEvent = new SDL_Event();
	isRunning = true;
	SDL_ShowCursor(0);
	std::cout << "Initialization DONE!" << std::endl;
}

void Game::changeState(GameState* state) {
	//clean current state
	if(!states.empty()) {
		states.back()->clean();
		states.pop_back();
	}
	//store and init a new state
	states.push_back(state);
	states.back()->init(this);
}

void Game::pushState(GameState* state) {
	//pause current state
	if(!states.empty()) {
		states.back()->pause();
	}
	//store and init a new state
	states.push_back(state);
	states.back()->init(this);
}

void Game::popState() {
	//clean current state
	if(!states.empty()) {
		states.back()->clean();
		states.pop_back();
	}
	//resume previous state
	if(!states.empty()) {
		states.back()->resume();
	}
}

void Game::handleEvents() {
	states.back()->handleEvents();
}

void Game::update() {
	states.back()->update();
}

void Game::render() {
	SDL_RenderClear(renderer);
	states.back()->render();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	while(!states.empty()) {
		states.back()->clean();
		states.pop_back();
	}
	//SDL_JoystickClose(stick);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_Quit();
	delete mainEvent;
}
