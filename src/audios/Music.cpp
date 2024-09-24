#include "Audio.hpp"

namespace ware {
    Music::Music(const std::string filePath)
    {
        loadFile(filePath);
        _replayPoint = sf::seconds(0);
    }

    Music::~Music()
    {
    }

    void Music::loadFile(const std::string filePath)
    {
        _music.openFromFile(filePath);
        setLoop(true);
    }

    void Music::update(sf::RenderWindow& window)
    {
        (void)window;
        if (!isPlaying())
            replay();
    }

    void Music::play()
    {
        _music.play();
    }

    void Music::replay()
    {
        play();
        _music.setPlayingOffset(_replayPoint);
    }

    void Music::stop()
    {
        _music.stop();
    }

    bool Music::isPlaying()
    {
        return _music.getStatus() == sf::Music::Playing;
    }

    void Music::setReplayPoint(float seconds)
    {
        _replayPoint = sf::seconds(seconds);
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

    void AAudio::update(sf::RenderWindow& window)
    {
        (void)window;
    }
}