/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** EncRaylibText.hpp
*/

#pragma once

#include "Raylib.hpp"

/**
 * @brief The namespace of the Otter Graphic library for Raylib
 */
namespace Otter::Graphic::Raylib {

    /**
     * @brief Class for the encapsulation of the Raylib Text functions
     */
    class RaylibText {
      public:
        /**
         * @brief Constructor for the Raylib::Text class
         * @return A new instance of the Raylib::Text class
         */
        RaylibText();
        /**
         * @brief Destructor for the Raylib::Text class
         * @return Nothing
         */
        ~RaylibText();

        /**
         * @brief Draw a text
         * @param text: The text to draw
         * @param pos: The position to draw the text
         * @param fontSize: The size of the font
         * @return Nothing
         */
        void draw(std::string& text, Otter::Core::Utils::Vector2 pos, int fontSize);

        /**
         * @brief Set the font to use
         * @param fontPath: The path to the font to use
         * @return Nothing
         */
        void setFont(const std::string& fontPath);

        /**
         * @brief Set the color of the text
         * @param color: The color to set
         * @return Nothing
         */
        void setColor(raylib::Color color);

        /**
         * @brief Get the font of the text
         * @return The font of the text
         */
        [[nodiscard]] raylib::Font getFont() const;

        /**
         * @brief Get the color of the text
         * @return The color of the text
         */
        [[nodiscard]] raylib::Color getColor() const;

      private:
        raylib::Font _font;
        raylib::Color _color;
    }; // class Text

} // namespace Otter::Graphic::Raylib