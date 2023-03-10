/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** RaylibTexture.hpp
*/

#pragma once

#include "Raylib.hpp"

/**
 * @brief The namespace of the Otter Graphic library for Raylib
 */
namespace Otter::Graphic::Raylib {

    /**
     * @brief Class for encapsulation of Raylib Texture functions
     */
    class RaylibTexture {
      public:
        explicit RaylibTexture(const std::string& texturePath);
        ~RaylibTexture();

        /**
         * @brief Draw the texture
         * @details Draw the texture at the position given in parameter
         * @param source: The position of the square texture
         * @param position: The position to draw the texture
         * @param rotation: The rotation of the texture
         * @param scale: The scale of the texture
         * @return Nothing
         */
        void draw(Otter::Core::Utils::Rectangle source, Otter::Core::Utils::Vector2 position, float rotation, float scale);

        /**
         * @brief Set the texture to use
         * @param texturePath: The path to the texture to use
         * @return Nothing
         */
        void setTexture(const std::string& texturePath);

        /**
         * @brief Set the color of the texture
         * @param color: The color to set
         * @return Nothing
         */
        void setColor(raylib::Color color);

        /**
         * @brief Get the texture
         * @return The texture
         */
        [[nodiscard]] raylib::Texture2D getTexture() const;

        /**
         * @brief Get the color of the texture
         * @return The color of the texture
         */
        [[nodiscard]] raylib::Color getColor() const;

        /**
         * @brief Get the width of the texture
         * @return The width of the texture
         */
        [[nodiscard]] int getWidth() const;

        /**
         * @brief Get the height of the texture
         * @return The height of the texture
         */
        [[nodiscard]] int getHeight() const;

        /**
         * @brief Get the height of the texture
         * @return The height of the texture
         */
        [[nodiscard]] std::string getFilePath() const;

      private:
        raylib::Texture2D _texture;
        raylib::Color _color;
        std::string _texturePath;
    }; // class Texture
} // namespace Otter::Graphic::Raylib