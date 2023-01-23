/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** RaylibTexture.cpp
*/

#include "RaylibTexture.hpp"

namespace Raylib {

    /**
     * @brief Constructor of the RaylibTexture class
     * @param texturePath: Path of the texture to load
     * @return Instance of the RaylibTexture class
     */
    RaylibTexture::RaylibTexture(const std::string &texturePath) : _texture(LoadTexture(texturePath.c_str())),
                                                               _position({0, 0}), _rotation(0), _scale(1), _color(WHITE)
    {
    }

    /**
     * @brief Destructor of the RaylibTexture class
     */
    RaylibTexture::~RaylibTexture()
    {
        UnloadTexture(_texture);
    }

    /**
     * @brief Draw the texture
     * @return Nothing
     */
    void RaylibTexture::draw()
    {
        DrawTextureEx(_texture, _position, _rotation, _scale, _color);
    }

    /**
     * @brief Set the texture
     * @param texturePath: Path of the texture to load
     * @return Nothing
     */
    void RaylibTexture::setTexture(const std::string &texturePath)
    {
        UnloadTexture(_texture);
        _texture = LoadTexture(texturePath.c_str());
    }

    /**
     * @brief Set the position of the texture
     * @param position: Position of the texture
     * @return Nothing
     */
    void RaylibTexture::setPosition(Vector2 position)
    {
        _position = position;
    }

    /**
     * @brief Set the rotation of the texture
     * @param rotation: Rotation of the texture
     * @return Nothing
     */
    void RaylibTexture::setRotation(float rotation)
    {
        _rotation = rotation;
    }

    /**
     * @brief Set the scale of the texture
     * @param scale: Scale of the texture
     * @return Nothing
     */
    void RaylibTexture::setScale(float scale)
    {
        _scale = scale;
    }

    /**
     * @brief Set the color of the texture
     * @param color: Color of the texture
     * @return Nothing
     */
    void RaylibTexture::setColor(Color color)
    {
        _color = color;
    }

    /**
     * @brief Get the texture
     * @return Texture2D
     */
    Texture2D RaylibTexture::getTexture() const
    {
        return _texture;
    }

    /**
     * @brief Get the position of the texture
     * @return Vector2
     */
    Vector2 RaylibTexture::getPosition() const
    {
        return _position;
    }

    /**
     * @brief Get the rotation of the texture
     * @return float
     */
    float RaylibTexture::getRotation() const
    {
        return _rotation;
    }

    /**
     * @brief Get the scale of the texture
     * @return float
     */
    float RaylibTexture::getScale() const
    {
        return _scale;
    }

    /**
     * @brief Get the color of the texture
     * @return Color
     */
    Color RaylibTexture::getColor() const
    {
        return _color;
    }

}
