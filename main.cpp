/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** main
*/

#include "Game.hpp"
#include <iostream>
#include <sol/sol.hpp> 

int main(void)
{
    Game game;
    sol::state lua; // Création de l'état Lua
    lua.open_libraries(sol::lib::base, sol::lib::math, sol::lib::string); // Ouvre les bibliothèques standard de Lua

    // Charger et exécuter le script Lua
    lua.script_file("scripts/test.lua");

    // Appeler la fonction 'add' définie dans Lua
    sol::function add = lua["add"];
    int result = add(10, 20);

    std::cout << "Résultat de l'addition dans Lua: " << result << std::endl;

    game.run();
    return 0;
}