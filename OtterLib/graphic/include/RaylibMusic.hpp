/*
** EPITECH PROJECT, 2023
** OtterLib
** File description:
** RaylibMusic.hpp
*/
#ifndef RAYLIBMUSIC_HPP_
#define RAYLIBMUSIC_HPP_

#include <string>
#include <raylib.h>

/**
 * @brief The namespace of the Otter Graphic library for Raylib
 */
namespace Otter::Graphic::Raylib
{
    /**
     * @brief The RaylibMusic class for Raylib music management
     */
    class RaylibMusic {
    public:
        /**
         * @brief Construct a new Music object
         * @param music_path The path of the music
         */
        explicit RaylibMusic(const std::string &music_path);
        /**
         * @brief Destroy the Music object
         */
        ~RaylibMusic();

        /**
         * @brief Play the music
         */
        void play();
        /**
         * @brief Pause the music
         */
        void pause();
        /**
         * @brief Resume the music
         */
        void resume();
        /**
         * @brief Stop the music
         */
        void stop();
        /**
         * @brief Set the volume of the music
         */
        void restart();

        /**
         * @brief Check uf the music is playing
         * @return True if the music is playing, false otherwise
         */
        bool isPlaying();

        /**
         * @brief Set the volume of the music
         * @param volume The volume of the music
         */
        void setVolume(const float &volume);

        /**
         * @brief Get the volume of the music
         * @return The volume of the music
         */
        [[nodiscard]] float getVolume() const;

      private:
        Music _music;
        float _volume;
    };
}

#endif /* !RAYLIBMUSIC_HPP_ */