#pragma once
#include "SDL2/SDL.h"
#include "FileUtils.h"
#include "Sprite.h"
#include "Text.h"
#include <vector>
#include <string>

class Tile {

	public:
		Tile(int x, int y, int w, int h);
		void clean();
		void update(int currentP);
		void draw(SDL_Renderer* renderer);
		void addMembers(int amount, int currentPlayer, int type);
		int getMembers(int currentPlayer, int type);
		int getMembersTotal(int playerNumber);
		int getWidth();
		int getHeight();
		int getX();
		int getY();

	private:
		const int missionTypes = 4;
		Sprite* image;
		int x, y;
		int w, h;
		int memberCount[2][4];
		int currentPlayer;
		Text* title;
		Sprite* mishAttack;
		Text* mishAttackText;
		Sprite* mishDefense;
		Text* mishDefenseText;
		Sprite* mishRecruit;
		Text* mishRecruitText;
		Sprite* mishHelp;
		Text* mishHelpText;
};
