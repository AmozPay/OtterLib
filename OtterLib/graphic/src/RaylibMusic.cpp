/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibMusic.cpp
*/

#include "RaylibMusic.hpp"

namespace Otter::Graphic::Raylib {

    RaylibMusic::RaylibMusic(const std::string& music_path) : _music(raylib::LoadMusicStream(music_path.c_str())), _volume(1.0f)
    {
    }

    RaylibMusic::~RaylibMusic() { raylib::UnloadMusicStream(_music); }

    void Raylib::RaylibMusic::play() { raylib::PlayMusicStream(_music); }

    void RaylibMusic::pause() { raylib::PauseMusicStream(_music); }

    void RaylibMusic::resume() { raylib::ResumeMusicStream(_music); }

    void RaylibMusic::stop() { raylib::StopMusicStream(_music); }

    void RaylibMusic::restart()
    {
        raylib::StopMusicStream(_music);
        raylib::PlayMusicStream(_music);
    }

    bool RaylibMusic::isPlaying() { return raylib::IsMusicStreamPlaying(_music); }

    void RaylibMusic::setVolume(const float& volume)
    {
        _volume = volume;
        raylib::SetMusicVolume(_music, _volume);
    }

    float RaylibMusic::getVolume() const { return _volume; }
} // namespace Otter::Graphic::Raylib