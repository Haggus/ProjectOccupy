#pragma once
#include "../FileUtils.h"
#include "../Sprite.h"
#include "../Text.h"
#include "../Map.h"
#include <string>

class SideBar {

    public:
        SideBar(Map* mapper, int xPos, int yPos);
        void clean();
        void update();
        void draw(SDL_Renderer* renderer);
        int getWidth();
        int getHeight();

    private:
        int x;
        int y;
        int width;
        int height;
        Map* map;
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
