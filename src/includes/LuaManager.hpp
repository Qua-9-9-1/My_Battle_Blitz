/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** LuaManager
*/

#pragma once

#include <sol/sol.hpp>
#include "LuaManager.hpp"

namespace ware {
    class LuaManager {
        public:
            LuaManager();
            ~LuaManager();
            bool loadScript(const std::string& scriptPath);
            sol::table getGlobalTable();
            sol::table getTable(const std::string& tableName);
            sol::function getFunction(const std::string& functionName);
            void setGlobal(const std::string& name, sol::object value);
        private:
            sol::state _luaState;
            sol::function _luaFunction;
    };
}