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
     * @param text The content of the Text object
     * @param fontPath The path to the font to use
     * @return A new instance of the Raylib::Text class
     */
    RaylibText::RaylibText(std::string text, const std::string &fontPath) : _font(LoadFont(fontPath.c_str())),
                                                                        _text(std::move(text)), _position({0, 0}),
                                                                        _origin({0, 0}), _rotation(0), _fontSize(16),
                                                                        _spacing(0), _color({0, 0, 0, 255})
    {
    }

    /**
     * @brief Destructor for the Raylib::Text class
     * @return Nothing
     */
    RaylibText::~RaylibText()
    {
        UnloadFont(_font);
    }

    /**
     * @brief Draw a text
     * @return Nothing
     */
    void RaylibText::draw()
    {
        DrawTextPro(_font, _text.c_str(), _position, _origin, _rotation, _fontSize, _spacing, _color);
    }

    /**
     * @brief Set the font to use
     * @param fontPath: The path to the font to use
     * @return Nothing
     */
    void RaylibText::setFont(const std::string &fontPath)
    {
        UnloadFont(_font);
        _font = LoadFont(fontPath.c_str());
    }

    /**
     * @brief Set the text to display
     * @param text: The text to set
     * @return Nothing
     */
    void RaylibText::setText(const std::string &text)
    {
        _text = text;
    }

    /**
     * @brief Set the position of the text
     * @param pos: The position to set
     * @return Nothing
     */
    void RaylibText::setPos(Vector2 pos)
    {
        _position = pos;
    }

    /**
     * @brief Set the origin of the text
     * @param origin: The origin to set
     * @return Nothing
     */
    void RaylibText::setOrigin(Vector2 origin)
    {
        _origin = origin;
    }

    /**
     * @brief Set the rotation of the text
     * @param rotation: The rotation to set
     * @return Nothing
     */
    void RaylibText::setRotation(float rotation)
    {
        _rotation = rotation;
    }

    /**
     * @brief Set the font size of the text
     * @param fontSize: The font size to set
     * @return Nothing
     */
    void RaylibText::setFontSize(float fontSize)
    {
        _fontSize = fontSize;
    }

    /**
     * @brief Set the spacing between letters of the text
     * @param spacing: The spacing to set
     * @return Nothing
     */
    void RaylibText::setSpacing(float spacing)
    {
        _spacing = spacing;
    }

    /**
     * @brief Set the color of the text
     * @param color: The color to set
     * @return Nothing
     */
    void RaylibText::setColor(Color color)
    {
        _color = color;
    }

    /**
     * @brief Get the font used
     * @return The font used
     */
    Font RaylibText::getFont() const
    {
        return _font;
    }

    /**
     * @brief Get the text displayed
     * @return The text displayed
     */
    std::string RaylibText::getText() const
    {
        return _text;
    }

    /**
     * @brief Get the position of the text
     * @return The position of the text
     */
    Vector2 RaylibText::getPos() const
    {
        return _position;
    }

    /**
     * @brief Get the origin of the text
     * @return The origin of the text
     */
    Vector2 RaylibText::getOrigin() const
    {
        return _origin;
    }

    /**
     * @brief Get the font size of the text
     * @return The font size of the text
     */
    float RaylibText::getFontSize() const
    {
        return _fontSize;
    }

    /**
     * @brief Get the spacing between letters of the text
     * @return The spacing between letters of the text
     */
    float RaylibText::getSpacing() const
    {
        return _spacing;
    }

    /**
      * @brief Get the color of the text
      * @return The color of the text
      */
    Color RaylibText::getColor() const
    {
        return _color;
    }
}