#include "../include/Menu.hpp"
#include "../include/game.hpp"

Menu::Menu()
{
    MustachTexture.loadFromFile("assets/mustach.png");
    MustachSprite.setTexture(MustachTexture);
    MustachSprite.setScale(0.8, 0.8);
    font.loadFromFile("assets/arial.ttf");
    play.setString("PLAY");
    play.setFont(font);
    play.setFillColor(sf::Color::Cyan);
    play.setCharacterSize(30);
    play.setPosition(350, 450);
    quit.setString("QUIT");
    quit.setFont(font);
    quit.setFillColor(sf::Color::Cyan);
    quit.setCharacterSize(30);
    quit.setPosition(350, 500);
    menuLoop();
}

void Menu::menuLoop(void)
{
    _window.create(sf::VideoMode(800, 600), "Moustachio");

    while (_window.isOpen()) {
        _window.pollEvent(event);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
            launchGame = true;
            jumping();
            _window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::getPosition().x >= 450 && sf::Mouse::getPosition().x <= 523 && sf::Mouse::getPosition().y >= 621 && sf::Mouse::getPosition().y <= 651) {
            launchGame = true;
            jumping();
            _window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::getPosition().x >= 450 && sf::Mouse::getPosition().x <= 524 && sf::Mouse::getPosition().y >= 677 && sf::Mouse::getPosition().y <= 702) {
            launchGame = false;
            _window.close();
        }
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            _window.close();
        setPos();
        _window.clear(sf::Color::Blue);
        _window.draw(MustachSprite);
        _window.draw(play);
        _window.draw(quit);
        _window.display();
    }
    if (launchGame)
        Game game;
}

void Menu::jumping(void)
{
    sf::Clock timer;
    int base = mustachposY;
    sf::Time timeLimit = sf::seconds(1.0f);

    while (timer.getElapsedTime().asSeconds() < timeLimit.asSeconds()) {
        int timejump = timer.getElapsedTime().asMilliseconds();
        if (timejump <= 500 && mustachposY > (base - 50))
            mustachposY -= 0.07;
        if (timejump > 500 && mustachposY < base)
            mustachposY += 0.07;
        setPos();
        _window.clear(sf::Color::Blue);
        _window.draw(MustachSprite);
        _window.display();
    }
}

void Menu::setPos(void)
{
    MustachSprite.setPosition(mustachposX, mustachposY);
}