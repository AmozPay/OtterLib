/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** RaylibTexture.cpp
*/

#include "RaylibTexture.hpp"

/**
 * @brief The namespace of the Otter Graphic library for Raylib
 */
namespace Otter::Graphic::Raylib {

    /**
     * @brief Constructor of the RaylibTexture class
     * @param texturePath: Path of the texture to load
     * @return Instance of the RaylibTexture class
     */
    RaylibTexture::RaylibTexture(const std::string& texturePath)
        : _texture(LoadTexture(texturePath.c_str())), _color(WHITE)
    {
    }

    /**
     * @brief Destructor of the RaylibTexture class
     */
    RaylibTexture::~RaylibTexture() = default;

    //    RaylibTexture::~RaylibTexture() { UnloadTexture(_texture); }

    /**
     * @brief Draw the texture
     * @return Nothing
     */
    void RaylibTexture::draw(Rectangle source, Vector2 position, float rotation, float scale)
    {
        Rectangle dest = {position.x, position.y, source.width * scale, source.height * scale};
        Vector2 origin = {0.0f, 0.0f};

        DrawTextureTiled(_texture, source, dest, origin, rotation, scale, _color);
    }

    /**
     * @brief Set the texture
     * @param texturePath: Path of the texture to load
     * @return Nothing
     */
    void RaylibTexture::setTexture(const std::string& texturePath)
    {
        UnloadTexture(_texture);
        _texture = LoadTexture(texturePath.c_str());
    }

    /**
     * @brief Set the color of the texture
     * @param color: Color of the texture
     * @return Nothing
     */
    void RaylibTexture::setColor(Color color) { _color = color; }

    /**
     * @brief Get the texture
     * @return Texture2D
     */
    Texture2D RaylibTexture::getTexture() const { return _texture; }

    /**
     * @brief Get the color of the texture
     * @return Color
     */
    Color RaylibTexture::getColor() const { return _color; }

    int RaylibTexture::getWidth() const { return _texture.width; }

    int RaylibTexture::getHeight() const { return _texture.height; }

} // namespace Otter::Graphic::Raylib
