/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
*/

#pragma once

#include <sol/sol.hpp>
#include <SFML/Graphics.hpp>
#include "LuaManager.hpp"
#include "Renderer.hpp"
#include "Audio.hpp"
#include "Settings.hpp"
#include "Game.hpp"

namespace ware {
class LuaManager {
  public:
    LuaManager();
    ~LuaManager();
    void                       loadGameClass();
    void                       loadImageClass();
    void                       loadSpriteClass();
    void                       loadTextClass();
    void                       loadButtonClass();
    void                       loadSoundClass();
    void                       loadMusicClass();
    void                       loadBackgroundClasses();
    bool                       loadScript(const std::string& scriptPath);
    void                       unloadScript();
    sol::table                 getGlobalTable();
    sol::table                 getTable(const std::string& tableName);
    sol::function              getFunction(const std::string& functionName);
    template <typename T> void setGlobal(const std::string& name, T&& value) {
        _luaState[name] = sol::make_object(_luaState, std::forward<T>(value));
    }

  private:
    sol::state    _luaState;
    sol::function _luaFunction;
};
} // namespace ware