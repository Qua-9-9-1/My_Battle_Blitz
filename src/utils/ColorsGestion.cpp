/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** ColorsGestion
*/

#include "utils.hpp"

sf::Color darkenColor(sf::Color color, float factor)
{
    return sf::Color(color.r * factor, color.g * factor, color.b * factor, color.a);
}

sf::Color lightenColor(sf::Color color, float factor)
{
    return sf::Color(color.r + (255 - color.r) * factor, color.g + (255 - color.g) * factor, color.b + (255 - color.b) * factor, color.a);
}
