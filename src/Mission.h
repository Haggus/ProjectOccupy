#pragma once
#include "Text.h"
#include "Button.h"
#include <iostream>

class Mission {
	
	public:
		Mission();
		int getDifficulty();
		void clean();
		std::string getName();
		std::string getDescription();
		Button* getButton();
		void setX(int x);
		void setY(int y);
		bool collision(int x, int y);
		void draw(SDL_Renderer* renderer);

	private:
		int difficulty;
		std::string name;
		std::string description;
		Text* label;
		Button* button;
};