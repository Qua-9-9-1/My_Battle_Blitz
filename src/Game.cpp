/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
    window.create(sf::VideoMode(800, 600), "my_MicroGames");
    window.setFramerateLimit(60);
}

Game::~Game()
{
}

void Game::run()
{
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        // Draw here
        window.display();
    }
}