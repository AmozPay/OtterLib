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
     * @brief Enum for the powerup type
     * @details The powerup type is used to know what the powerup is going to do
     * @enum PowerupType
     * @var HEALTH: The powerup is going to heal the entity who picked it up (HP ++)
     * @var DAMAGE: The powerup is going to apply damage to the entity who picked it up (HP --)
     * @var STRENGTH: The powerup is going to increase the attack of the entity who picked it up (Attack ++)
     * @var WEAKNESS: The powerup is going to decrease the attack of the entity who picked it up (Attack --)
     * @var SPEED: The powerup is going to increase the speed of the entity who picked it up (Speed ++)
     * @var SLOWNESS: The powerup is going to decrease the speed of the entity who picked it up (Speed --)
    */
    enum PowerupType { HEALTH, DAMAGE, STRENGTH, WEAKNESS, SPEED, SLOWNESS };

    struct Powerup {
        /**
         * @brief Constructor of the Powerup component
         * @param type: The type of the powerup
         * @param value: The value of the powerup
        */
        Powerup(PowerupType type, int value) {
            _type = type;
            _value = value;
        }
        ~Powerup(){};

        PowerupType _type;
        int _value;
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
     * @var _reloadTime: The reload time of the shot, -1 if infinite (in ms)
     * @var _lastShotTimestamp: The timestamp of the last shot (in ms)
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
         * @param reloadTime: The reload time of the shot, -1 if infinite (in ms)
         */
        Shooter(ShotDirection direction, bool canShoot, int shotNbr, double reloadTime)
        {
            _direction = direction;
            _canShoot = canShoot;
            _shotNbr = shotNbr;
            _reloadTime = reloadTime;
            _lastShotTimestamp = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch());
        }

        ~Shooter(){};

        ShotDirection _direction;
        bool _canShoot;
        int _shotNbr;
        double _reloadTime;
        std::chrono::milliseconds _lastShotTimestamp;
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

} // namespace Otter::Games::RType::Components

#endif // RTYPE_COMPONENTS_HPP