/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Components.hpp
*/

#ifndef RTYPE_COMPONENTS_HPP
#define RTYPE_COMPONENTS_HPP

#include "Utils.hpp"
#include "NetChannel.hpp"
#include "OtterCore.hpp"
#include "OtterGraphic.hpp"
#include "Class.hpp"
#include "Variable.hpp"

#include <boost/property_tree/ptree.hpp>
#include <chrono>
#include <memory>
#include <string>

namespace Otter::Games::RType::Components {
    namespace pt = boost::property_tree;

    Otter::Games::RType::Utils::Vector2 getVector2(pt::ptree json, std::string key);

    /**
     * @brief Component for the rendering
     * @details The render component is used to render an entity
     * You need to add the render component to an entity to be able to render it
     * @struct Render
     */
    struct Render {
        COMPONENT_BUILDER(Render) { core.add_component(e, Render()); }
        Render() = default;
        ~Render() = default;
    };

    /**
     * @brief Component for the window
     * @details The window component is used to create & manage a window
     * @struct Window
     * @var _width: The width of the window
     * @var _height: The height of the window
     * @var _title: The title of the window
     * @var _fps: The target framerate of the window
     * @var _window: An instance of the RaylibWindow class
     */
    struct Window {
        COMPONENT_BUILDER(Window)
        {
            core.add_component(e, Window(json.get<int>("width"), json.get<int>("height"),
                                         json.get<std::string>("title"), json.get<int>("fps")));
        }
        /**
         * @brief Constructor of the Window component
         * @param width: The width of the window
         * @param height: The height of the window
         * @param title: The title of the window
         * @param fps: The target framerate of the window
         */
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
     * @var _keyboard: An instance of the RaylibKeyboard class
     */
    struct Keyboard {

        COMPONENT_BUILDER(Keyboard) { core.add_component(e, Keyboard()); }
        /**
         * @brief Constructor of the Keyboard component
         */
        Keyboard() : _keyboard(Otter::Graphic::Raylib::RaylibKeyboard()){};
        ~Keyboard() = default;
        void setKey(Otter::Graphic::IKeyboard::KeyType raylibKey, const int& state) { _keyMap[raylibKey] = state; };
        void removeKey(Otter::Graphic::IKeyboard::KeyType raylibKey) { _keyMap.erase(raylibKey); };
        std::map<Otter::Graphic::IKeyboard::KeyType, int>::iterator begin() { return _keyMap.begin(); };
        std::map<Otter::Graphic::IKeyboard::KeyType, int>::iterator end() { return _keyMap.end(); };
 
        Otter::Graphic::Raylib::RaylibKeyboard _keyboard;
        std::map<Otter::Graphic::IKeyboard::KeyType, int> _keyMap;

    };

    /**
     * @brief Component for the box collider
     * @details The box collider component is used to store the size of the hitbox of an entity, in order to detect
     * collision
     * @struct BoxCollider
     * @var _width: The width of the box collider rectangle
     * @var _height: The height of the box collider rectangle
     */
    struct BoxCollider {
        COMPONENT_BUILDER(BoxCollider)
        {
            core.add_component(e, BoxCollider(json.get<float>("width"), json.get<float>("height")));
        }
        /**
         * @brief Constructor of the BoxCollider component
         * @param width: The width of the box collider rectangle
         * @param height: The height of the box collider rectangle
         */
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
     * @var _path: The path to the sound
     * @var _volume: The volume of the sound
     * @var _status: The status of the sound
     */
    struct Sound {
        COMPONENT_BUILDER(Sound)
        {
            auto str_to_enum = std::map<std::string, SoundStatus>();
            str_to_enum["PLAYING"] = PLAYING;
            str_to_enum["PAUSED"] = PAUSED;
            str_to_enum["STOPPED"] = STOPPED;

            core.add_component(e, Sound(json.get<std::string>("path"), json.get<float>("volume"),
                                        str_to_enum[json.get<std::string>("status")]));
        }
        /**
         * @brief Constructor of the Sound component
         * @param path: The path to the sound
         * @param volume: The volume of the sound
         * @param status: The status of the sound
         */
        Sound(const std::string& path, float volume, SoundStatus status)
        {
            _path = path;
            _volume = volume;
            _status = status;
        };
        ~Sound() = default;

