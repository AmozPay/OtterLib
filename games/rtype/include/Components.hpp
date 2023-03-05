/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Components.hpp
*/

#ifndef RTYPE_COMPONENTS_HPP
#define RTYPE_COMPONENTS_HPP

#include "EventComponent.hpp"
#include "OtterCore.hpp"
#include "OtterGraphic.hpp"
#include "Utils.hpp"

#include <boost/property_tree/ptree.hpp>
#include <chrono>
#include <memory>
#include <string>

namespace Otter::Games::RType::Components {
    namespace pt = boost::property_tree;
    namespace utils = Otter::Games::RType::Utils;

    utils::Vector2 getVector2(pt::ptree json, std::string key);

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

        ~Obstacle(){};

        ObstacleType _type;
        std::string _tag;
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
        Shooter(ShotDirection direction, bool canShoot, int shotNbr, double reloadTime)
        {
            _direction = direction;
            _canShoot = canShoot;
            _shotNbr = shotNbr;
            _reloadTime = reloadTime;
            _lastShotTimestamp = 0;
        }

        ~Shooter(){};

        ShotDirection _direction;
        bool _canShoot;
        int _shotNbr;
        double _reloadTime;
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

        ~Shot(){};

        int _shooterId;
    };

    /**
     * @brief Enum for the power up type
     * @details The power up type is used to know what the power up is doing
     * @enum PowerUpType
     * @var HEALTH: The power up is modifying the health
     * @var DAMAGE: The power up is modifying the damage
     */
    enum PowerUpType { HEALTH, DAMAGE };

    /**
     * @brief Component for the power up
     * @details The power up component is used to know if an entity is a power up. If it is, it will be able to act as a
     * power up
     * @struct PowerUp
     * @var _powerUpId: The id of the power up
     * @var _type: The type of the power up
     * @var _value: The value of the power up (can be negative)
     */
    struct PowerUp {
        PowerUp(int powerUpId, PowerUpType type, int value)
        {
            _powerUpId = powerUpId;
            _type = type;
            _value = value;
        }
        ~PowerUp() = default;

        int _powerUpId;
        PowerUpType _type;
        int _value;
    };
} // namespace Otter::Games::RType::Components

#endif // RTYPE_COMPONENTS_HPP