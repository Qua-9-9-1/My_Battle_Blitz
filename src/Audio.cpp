/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
*/

#include "Audio.hpp"

namespace ware {
    Sound::Sound(const std::string filePath)
    {
        loadFile(filePath);
    }

    Sound::~Sound()
    {
    }

    void Sound::loadFile(const std::string filePath)
    {
        _buffer.loadFromFile(filePath);
        _sound.setBuffer(_buffer);
        _isPlaying = false;
    }

    void Sound::play()
    {
        _isPlaying = true;
        _sound.play();
    }

    void Sound::stop()
    {
        _isPlaying = false;
        _sound.stop();
    }

    void Sound::setVolume(float volume)
    {
        _sound.setVolume(volume);
    }

    void Sound::setPitch(float pitch)
    {
        _sound.setPitch(pitch);
    }

    Music::Music(const std::string filePath)
    {
        loadFile(filePath);
    }

    void Music::loadFile(const std::string filePath)
    {
        _music.openFromFile(filePath);
        _isPlaying = false;
    }

    Music::~Music()
    {
    }

    void Music::play()
    {
        _music.play();
        _isPlaying = true;
    }

    void Music::stop()
    {
        _music.stop();
        _isPlaying = false;
    }


    void Music::setVolume(float volume)
    {
        _music.setVolume(volume);
    }

    void Music::setPitch(float pitch)
    {
        _music.setPitch(pitch);
    }

    void Music::setLoop(bool loop)
    {
        _music.setLoop(loop);
    }

    void AAudio::update(sf::RenderWindow& window, float deltaTime)
    {
        if (_isPlaying)
            play();
        else
            stop();
    }
}