        std::string _path;
        float _volume;
        SoundStatus _status;
    };

    /**
     * @brief Component for the music
     * @details The music component is different from the sound component because music is looping
     * @struct Music
     * @var _path: The path to the music
     * @var _volume: The volume of the music
     * @var _isLooping: If the music is looping
     * @var _status: The status of the music
     */
    struct Music {
        COMPONENT_BUILDER(Music)
        {
            auto str_to_enum = std::map<std::string, SoundStatus>();
            str_to_enum["PLAYING"] = PLAYING;
            str_to_enum["PAUSED"] = PAUSED;
            str_to_enum["STOPPED"] = STOPPED;

            core.add_component(e, Music(json.get<std::string>("path"), json.get<float>("volume"),
                                        json.get<bool>("isLooping"), str_to_enum[json.get<std::string>("status")]));
        }
        /**
         * @brief Constructor of the Music component
         * @param path: The path to the music
         * @param volume: The volume of the music
         * @param isLooping: If the music is looping
         * @param status: The status of the music
         */
        Music(const std::string& path, float volume, bool isLooping, SoundStatus status)
        {
            _path = path;
            _volume = volume;
            _isLooping = isLooping;
            _status = status;
        }
        ~Music() = default;

        std::string _path;
        float _volume;
        bool _isLooping;
        SoundStatus _status;
    };

    /**
     * @brief Component for the texture
     * @details The texture component is used to store the path to the texture and the texture itself
     * @struct Texture
     * @var _path: The path to the texture
     * @var _texture: An instance of the RaylibTexture class
     */
    struct Texture {
        COMPONENT_BUILDER(Texture)
        {
#if defined(TARGET_CLIENT)
            std::cout << "init texture" << std::endl;
            auto path = json.get<std::string>("path");
            std::cout << "init texture 2" << std::endl;
            core.add_component(e, Texture(path, Otter::Graphic::Raylib::RaylibTexture(path)));
            std::cout << "init texture 3" << std::endl;
#endif
        }

        /**
         * @brief Constructor of the Texture component
         * @param path: The path to the texture
         * @param texture: An instance of the RaylibTexture class
         */
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
     * @var _position: A vector of float for the position of the entity
     * @var _lastPosition: A vector of float for the last position of the entity
     * @var _rotation: The rotation of the entity
     * @var _scale: The scale of the entity
     */
    struct Transform {
        COMPONENT_BUILDER(Transform)
        {
            auto scale = json.get<float>("scale");
            auto rotation = json.get<float>("rotation");
            core.add_component(e, Transform(scale, rotation, getVector2(json, "position")));
        }

