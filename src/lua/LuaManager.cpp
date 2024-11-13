/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
*/

#include "LuaManager.hpp"

namespace ware {
LuaManager::LuaManager() {
    _luaState = sol::state();
    _luaState.open_libraries(sol::lib::base, sol::lib::math, sol::lib::string, sol::lib::package);
    _luaState.new_usertype<sf::RenderWindow>("RenderWindow", "close", &sf::RenderWindow::close);
    loadImageClass();
    loadSpriteClass();
    loadTextClass();
    loadButtonClass();
    loadSoundClass();
    loadMusicClass();
    loadBackgroundClasses();
}

LuaManager::~LuaManager() { _luaState.collect_garbage(); }

bool LuaManager::loadScript(const std::string& scriptPath) {
    sol::load_result script = _luaState.load_file(scriptPath);

    if (!script.valid()) {
        sol::error error = script;
        std::cerr << "Failed to load Lua script: " << error.what() << std::endl;
        return false;
    }
    script();
    return true;
}

void LuaManager::unloadScript() { _luaState.collect_garbage(); }

sol::table LuaManager::getGlobalTable() {
    sol::table globalTable = _luaState.globals();
    return globalTable;
}

sol::table LuaManager::getTable(const std::string& tableName) {
    sol::table table = _luaState[tableName];
    return table;
}

sol::function LuaManager::getFunction(const std::string& functionName) {
    sol::function function = _luaState[functionName];
    if (!function.valid()) {
        std::cerr << "Failed to get Lua function: " << functionName << std::endl;
        return sol::nil;
    }
    return function;
}

void LuaManager::setGlobal(const std::string& name, sol::object value) { _luaState[name] = value; }
} // namespace ware