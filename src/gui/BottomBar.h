#pragma once
#include "../FileUtils.h"
#include "../Sprite.h"
#include "../Button.h"
#include <iostream>

class BottomBar {

    public:
        BottomBar(int xPos, int yPos);
        void clean();
        void handleEvent(SDL_Event* e, int mouseX, int mouseY);
        void draw(SDL_Renderer* renderer);

    private:
        int x;
        int y;
        Sprite* bottombar;
        Button* btnAttack;
        Button* btnDefense;
};
