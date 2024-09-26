/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
*/

#pragma once

#include <SFML/Graphics.hpp>

#define GAME_VERSION "1.0.0"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

sf::Color darkenColor(sf::Color color, float factor);
sf::Color lightenColor(sf::Color color, float factor);