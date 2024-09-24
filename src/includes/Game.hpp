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
            void handleEvents();
            void setOneTimeArrows(bool oneTimeArrows);
            void startMinigame(const std::string minigameName);
            int loadMinigame(const std::string minigameName);
        private:
            sf::RenderWindow                                _window;
            sf::Event                                       _event;
            float                                           _deltaTime;
            sf::Clock                                       _clock;          
            sf::View            _view1;
            sf::View                 _view2;
            bool                                            _isMinigameRunning;
            bool                                            _oneTimeArrows;
            std::shared_ptr<LuaManager>                     _luaManager;
            std::unordered_map<std::string, sol::function> _luaFunctions;
            std::shared_ptr<LuaManager>                    _luaMenuManager;
            std::unordered_map<std::string, sol::function> _luaMenuFunctions;            
    };
}
