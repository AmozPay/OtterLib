/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Components.hpp
*/

#ifndef RTYPE_COMPONENTS_HPP
#define RTYPE_COMPONENTS_HPP

#include "OtterCore.hpp"
#include "OtterGraphic.hpp"
#include "Utils.hpp"

#include <chrono>
#include <memory>
#include <string>

namespace Otter::Games::RType::Components {

    /**
     * @brief Component for the rendering
     * @details The render component is used to render an entity
     * @struct Render
     */
    struct Render {};

    /**
     * @brief Component for the window
     * @details The window component is used to create & manage a window
     * @struct Window
     * @var width: The width of the window
     * @var height: The height of the window
     * @var title: The title of the window
     * @var fps: The target framerate of the window
     * @var window: An instance of the RaylibWindow class
     */
    struct Window {
        Window(int width, int height, const std::string& title, int fps)
            : _window(Otter::Graphic::Raylib::RaylibWindow(height, width, title))
        {
            _width = width;
            _height = height;
            _title = title;
            _fps = fps;
        };

        ~Window() = default;

        int _width;
        int _height;
        std::string _title;
        int _fps;
        Otter::Graphic::Raylib::RaylibWindow _window;
    };

    /**
     * @brief Component for the keyboard
     * @details The keyboard component is used to manage the keyboard events
     * @struct Keyboard
     * @var keyboard: An instance of the RaylibKeyboard class
     */
    struct Keyboard {
        Keyboard() : _keyboard(Otter::Graphic::Raylib::RaylibKeyboard(0)){};
        ~Keyboard() = default;

        Otter::Graphic::Raylib::RaylibKeyboard _keyboard;
    };

    /**
     * @brief Component for the box collider
     * @details The box collider component is used to store the size of the hitbox of an entity, in order to detect
     * collision
     * @struct BoxCollider
     * @var width: The width of the box collider rectangle
     * @var height: The height of the box collider rectangle
     */
    struct BoxCollider {
        BoxCollider(float width, float height)
        {
            _width = width;
            _height = height;
        }
        ~BoxCollider() = default;

        float _width;
        float _height;
    };

    /**
     * @brief Enum for the different status of a sound
     * @details The sound status is used to know if a sound is playing, paused or stopped
     * @enum SoundStatus
     * @var PLAYING: The sound is playing
     * @var PAUSED: The sound is paused
     * @var STOPPED: The sound is stopped
     */
    enum SoundStatus { PLAYING, PAUSED, STOPPED };

    /**
     * @brief Component for the sound
     * @details The sound component is different from the music component because music is looping
     * @struct Sound
     * @var path: The path to the sound
     * @var volume: The volume of the sound
     * @var status: The status of the sound
     */
    struct Sound {
        std::string path;
        float volume;
        SoundStatus status;
    };

    /**
     * @brief Component for the music
     * @details The music component is different from the sound component because music is looping
     * @struct Music
     * @var path: The path to the music
     * @var volume: The volume of the music
     * @var isLooping: If the music is looping
     * @var status: The status of the music
     */
    struct Music {
        std::string path;
        float volume;
        bool isLooping;
        SoundStatus status;
    };

    /**
     * @brief Component for the texture
     * @details The texture component is used to store the path to the texture and the texture itself
     * @struct Texture
     * @var path: The path to the texture
     * @var texture: An instance of the RaylibTexture class
     */
    struct Texture {
        Texture(const std::string& path, Otter::Graphic::Raylib::RaylibTexture texture) : _texture(texture)
        {
            _path = path;
        };

        ~Texture() = default;

        Texture& operator=(const Texture& other)
        {
            _path = other._path;
            _texture = other._texture;
            return *this;
        }

        std::string _path;
        Otter::Graphic::Raylib::RaylibTexture _texture;
    };

    /**
     * @brief Component transform
     * @details The transform component is used to store the position, rotation and scale of an entity
     * @struct Transform
     * @var position: A vector of float for the position of the entity
     * @var lastPosition: A vector of float for the last position of the entity
     * @var rotation: The rotation of the entity
     * @var scale: The scale of the entity
     */
    struct Transform {

        Transform(float scale, float rotation, Otter::Games::RType::Utils::Vector2 position)
            : _position(position), _lastPosition(position)
        {
            _scale = scale;
            _rotation = rotation;
        }

