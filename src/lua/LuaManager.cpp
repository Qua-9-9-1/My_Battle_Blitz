/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
*/

#include "LuaManager.hpp"

namespace ware {
    LuaManager::LuaManager()
    {
        _luaState = sol::state();
        _luaState.open_libraries(sol::lib::base, sol::lib::math, sol::lib::string);
        _luaState.new_usertype<Image>("Image",
            sol::constructors<Image(const std::string&)>(),
            "loadFile", &Image::loadFile,
            "getImage", &Image::getImage,
            "colorize", &Image::colorize,
            "setPlayerColor", &Image::setPlayerColor,
            "setPlayer2Color", &Image::setPlayer2Color,
            "flipImage", &Image::flipImage
        );
        _luaState.new_usertype<Sprite>("Sprite",
            sol::constructors<Sprite(sf::Image)>(),
            "loadImage", &Sprite::loadImage,
            "update", &Sprite::update,
            "disappear", &Sprite::disappear,
            "setPosition", &Sprite::setPosition,
            "move", &Sprite::move,
            "setScale", &Sprite::setScale,
            "setRotation", &Sprite::setRotation,
            "rotate", &Sprite::rotate,
            "setTextureRect", &Sprite::setTextureRect,
            "setColor", &Sprite::setColor
        );
        _luaState.new_usertype<Text>("Text",
            sol::constructors<Text(const std::string&, const std::string&)>(),
            "loadFile", &Text::loadFile,
            "update", &Text::update,
            "setPosition", &Text::setPosition,
            "move", &Text::move,
            "setScale", &Text::setScale,
            "setRotation", &Text::setRotation,
            "rotate", &Text::rotate,
            "setColor", &Text::setColor
        );
        // _luaState.new_usertype<Button>("Button",
        //     sol::constructors<Button(const std::string&, const std::string&)>(),
        //     "loadFile", &Button::loadFile,
        //     "update", &Button::update,
        //     "disappear", &Button::disappear,
        //     "setPosition", &Button::setPosition,
        //     "setScale", &Button::setScale,
        //     "setRotation", &Button::setRotation,
        //     "setColor", &Button::setColor,
        //     "setBorderColor", &Button::setBorderColor,
        //     "setString", &Button::setString,
        //     "setCharacterSize", &Button::setCharacterSize,
        //     "setButtonColor", &Button::setButtonColor,
        //     "setButtonBorderColor", &Button::setButtonBorderColor,
        //     "setButtonSize", &Button::setButtonSize,
        //     "setButtonPosition", &Button::setButtonPosition,
        //     "setButtonScale", &Button::setButtonScale,
        //     "setButtonRotation", &Button::setButtonRotation,
        //     "setButtonTexture", &Button::setButtonTexture,
        //     "setButtonTextureRect", &Button::setButtonTextureRect,
        //     "setButtonColorize", &Button::setButtonColorize,
        //     "setButtonPlayerColor", &Button::setButtonPlayerColor,
        //     "setButtonPlayer2Color", &Button::setButtonPlayer2Color,
        //     "setButtonFlipImage", &Button::setButtonFlipImage
        // );
        _luaState.new_usertype<Sound>("Sound",
            sol::constructors<Sound(const std::string&)>(),
            "loadFile", &Sound::loadFile,
            "play", &Sound::play,
            "stop", &Sound::stop,
            "setVolume", &Sound::setVolume,
            "setPitch", &Sound::setPitch
        );
        _luaState.new_usertype<Music>("Music",
            sol::constructors<Music(const std::string&)>(),
            "loadFile", &Music::loadFile,
            "play", &Music::play,
            "replay", &Music::replay,
            "stop", &Music::stop,
            "isPlaying", &Music::isPlaying,
            "setReplayPoint", &Music::setReplayPoint
        );

    }

    LuaManager::~LuaManager()
    {
        _luaState.collect_garbage();
    }

    bool LuaManager::loadScript(const std::string& scriptPath)
    {
        sol::load_result script = _luaState.load_file(std::filesystem::current_path().string() + scriptPath);

        if (!script.valid()) {
            sol::error error = script;
            std::cerr << "Failed to load Lua script: " << error.what() << std::endl;
            return false;
        }
        script();
        return true;
    }

    void LuaManager::unloadScript()
    {
        _luaState.collect_garbage();
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
        if (!function.valid()) {
            std::cerr << "Failed to get Lua function: " << functionName << std::endl;
            return sol::nil;
        }
        return function;
    }

    void LuaManager::setGlobal(const std::string& name, sol::object value)
    {
        _luaState[name] = value;
    }
}