/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
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