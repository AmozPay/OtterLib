/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibMusic.cpp
*/

#include "RaylibMusic.hpp"

namespace Otter::Graphic::Raylib {

    RaylibMusic::RaylibMusic(const std::string& music_path) : _music(LoadMusicStream(music_path.c_str())), _volume(1.0f)
    {
    }

    RaylibMusic::~RaylibMusic() { UnloadMusicStream(_music); }

    void Raylib::RaylibMusic::play() { PlayMusicStream(_music); }

    void RaylibMusic::pause() { PauseMusicStream(_music); }

    void RaylibMusic::resume() { ResumeMusicStream(_music); }

    void RaylibMusic::stop() { StopMusicStream(_music); }

    void RaylibMusic::restart()
    {
        StopMusicStream(_music);
        PlayMusicStream(_music);
    }

    bool RaylibMusic::isPlaying() { return IsMusicStreamPlaying(_music); }

    void RaylibMusic::setVolume(const float& volume)
    {
        _volume = volume;
        SetMusicVolume(_music, _volume);
    }

    float RaylibMusic::getVolume() const { return _volume; }
} // namespace Otter::Graphic::Raylib