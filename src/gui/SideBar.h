#pragma once
#include "../FileUtils.h"
#include "../Sprite.h"
#include "../Text.h"
#include <string>

class SideBar {

    public:
        SideBar(int xPos, int yPos);
        void clean();
        void update(int numbers[]);
        void draw(SDL_Renderer* renderer);
        int getWidth();
        int getHeight();

    private:
        int x;
        int y;
        int width;
        int height;
        Sprite* sidebar;
        Sprite* mishAttack;
        Text* mishAttackText;
        Sprite* mishDefense;
        Text* mishDefenseText;
        Sprite* mishRecruit;
        Text* mishRecruitText;
        Sprite* mishHelp;
        Text* mishHelpText;
};
