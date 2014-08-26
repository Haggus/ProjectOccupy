#pragma once
#include "SDL2/SDL.h"
#include "FileUtils.h"
#include "Sprite.h"
#include "Mission.h"
#include "Button.h"
#include <vector>

class Tile {

	public:
		Tile(int x, int y, int w, int h);
		void clean();
		void update();
		void draw(SDL_Renderer* renderer);
		void addMembers(int amount, int type);
		void addMission();
		Mission* getMission(int i);
		int getMissionCount();
		int getMembers(int type);
		int getMembersTotal();
		int getWidth();
		int getHeight();
		int getX();
		int getY();
		Button* getButton();

	private:
		std::vector<Mission*> missions;
		Sprite* image;
		Button* button;
		int x, y;
		int w, h;
		int memberCount[2];
		int totalMembers;
};
