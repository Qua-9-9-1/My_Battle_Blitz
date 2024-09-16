/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** LuaManager
*/

#include "LuaManager.hpp"

namespace ware {
    LuaManager::LuaManager()
    {
        _luaState = sol::state();
        _luaState.open_libraries(sol::lib::base, sol::lib::math, sol::lib::string);
    }

    LuaManager::~LuaManager()
    {
        _luaState.collect_garbage();
    }

    bool LuaManager::loadScript(const std::string& scriptPath)
    {
        sol::load_result script = _luaState.load_file(scriptPath);

        if (!script.valid()) {
            sol::error error = script;
            std::cerr << "Failed to load Lua script: " << error.what() << std::endl;
            return false;
        }
        script();
        return true;
    }

    sol::table LuaManager::getGlobalTable()
    {
        sol::table globalTable = _luaState.globals();
        return globalTable;
    }

    sol::table LuaManager::getTable(const std::string& tableName)
    {
        sol::table table = _luaState[tableName];
        return table;
    }

    sol::function LuaManager::getFunction(const std::string& functionName)
    {
        sol::function function = _luaState[functionName];
        return function;
    }

    void LuaManager::setGlobal(const std::string& name, sol::object value)
    {
        _luaState[name] = value;
    }
}