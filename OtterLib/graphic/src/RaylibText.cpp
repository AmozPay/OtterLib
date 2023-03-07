/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** RaylibText.cpp
*/

#include "RaylibText.hpp"

#include <utility>

/**
 * @brief The namespace of the Otter Graphic library for Raylib
 */
namespace Otter::Graphic::Raylib {

    /**
     * @brief Constructor for the Raylib::Text class
     * @return A new instance of the Raylib::Text class
     */
    RaylibText::RaylibText() : _color(WHITE) {}

    /**
     * @brief Destructor for the Raylib::Text class
     * @return Nothing
     */
    // RaylibText::~RaylibText() { UnloadFont(_font); }
    RaylibText::~RaylibText() = default;

    /**
     * @brief Draw a text
     * @param text: The text to draw
     * @param pos: The position to draw the text
     * @param fontSize: The size of the font
     * @return Nothing
     */
    void RaylibText::draw(std::string& text, Vector2 pos, int fontSize)
    {
        DrawText(text.c_str(), pos.x, pos.y, fontSize, _color);
    }

    /**
     * @brief Set the font to use
     * @param fontPath: The path to the font to use
     * @return Nothing
     */
    void RaylibText::setFont(const std::string& fontPath)
    {
        UnloadFont(_font);
        _font = LoadFont(fontPath.c_str());
    }

    /**
     * @brief Set the color of the text
     * @param color: The color to set
     * @return Nothing
     */
    void RaylibText::setColor(Color color) { _color = color; }

    /**
     * @brief Get the font used
     * @return The font used
     */
    Font RaylibText::getFont() const { return _font; }

    /**
     * @brief Get the color of the text
     * @return The color of the text
     */
    Color RaylibText::getColor() const { return _color; }
} // namespace Otter::Graphic::Raylib