/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibSound.cpp
*/
#include "RaylibSound.hpp"

namespace Otter::Graphic::Raylib
{
    RaylibSound::RaylibSound(const std::string &sound_path) : _sound(LoadSound(sound_path.c_str())), _volume(1.0f)
    {}

    RaylibSound::~RaylibSound() {
        UnloadSound(_sound);
    }

    void RaylibSound::play() {
        PlaySound(_sound);
    }

    void RaylibSound::pause() {
        PauseSound(_sound);
    }

    void RaylibSound::resume() {
        ResumeSound(_sound);
    }

    void RaylibSound::stop() {
        StopSound(_sound);
    }

    void RaylibSound::restart() {
        StopSound(_sound);
        PlaySound(_sound);
    }

    bool RaylibSound::isPlaying() {
        return IsSoundPlaying(_sound);
    }

    void RaylibSound::setVolume(const float &volume) {
        _volume = volume;
        SetSoundVolume(_sound, _volume);
    }

    float RaylibSound::getVolume() const {
        return _volume;
    }
}