        /**
         * @brief Constructor of the Transform component
         * @param scale: The scale of the entity
         * @param rotation: The rotation of the entity
         * @param position: A vector of float for the position of the entity
         */
        Transform(float scale, float rotation, Otter::Games::RType::Utils::Vector2 position)
            : _position(position), _lastPosition(position)
        {
            _position = position;                                                                                      \
            this->setNewNetworkableVariable<Otter::Games::RType::Utils::Vector2>("couille", _position);
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
     * @var _speed: The speed of the entity
     * @var _constantSpeed: The constant speed of the entity
     * @var _accelerationDirection: A vector of float for the acceleration direction of the entity. The first value is
     * the x axis and the second value is the y axis. The value can be -1, 0 or 1. -1 is for the left or up, 0 is for
     * no acceleration and 1 is for the right or down
     * @var _constantAccelerationDirection: A vector of float for the constant acceleration direction of the entity.
     * Same as the accelerationDirection
     * @var _constantAccelerationDirection: A vector of float for the constant acceleration direction of the entity. Same
     * as the accelerationDirection
     */
    struct Velocity {
        COMPONENT_BUILDER(Velocity)
        {
            auto speed = json.get<float>("speed");
            //            core.add_component(e, Velocity(speed, getVector2(json, "accelerationDirection")));
            // TODO: Add constantAccelerationDirection
        }

        /**
         * @brief Constructor of the Velocity componen
         * @param speed: The speed of the entity
         * @param constantSpeed: The constant speed of the entity
         * @param constantAccelerationDirection: A vector of float for the constant acceleration direction of the entity
         * @param accelerationDirection: A vector of float for the acceleration direction of the entity
         */
        Velocity(float speed, float constantSpeed, Otter::Games::RType::Utils::Vector2 constantAccelerationDirection,
                 Otter::Games::RType::Utils::Vector2 accelerationDirection)
            : _accelerationDirection(accelerationDirection),
              _constantAccelerationDirection(constantAccelerationDirection)
        {
            _speed = speed;
            _constantSpeed = constantSpeed;
        };

        ~Velocity() = default;

        float _speed;
        float _constantSpeed;
        Otter::Games::RType::Utils::Vector2 _constantAccelerationDirection;
        Otter::Games::RType::Utils::Vector2 _accelerationDirection;
    };

    /**
     * @brief Component for the player
     * @details The player component is used to store the id and the tag of the player
     * @struct Player
     * @var _id: The id of the player
     * @var _tag: The tag of the player
     */
    struct Player {
        COMPONENT_BUILDER(Player)
        {
            int id = json.get<int>("id");
            auto tag = json.get<std::string>("tag");
            core.add_component(e, Player(id, tag));
        }
        /**
         * @brief Constructor of the Player component
         * @param id: The id of the player
         * @param tag: The tag of the player
         */
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
     * @var _id: The id of the enemy
     * @var _tag: The tag of the enemy
     */
    struct Enemy {
        COMPONENT_BUILDER(Enemy)
        {
            int id = json.get<int>("id");
            auto tag = json.get<std::string>("tag");
            core.add_component(e, Enemy(id, tag));
        }
        /**
         * @brief Constructor of the Enemy component
         * @param id: The id of the enemy
         * @param tag: The tag of the enemy
         */
        Enemy(int id, const std::string& tag)
        {
            _id = id;
            _tag = tag;
        }
        ~Enemy() = default;

        int _id;
        std::string _tag;
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
     * @var _type: The type of the obstacl
     * @var _tag: The tag of the obstacle
     */
    struct Obstacle {
        COMPONENT_BUILDER(Obstacle)
        {
            auto str_to_enum = std::map<std::string, ObstacleType>();
            str_to_enum["WALL"] = WALL;
            str_to_enum["BULLET"] = BULLET;
            str_to_enum["POWERUP"] = POWERUP;

            core.add_component(e, Obstacle(str_to_enum[json.get<std::string>("type")], json.get<std::string>("tag")));
        }
        /**
         * @brief Constructor of the Obstacle component
         * @param type: The type of the obstacle
         * @param tag: The tag of the obstacle
         */
        Obstacle(ObstacleType type, std::string tag)
        {
            _type = type;
            _tag = tag;
        };

        ~Obstacle() = default;

        ObstacleType _type;
        std::string _tag;
    };

    /**
     * @brief Component for the health
     * @details The health component is used to store the health point of an entity
     * @struct Health
     * @var _hp: The health point of the entity
     */
    struct Health {
        COMPONENT_BUILDER(Health) { core.add_component(e, Health(json.get<unsigned int>("hp"))); }
        /**
         * @brief Constructor of the Health component
         * @param hp: The health point of the entity
         */
        explicit Health(unsigned int hp) { _hp = hp; };

        ~Health() = default;

        unsigned int _hp;
    };

    /**
     * @brief Component for the damage
     * @details The damage component is used to store the damage of an entity
     * @struct Damage
     * @var _damage: The damage of the entity
     */
    struct Damage {
        COMPONENT_BUILDER(Damage) { core.add_component(e, Damage(json.get<unsigned int>("damage"))); }
        /**
         * @brief Constructor of the Damage component
         * @param damage: The damage of the entity
         */
        Damage(unsigned int damage) { _damage = damage; }
        ~Damage() = default;

        unsigned int _damage;
    };

    /**
     * @brief Component for the destructible
     * @details The destructible component is used to know if an entity is destructible. If it is, it will be destroyed
     * when it will have 0 hp
     * @struct Destructible
     * @var _isDestructible: If the entity is destructible: true, otherwise: false
     */
    struct Destructible {
        COMPONENT_BUILDER(Destructible) { core.add_component(e, Destructible(json.get<bool>("isDestructible"))); }
        /**
         * @brief Constructor of the Destructible component
         * @param isDestructible: If the entity is destructible: true, otherwise: false
         */
        Destructible(bool isDestructible) { _isDestructible = isDestructible; }
        ~Destructible() = default;

        bool _isDestructible;
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
     * @var _direction: The direction of the shot
     * @var _canShoot: If the entity can shoot: true, otherwise: false
     * @var _shotNbr: The number of shot, -1 if infinite
     * @var _reloadTime: The reload time of the shot, -1 if infinite
     * @var _lastShotTimestamp: The timestamp of the last shot
     */
    struct Shooter {
        COMPONENT_BUILDER(Shooter)
        {
            auto str_to_enum = std::map<std::string, ShotDirection>();
            str_to_enum["LEFT"] = LEFT;
            str_to_enum["RIGHT"] = RIGHT;
            core.add_component(e, Shooter(str_to_enum[json.get<std::string>("direction")], json.get<bool>("canShoot"),
                                          json.get<int>("shotNbr"), json.get<int>("reloadTime")));
        }
        /**
         * @brief Constructor of the Shooter component
         * @param direction: The direction of the shot
         * @param canShoot: If the entity can shoot: true, otherwise: false
         * @param shotNbr: The number of shot, -1 if infinite
         * @param reloadTime: The reload time of the shot, -1 if infinite
         */
        Shooter(ShotDirection direction, bool canShoot, int shotNbr, int reloadTime)
        {
            _direction = direction;
            _canShoot = canShoot;
            _shotNbr = shotNbr;
            _reloadTime = reloadTime;
            _lastShotTimestamp = 0;
        }

        ~Shooter() = default;

        ShotDirection _direction;
        bool _canShoot;
        int _shotNbr;
        int _reloadTime;
        std::time_t _lastShotTimestamp;
    };

    /**
     * @brief Component for the shot
     * @details The shot component is used to know if an entity is a shot. If it is, it will be able to act as a shot
     * @struct Shot
     * @var _shooterId: The id of the shooter
     */
    struct Shot {
        COMPONENT_BUILDER(Shot) { core.add_component(e, Shot(json.get<int>("shooterId"))); }
        /**
         * @brief Constructor of the Shot component
         * @param shooterId: The id of the shooter
         */
        explicit Shot(int shooterId) { _shooterId = shooterId; };

        ~Shot() = default;

        int _shooterId;
    };

    /**
     * @brief Component for the dispawnable
     * @details The dispawnable component is used to know if an entity is dispawnable. If it is, it will be destroyed
     * You need to add the component to the entity to be able to dispawn it
     * @struct Render
     */
    struct Dispawnable {
        COMPONENT_BUILDER(Dispawnable) { core.add_component(e, Dispawnable()); }
        Dispawnable() = default;
        ~Dispawnable() = default;
    };

    /**
     * @brief Component for the parallax
     * @details The parallax component is used to know if an entity is a parallax. If it is, it will be able to act as a
     * parallax
     * @struct Parallax
     */
    struct Parallax {
        COMPONENT_BUILDER(Parallax) { core.add_component(e, Parallax()); }
        Parallax() = default;
        ~Parallax() = default;
    };

    /**
     * @brief Component for the network
     */
    struct EventNetwork {
        COMPONENT_BUILDER(EventNetwork) { core.add_component(e, EventNetwork()); }
        EventNetwork() { _data = -1; }

        ~EventNetwork() = default;

        int _data;
    };
} // namespace Otter::Games::RType::Components

#endif // RTYPE_COMPONENTS_HPP
