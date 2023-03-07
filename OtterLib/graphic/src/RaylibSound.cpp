/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibSound.cpp
*/
#include "RaylibSound.hpp"

namespace Otter::Graphic::Raylib {
    RaylibSound::RaylibSound(const std::string& sound_path) : _sound(raylib::LoadSound(sound_path.c_str())), _volume(1.0f) {}

    RaylibSound::~RaylibSound() { raylib::UnloadSound(_sound); }

    void RaylibSound::play() { raylib::PlaySound(_sound); }

    void RaylibSound::pause() { raylib::PauseSound(_sound); }

    void RaylibSound::resume() { raylib::ResumeSound(_sound); }

    void RaylibSound::stop() { raylib::StopSound(_sound); }

    void RaylibSound::restart()
    {
        raylib::StopSound(_sound);
        raylib::PlaySound(_sound);
    }

    bool RaylibSound::isPlaying() { return raylib::IsSoundPlaying(_sound); }

    void RaylibSound::setVolume(const float& volume)
    {
        _volume = volume;
        raylib::SetSoundVolume(_sound, _volume);
    }

    float RaylibSound::getVolume() const { return _volume; }
} // namespace Otter::Graphic::Raylib
