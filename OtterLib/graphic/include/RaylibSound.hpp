/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibSound.hpp
*/

#ifndef RAYLIBSOUND_HPP_
#define RAYLIBSOUND_HPP_

#include <string>
#include <raylib.h>

/**
 * @brief The namespace of the Otter Graphic library for Raylib
 */
namespace Otter::Graphic::Raylib
{
    /**
     * @brief The RaylibSound class for Raylib sound management
     */
    class RaylibSound {
    public:
        /**
         * @brief Construct a new Sound object
         * @param sound_path The path of the sound
         */
        explicit RaylibSound(const std::string &sound_path);
        /**
         * @brief Destroy the Sound object
         */
        ~RaylibSound();

        /**
         * @brief Play the sound
         */
        void play();
        /**
         * @brief Pause the sound
         */
        void pause();
        /**
         * @brief Resume the sound
         */
        void resume();
        /**
         * @brief Stop the sound
         */
        void stop();
        /**
         * @brief Set the volume of the sound
         */
        void restart();

        /**
         * @brief Check if the sound is playing
         * @return True if the sound is playing, false otherwise
         */
        bool isPlaying();

        /**
         * @brief Set the volume of the sound
         * @param volume The volume of the sound
         */
        void setVolume(const float &volume);

        /**
         * @brief Get the volume of the sound
         * @return The volume of the sound
         */
        [[nodiscard]] float getVolume() const;

    private:
        Sound _sound;
        float _volume;
    };

}
#endif /* !RAYLIBSOUND_HPP_ */