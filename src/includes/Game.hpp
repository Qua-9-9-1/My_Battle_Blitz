/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** Game
*/

#pragma once

#include <SFML/Graphics.hpp>

class Game {
    public:
        Game();
        ~Game();
        void run();
    private:
        sf::RenderWindow window;
        sf::Event event;
};