        ~Transform() = default;
        Otter::Games::RType::Utils::Vector2 _position;
        Otter::Games::RType::Utils::Vector2 _lastPosition;
        float _rotation;
        float _scale;
    };

    /**
     * @brief Component for the velocity
     * @details The velocity component is used to store the speed and acceleration of an entity
     * @struct Velocity
     * @var speed: The speed of the entity
     * @var accelerationDirection: A vector of float for the acceleration direction of the entity. The first value is
     * the x axis and the second value is the y axis. The value can be -1, 0 or 1. -1 is for the left or up, 0 is for
     * no acceleration and 1 is for the right or down
     */
    struct Velocity {
        Velocity(float speed, Otter::Games::RType::Utils::Vector2 accelerationDirection)
            : _accelerationDirection(accelerationDirection)
        {
            _speed = speed;
        };
        ~Velocity() = default;

        float _speed;
        Otter::Games::RType::Utils::Vector2 _accelerationDirection;
    };

    /**
     * @brief Component for the player
     * @details The player component is used to store the id and the tag of the player
     * @struct Player
     * @var id: The id of the player
     * @var tag: The tag of the player
     */
    struct Player {
        Player(int id, const std::string& tag)
        {
            _id = id;
            _tag = tag;
        };
        ~Player() = default;

        int _id;
        std::string _tag;
    };

    /**
     * @brief Component for the enemy
     * @details The enemy component is used to store the id and the tag of the enemy
     * @struct Enemy
     * @var id: The id of the enemy
     * @var tag: The tag of the enemy
     */
    struct Enemy {
        int id;
        std::string tag;
    };

    /**
     * @brief Enum for the different type of obstacle
     * @details The obstacle type is used to know if the obstacle is a wall, a bullet or a powerup
     * @enum ObstacleType
     * @var WALL: The obstacle is a wall
     * @var BULLET: The obstacle is a bullet
     * @var POWERUP: The obstacle is a powerup
     */
    enum ObstacleType { WALL, BULLET, POWERUP };

    /**
     * @brief Component for the Obstacle
     * @details The box collider component is used to store the type and the tag of the box
     * @struct Obstacle
     * @var type: The type of the box
     * @var tag: The tag of the box
     */
    struct Obstacle {
        ObstacleType type;
        std::string tag;
    };

    /**
     * @brief Component for the health
     * @details The health component is used to store the health point of an entity
     * @struct Health
     * @var hp: The health point of the entity
     */
    struct Health {
        explicit Health(unsigned int hp) { _hp = hp; };
        ~Health() = default;

        unsigned int _hp;
    };

    /**
     * @brief Component for the damage
     * @details The damage component is used to store the damage of an entity
     * @struct Damage
     * @var damage: The damage of the entity
     */
    struct Damage {
        unsigned int damage;
    };

    /**
     * @brief Component for the destructible
     * @details The destructible component is used to know if an entity is destructible. If it is, it will be destroyed
     * when it will have 0 hp
     * @struct Destructible
     * @var isDestructible: If the entity is destructible: true, otherwise: false
     */
    struct Destructible {
        bool isDestructible;
    };

    /**
     * @brief Enum for the shot direction
     * @details The shot direction is used to know if the shot is going to the left or to the right
     * @enum ShotDirection
     * @var LEFT: The shot is going to the left
     * @var RIGHT: The shot is going to the right
     */
    enum ShotDirection { LEFT, RIGHT };

    /**
     * @brief Component for the shooter
     * @details The shooter component is used to know if an entity is a shooter. If it is, it will be able to shoot
     * @struct Shooter
     * @var direction: The direction of the shot
     * @var canShoot: If the entity can shoot: true, otherwise: false
     * @var shotNbr: The number of shot, -1 if infinite
     * @var reloadTime: The reload time of the shot, -1 if infinite
     * @var lastShotTimestamp: The timestamp of the last shot
     */
    struct Shooter {
        ShotDirection direction;
        bool canShoot;
        int shotNbr;
        int reloadTime;
        std::time_t lastShotTimestamp;
    };

} // namespace Otter::Games::RType::Components

#endif // RTYPE_COMPONENTS_HPP