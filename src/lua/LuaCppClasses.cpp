#include "LuaManager.hpp"

namespace ware {
void LuaManager::loadImageClass() {
    _luaState.new_usertype<Image>("Image", sol::constructors<Image(const std::string&)>(),
                                  "loadFile", &Image::loadFile, "getImage", &Image::getImage,
                                  "colorize", &Image::colorize, "setPlayerColor",
                                  &Image::setPlayerColor, "setPlayer2Color",
                                  &Image::setPlayer2Color, "flipImage", &Image::flipImage);
}

void LuaManager::loadSpriteClass() {
    _luaState.new_usertype<Sprite>(
        "Sprite", sol::constructors<Sprite(sf::Image)>(), "loadImage", &Sprite::loadImage, "update",
        &Sprite::update, "draw", &Sprite::draw, "disappear", &Sprite::disappear, "setPosition",
        &Sprite::setPosition, "move", &Sprite::move, "setScale", &Sprite::setScale, "setRotation",
        &Sprite::setRotation, "rotate", &Sprite::rotate, "setTextureRect", &Sprite::setTextureRect,
        "setColor", &Sprite::setColor, "flip", &Sprite::flip);
}

void LuaManager::loadTextClass() {
    _luaState.new_usertype<Text>(
        "Text", sol::constructors<Text(const std::string&, const std::string&)>(), "loadFile",
        &Text::loadFile, "update", &Text::update, "draw", &Text::draw, "setPosition",
        &Text::setPosition, "move", &Text::move, "setScale", &Text::setScale, "setRotation",
        &Text::setRotation, "rotate", &Text::rotate, "setColor", &Text::setColor, "setBorderColor",
        &Text::setBorderColor, "setBorderThickness", &Text::setBorderThickness, "setString",
        &Text::setString, "setCharacterSize", &Text::setCharacterSize);
}

void LuaManager::loadButtonClass() {
    _luaState.new_usertype<Button>(
        "Button", sol::constructors<Button(const std::string&, const std::string&, float, float)>(),
        "update", &Button::update, "draw", &Button::draw, "disappear", &Button::disappear,
        "setPosition", &Button::setPosition, "move", &Button::move, "setScale", &Button::setScale,
        "setRotation", &Button::setRotation, "rotate", &Button::rotate, "setColor",
        &Button::setColor, "setBorderColor", &Button::setBorderColor, "setTextColor",
        &Button::setTextColor, "setString", &Button::setString, "setSize", &Button::setSize,
        "setTextSize", &Button::setTextSize, "setBorder", &Button::setBorder, "setTexture",
        &Button::setTexture, "setTextureRect", &Button::setTextureRect);
}

void LuaManager::loadSoundClass() {
    _luaState.new_usertype<Sound>("Sound", sol::constructors<Sound(const std::string&)>(),
                                  "loadFile", &Sound::loadFile, "play", &Sound::play, "stop",
                                  &Sound::stop, "setVolume", &Sound::setVolume, "setPitch",
                                  &Sound::setPitch);
}

void LuaManager::loadMusicClass() {
    _luaState.new_usertype<Music>(
        "Music", sol::constructors<Music(const std::string&)>(), "loadFile", &Music::loadFile,
        "update", &Music::update, "play", &Music::play, "replay", &Music::replay, "stop",
        &Music::stop, "isPlaying", &Music::isPlaying, "setReplayPoint", &Music::setReplayPoint);
}

void LuaManager::loadBackgroundClasses() {
    _luaState.new_usertype<SolidColorBackground>(
        "SolidColorBackground",
        sol::constructors<SolidColorBackground(float, float, float, float)>(), "update",
        &SolidColorBackground::update, "draw", &SolidColorBackground::draw, "setPosition",
        &SolidColorBackground::setPosition, "setSize", &SolidColorBackground::setSize, "setScale",
        &SolidColorBackground::setScale, "setRotation", &SolidColorBackground::setRotation,
        "setColor", &SolidColorBackground::setColor);

    _luaState.new_usertype<ScrollingBackground>(
        "ScrollingBackground", sol::constructors<ScrollingBackground(sf::Image)>(), "update",
        &ScrollingBackground::update, "draw", &ScrollingBackground::draw, "setPosition",
        &ScrollingBackground::setPosition, "setSize", &ScrollingBackground::setSize, "setScale",
        &ScrollingBackground::setScale, "setSpriteRect", &ScrollingBackground::setSpriteRect,
        "setRotation", &ScrollingBackground::setRotation, "setSpeed",
        &ScrollingBackground::setSpeed, "setDirection", &ScrollingBackground::setDirection,
        "setColor", &ScrollingBackground::setColor);

    _luaState.new_usertype<ImageBackground>(
        "ImageBackground", sol::constructors<ImageBackground(sf::Image)>(), "update",
        &ImageBackground::update, "draw", &ImageBackground::draw, "setPosition",
        &ImageBackground::setPosition, "setSize", &ImageBackground::setSize, "setScale",
        &ImageBackground::setScale, "setSpriteRect", &ImageBackground::setSpriteRect, "setRotation",
        &ImageBackground::setRotation);

    _luaState.new_usertype<ParallaxBackground>(
        "ParallaxBackground", sol::constructors<ParallaxBackground(sf::Image, int)>(), "update",
        &ParallaxBackground::update, "draw", &ParallaxBackground::draw, "setPosition",
        &ParallaxBackground::setPosition, "setSize", &ParallaxBackground::setSize, "setScale",
        &ParallaxBackground::setScale, "setSpeeds", &ParallaxBackground::setSpeed, "setDirection",
        &ParallaxBackground::setDirection);
}
} // namespace ware