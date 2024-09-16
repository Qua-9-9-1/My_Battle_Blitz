/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** IObject
*/

#pragma once

#include <SFML/Graphics.hpp>

namespace ware {
    class IObject {
        public:
            virtual ~IObject() = default;
            virtual void update(sf::RenderWindow& window, float deltaTime) = 0;
    };
}