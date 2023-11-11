#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <unistd.h>

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Moustachio");
    sf::Event event;

    while (window.isOpen()) {
        window.pollEvent(event);
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
    }


    return 0;
}
