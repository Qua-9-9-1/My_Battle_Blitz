/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** Player
*/

#pragma once

#include <SFML/Graphics.hpp>

namespace ware {
    class Player {
        public:
            Player();
            ~Player();
            void update(sf::RenderWindow& window, float deltaTime);
            sf::Color getSkinColor() { return _skinColor; }
            sf::Color getClothesColor() { return _clothesColor; }
            int getScore() { return _score; }
            void setPlayer(int score, sf::Color skinColor, sf::Color clothesColor);
            void setPosition(sf::Vector2f position);
        private:
            int         _score;
            sf::Color   _skinColor;
            sf::Color   _clothesColor;
    };
}