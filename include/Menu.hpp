#ifndef MENU_HPP_
    #define MENU_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unistd.h>
#include <stdbool.h>

class Menu {
    private:
        sf::RenderWindow _window;
        sf::Event event;
        sf::Texture MustachTexture;
        sf::Sprite MustachSprite;
        float mustachposX = 350;
        float mustachposY = 300;
        bool launchGame = false;
        sf::Font font;
        sf::Text play;
        sf::Text quit;
    public:
        Menu();
        void menuLoop(void);
        void jumping(void);
        void setPos(void);
};

#endif