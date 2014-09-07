#pragma once
#include "../FileUtils.h"
#include "../Sprite.h"
#include "../Button.h"
#include "../Selector.h"
#include "../Player.h"
#include <iostream>
#include <vector>

class BottomBar {

    public:
        BottomBar(std::vector<Player>* playaz, Selector* selector, int xPos, int yPos);
        void clean();
        void handleEvent(SDL_Event* e, int mouseX, int mouseY, int currentPlayer);
        bool collision(int xPos, int yPos);
        void draw(SDL_Renderer* renderer);

    private:
        int x;
        int y;
        int width;
        int height;
        std::vector<Player>* players;
        Selector* select;
        Sprite* bottombar;
        Button* btnAttack;
        Button* btnDefense;
};
