/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
*/

#pragma once

#include <SFML/Audio.hpp>
#include "IObject.hpp"

namespace ware {
    class AAudio : public IObject {
        public:
            virtual ~AAudio() = default;
            virtual void play() = 0;
            virtual void stop() = 0;
            virtual void loadFile(const std::string filePath) = 0;
            virtual void setVolume(float volume) = 0;
            virtual void setPitch(float pitch) = 0;
            void update(sf::RenderWindow& window) override;

        protected:
            bool _isPlaying;
    };

    class Sound : public AAudio {
        public:
            Sound(const std::string filePath);
            ~Sound();
            void play() override;
            void stop() override;
            void loadFile(const std::string filePath) override;
            void setVolume(float volume) override;
            void setPitch(float pitch) override;
        private:
            sf::Sound       _sound;
            sf::SoundBuffer _buffer;
    };

    class Music : public AAudio {
        public:
            Music(const std::string filePath);
            ~Music();
            void update(sf::RenderWindow& window) override;
            void play() override;
            void stop() override;
            void replay();
            void setReplayPoint(float seconds);
            bool isPlaying();
            void loadFile(const std::string filePath) override;
            void setVolume(float volume) override;
            void setPitch(float pitch) override;
            void setLoop(bool loop);
        private:
            sf::Music _music;
            sf::Time  _replayPoint;
    };
}
