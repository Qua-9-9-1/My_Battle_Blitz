/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
*/

#pragma once

#include "LuaManager.hpp"

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
            void unifyViews();
            void startMinigame(const std::string minigameName);
        private:
            sf::RenderWindow    _window;
            sf::Event           _event;
            float               _deltaTime;
            sf::Clock           _clock;          
            sf::View            _view1;
            sf::View            _view2;
            bool                _separatedViews;
            LuaManager          _luaManager;
            bool                _oneTimeArrows;
            Image _image;
            Sprite _sprite;
            Text _text;
            Sound _sound;
            Music _music;
            
    };
}
