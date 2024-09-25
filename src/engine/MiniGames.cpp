#include "Game.hpp"

namespace ware {

    void Game::launchMenu()
    {
        std::vector<std::string> requiredFunctions = {
            "update", "onP1Left", "onP1Right", "onP1Up", "onP1Down",
            "onP2Left", "onP2Right", "onP2Up", "onP2Down", "onP1_1", "onP1_2",
            "onP1_3", "onP2_1", "onP2_2", "onP2_3", "onP1Start", "onP2Start"
        };

        _luaMenuFunctions.clear();
        _luaMenuManager->loadScript("scripts/game_menu/menu.lua");
        _luaMenuFunctions["init"] = _luaMenuManager->getFunction("init");
        if (!_luaMenuFunctions["init"].valid()) {
            std::cerr << "Failed to get Lua function init" << std::endl;
            exit(1);
        }
        try {
            sol::protected_function_result result = _luaMenuFunctions["init"]();
            if (!result.valid() || result.get<bool>() == false) {
                sol::error err = result;
                std::cerr << "Error initializing game: " << err.what() << std::endl;
                exit(1);
            }
        } catch (const std::exception& e) {
            std::cerr << "Error initializing game: " << e.what() << std::endl;
            exit(1);
        }
        _luaMenuFunctions["update"] = _luaMenuManager->getFunction("update");
        _luaMenuFunctions["onP1Left"] = _luaMenuManager->getFunction("on_P1_left");
        _luaMenuFunctions["onP1Right"] = _luaMenuManager->getFunction("on_P1_right");
        _luaMenuFunctions["onP1Up"] = _luaMenuManager->getFunction("on_P1_up");
        _luaMenuFunctions["onP1Down"] = _luaMenuManager->getFunction("on_P1_down");
        _luaMenuFunctions["onP2Left"] = _luaMenuManager->getFunction("on_P2_left");
        _luaMenuFunctions["onP2Right"] = _luaMenuManager->getFunction("on_P2_right");
        _luaMenuFunctions["onP2Up"] = _luaMenuManager->getFunction("on_P2_up");
        _luaMenuFunctions["onP2Down"] = _luaMenuManager->getFunction("on_P2_down");
        _luaMenuFunctions["onP1_1"] = _luaMenuManager->getFunction("on_P1_1");
        _luaMenuFunctions["onP1_2"] = _luaMenuManager->getFunction("on_P1_2");
        _luaMenuFunctions["onP1_3"] = _luaMenuManager->getFunction("on_P1_3");
        _luaMenuFunctions["onP2_1"] = _luaMenuManager->getFunction("on_P2_1");
        _luaMenuFunctions["onP2_2"] = _luaMenuManager->getFunction("on_P2_2");
        _luaMenuFunctions["onP2_3"] = _luaMenuManager->getFunction("on_P2_3");
        _luaMenuFunctions["onP1Start"] = _luaMenuManager->getFunction("on_P1_start");
        _luaMenuFunctions["onP2Start"] = _luaMenuManager->getFunction("on_P2_start");
        for (const auto& func : requiredFunctions)
            if (!_luaMenuFunctions[func].valid())
                exit(1);
    }

    void Game::startMinigame(const std::string minigameName)
    {
        _isMinigameRunning = true;
        if (loadMinigame(minigameName) != 0) {
                _luaManager->unloadScript();
                _isMinigameRunning = false;
                exit(1);
        }
    }

    int Game::loadMinigame(const std::string minigameName)
    {
        std::vector<std::string> requiredFunctions = {
            "update", "draw", "onP1Left", "onP1Right", "onP1Up", "onP1Down",
            "onP2Left", "onP2Right", "onP2Up", "onP2Down", "onP1_1", "onP1_2",
            "onP1_3", "onP2_1", "onP2_2", "onP2_3"
        };

        _luaFunctions.clear();
        _luaManager->loadScript("scripts/" + minigameName + ".lua");
        _luaFunctions["init"] = _luaManager->getFunction("init");
        //pas besoin de l'enregistrer, donner en paramètres afficher règles
        if (!_luaFunctions["init"].valid()) {
            std::cerr << "Failed to get Lua function init" << std::endl;
            return 1;
        }
        try {
            sol::protected_function_result result = _luaFunctions["init"]();
            if (!result.valid() || result.get<bool>() == false) {
                sol::error err = result;
                std::cerr << "Error initializing game: " << err.what() << std::endl;
                return 1;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error initializing game: " << e.what() << std::endl;
            return 1;
        }
        _luaFunctions["update"] = _luaManager->getFunction("update");
        _luaFunctions["draw"] = _luaManager->getFunction("draw");
        _luaFunctions["onP1Left"] = _luaManager->getFunction("on_P1_left");
        _luaFunctions["onP1Right"] = _luaManager->getFunction("on_P1_right");
        _luaFunctions["onP1Up"] = _luaManager->getFunction("on_P1_up");
        _luaFunctions["onP1Down"] = _luaManager->getFunction("on_P1_down");
        _luaFunctions["onP2Left"] = _luaManager->getFunction("on_P2_left");
        _luaFunctions["onP2Right"] = _luaManager->getFunction("on_P2_right");
        _luaFunctions["onP2Up"] = _luaManager->getFunction("on_P2_up");
        _luaFunctions["onP2Down"] = _luaManager->getFunction("on_P2_down");
        _luaFunctions["onP1_1"] = _luaManager->getFunction("on_P1_1");
        _luaFunctions["onP1_2"] = _luaManager->getFunction("on_P1_2");
        _luaFunctions["onP1_3"] = _luaManager->getFunction("on_P1_3");
        _luaFunctions["onP2_1"] = _luaManager->getFunction("on_P2_1");
        _luaFunctions["onP2_2"] = _luaManager->getFunction("on_P2_2");
        _luaFunctions["onP2_3"] = _luaManager->getFunction("on_P2_3");
        for (const auto& func : requiredFunctions)
            if (!_luaFunctions[func].valid())
                return 1;
        return 0;
    }

    void Game::stopMinigame()
    {
        _luaManager->unloadScript();
        _isMinigameRunning = false;
        unifyViews();
    }
}