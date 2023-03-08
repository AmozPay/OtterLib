/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibSound.hpp
*/

#ifndef RAYLIBSOUND_HPP_
#define RAYLIBSOUND_HPP_

#include "Raylib.hpp"

/**
 * @brief The namespace of the Otter Graphic library for Raylib
 */
namespace Otter::Graphic::Raylib {
    /**
     * @brief The RaylibSound class for Raylib sound management
     */
    class RaylibSound {
      public:
        /**
         * @brief Construct a new Sound object
         * @param sound_path The path of the sound
         */
        explicit RaylibSound(const std::string& sound_path);
        /**
         * @brief Destroy the Sound object
         */
        ~RaylibSound();

        /**
         * @brief Play the sound
         * @return Nothing
         */
        void play();
        /**
         * @brief Pause the sound
         * @return Nothing
         */
        void pause();
        /**
         * @brief Resume the sound
         * @return Nothing
         */
        void resume();
        /**
         * @brief Stop the sound
         * @return Nothing
         */
        void stop();
        /**
         * @brief Set the volume of the sound
         * @return Nothing
         */
        void restart();

        /**
         * @brief Check if the sound is playing
         * @return True if the sound is playing, false otherwise
         */
        bool isPlaying();

        /**
         * @brief Set the volume of the sound
         * @param volume: The volume of the sound
         * @return Nothing
         */
        void setVolume(const float& volume);

        /**
         * @brief Get the volume of the sound
         * @return The volume of the sound
         */
        [[nodiscard]] float getVolume() const;

      private:
        raylib::Sound _sound;
        float _volume;
    };

} // namespace Otter::Graphic::Raylib
#endif /* !RAYLIBSOUND_HPP_ */