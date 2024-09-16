/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** Game
*/

#pragma once

#include "LuaManager.hpp"
#include "View.hpp"

#include "Renderer.hpp"
#include "Audio.hpp"

#include <SFML/Graphics.hpp>

namespace ware {
    class Game {
        public:
            Game();
            ~Game();
            void run();
            void handleEvents(bool oneTimeArrows);
            void separateViews();
            void startMinigame(const std::string minigameName);
        private:
            sf::RenderWindow            _window;
            sf::Event                   _event;
            float                       _deltaTime;            
            std::shared_ptr<ware::View> _view;
            LuaManager                  _luaManager;
            Sprite _sprite;
            Text _text;
            Sound _sound;
            Music _music;
            
    };
}
