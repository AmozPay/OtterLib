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
             * @param text The content of the Text object
             * @param fontPath The path to the font to use
             * @return A new instance of the Raylib::Text class
             */
            RaylibText(std::string  text, const std::string &fontPath);
            /**
             * @brief Destructor for the Raylib::Text class
             * @return Nothing
             */
            ~RaylibText();

            /**
             * @brief Draw a text
             * @return Nothing
             */
            void draw();

            /**
             * @brief Set the font to use
             * @param fontPath: The path to the font to use
             * @return Nothing
             */
            void setFont(const std::string &fontPath);

            /**
             * @brief Set the text to display
             * @param text: The text to set
             * @return Nothing
             */
            void setText(const std::string &text);

            /**
             * @brief Set the position of the text
             * @param pos: The position to set
             * @return Nothing
             */
            void setPos(Vector2 pos);

            /**
             * @brief Set the origin of the text
             * @param origin: The origin to set
             * @return Nothing
             */
            void setOrigin(Vector2 origin);

            /**
             * @brief Set the rotation of the text
             * @param rotation: The rotation to set
             * @return Nothing
             */
            void setRotation(float rotation);

            /**
             * @brief Set the font size of the text
             * @param fontSize: The font size to set
             * @return Nothing
             */
            void setFontSize(float fontSize);

            /**
             * @brief Set the spacing of the text
             * @param spacing: The spacing to set
             * @return Nothing
             */
            void setSpacing(float spacing);

            /**
             * @brief Set the color of the text
             * @param color: The color to set
             * @return Nothing
             */
            void setColor(Color color);

            /**
             * @brief Get the font of the text
             * @return The font of the text
             */
            [[nodiscard]] Font getFont() const;

            /**
             * @brief Get the text of the text
             * @return The text of the text
             */
            [[nodiscard]] std::string getText() const;

            /**
             * @brief Get the position of the text
             * @return The position of the text
             */
            [[nodiscard]] Vector2 getPos() const;

            /**
             * @brief Get the origin of the text
             * @return The origin of the text
             */
            [[nodiscard]] Vector2 getOrigin() const;

            /**
            * @brief Get the font 
            * @return The font
            */
            [[nodiscard]] float getFontSize() const;

            /**
             * @brief get spacing
            */
            [[nodiscard]] float getSpacing() const;

            /**
             * @brief Get the color of the text
             * @return The color of the text
             */
            [[nodiscard]] Color getColor() const;

        private:
            Font _font;
            std::string _text;
            Vector2 _position;
            Vector2 _origin;
            float _rotation;
            float _fontSize;
            float _spacing;
            Color _color;
    }; // class Text

} // namespace Raylib::Text