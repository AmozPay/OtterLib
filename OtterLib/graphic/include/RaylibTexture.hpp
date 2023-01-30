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
         * @param position: The position to draw the texture
         * @return Nothing
         */
        void draw(Vector2 position);

        /**
         * @brief Set the texture to use
         * @param texturePath: The path to the texture to use
         * @return Nothing
         */
        void setTexture(const std::string& texturePath);

        /**
         * @brief Set the rotation of the texture
         * @param rotation: The rotation to set
         * @return Nothing
         */
        void setRotation(float rotation);

        /**
         * @brief Set the scale of the texture
         * @param scale: The scale to set
         * @return Nothing
         */
        void setScale(float scale);

        /**
         * @brief Set the color of the texture
         * @param color: The color to set
         * @return Nothing
         */
        void setColor(Color color);

        /**
         * @brief Get the texture
         * @return The texture
         */
        [[nodiscard]] Texture2D getTexture() const;

        /**
         * @brief Get the rotation of the texture
         * @return The rotation of the texture
         */
        [[nodiscard]] float getRotation() const;

        /**
         * @brief Get the scale of the texture
         * @return The scale of the texture
         */
        [[nodiscard]] float getScale() const;

        /**
         * @brief Get the color of the texture
         * @return The color of the texture
         */
        [[nodiscard]] Color getColor() const;

      private:
        Texture2D _texture;
        float _rotation;
        float _scale;
        Color _color;
    }; // class Texture
} // namespace Otter::Graphic::Raylib