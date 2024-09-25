/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "LuaManager.hpp"
#include "View.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

namespace ware {
    class Game {
        public:
            Game();
            ~Game();
            void run();
            void handleEvents();
            void handleOneTimeKeys();
            void handleMutipleTimeKeys();
            void setOneTimeArrows(bool oneTimeArrows) { _oneTimeArrows = oneTimeArrows; }
            void setOneTimeButtons(bool oneTimeButtons) { _oneTimeButtons = oneTimeButtons; }
            void launchMenu();
            void startMinigame(const std::string minigameName);
            int loadMinigame(const std::string minigameName);
            void stopMinigame();
            void separateViews();
            void unifyViews();
            void doInput(const std::string& input);
            void resizeViews(int width, int height);
        private:
            sf::RenderWindow                                _window;
            sf::Event                                       _event;
            float                                           _deltaTime;
            sf::Clock                                       _clock;
            View                                            _view1;
            View                                            _view2;      
            bool                                            _isMinigameRunning;
            bool                                            _oneTimeArrows;
            bool                                            _oneTimeButtons;
            bool                                            _pause;
            bool                                            _separatedViews;
            std::shared_ptr<LuaManager>                     _luaManager;
            std::unordered_map<std::string, sol::function> _luaFunctions;
            std::shared_ptr<LuaManager>                    _luaMenuManager;
            std::unordered_map<std::string, sol::function> _luaMenuFunctions;            
    };
}
