/*
** EPITECH PROJECT, 2023
** RType
** File description:
** EventNetworkSystem.cpp
*/

#include "EventNetworkSystem.hpp"

#include "Components.hpp"

namespace Otter::Games::RType::System::EventNetwork {
    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;
    namespace raylib = Otter::Graphic::Raylib;

    void PlayerMovementEvent(Otter::Core::Orchestrator& ref, size_t playerIndex, utils::EventState state)
    {
        auto& velocities = ref.get_components<components::Velocity>();
        if (playerIndex < velocities.size() && velocities[playerIndex]) {
            auto& velocity = velocities[playerIndex];
            if (state == utils::EventState::BACKWARD)
                velocity->_accelerationDirection.x += -1;
            if (state == utils::EventState::FORWARD)
                velocity->_accelerationDirection.x += 1;
            if (state == utils::EventState::UP)
                velocity->_accelerationDirection.y += -1;
            if (state == utils::EventState::DOWN)
                velocity->_accelerationDirection.y += 1;
        }
    }

    void CreateShotEntity(Otter::Core::Orchestrator& ref, size_t playerIndex, auto const& transform, auto& texture,
                          auto& shooter)
    {
        Otter::Core::Entity newShot = ref.createEntity();

#if defined(TARGET_CLIENT)
        auto& textureStorages = ref.get_components<components::TextureStorage>();

        for (size_t i = 0; i < textureStorages.size(); i++) {
            auto& textureStorage = textureStorages[i];

            if (textureStorage) {
                ref.add_component(newShot,
                                  components::Texture("../assets/projectile.gif",
                                                      textureStorage->findTextureByPath("../assets/projectile.gif"),
                                                      Otter::Games::RType::Utils::Rectangle(0, 0, 16, 12)));
            }
        }
        ref.add_component(newShot, components::Render());
#endif
        ref.add_component(
            newShot, components::Transform(3, 0,
                                           {transform->_position.x + (texture->_texture.getWidth() * transform->_scale),
                                            transform->_position.y}));

        ref.add_component(newShot, components::Shot(playerIndex));
        if (shooter->_direction == components::LEFT)
            ref.add_component(newShot, components::Velocity(0, 5, {-1, 0}, {0, 0}));
        if (shooter->_direction == components::RIGHT)
            ref.add_component(newShot, components::Velocity(0, 5, {1, 0}, {0, 0}));
        ref.add_component(newShot, components::Obstacle(components::ObstacleType::BULLET, "bullet"));
        ref.add_component(newShot, components::BoxCollider(48, 36));

        if (shooter->_shotNbr != -1)
            shooter->_shotNbr -= 1;
        shooter->_lastShotTimestamp = std::time(nullptr);
    }

    void CreateShot(Otter::Core::Orchestrator& ref, size_t playerIndex)
    {
        auto const& transforms = ref.get_components<components::Transform>();
        auto& textures = ref.get_components<components::Texture>();
        auto& shooters = ref.get_components<components::Shooter>();

        if (playerIndex < transforms.size() && playerIndex < textures.size() && playerIndex < shooters.size()) {
            auto const& transform = transforms[playerIndex];
            auto& texture = textures[playerIndex];
            auto& shooter = shooters[playerIndex];

            if (transform && texture && shooter) {
                std::time_t now = std::time(nullptr);
                if (shooter->_canShoot && (shooter->_shotNbr > 0 || shooter->_shotNbr == -1) &&
                    (shooter->_reloadTime == -1 || (now - shooter->_lastShotTimestamp) > shooter->_reloadTime)) {
                    CreateShotEntity(ref, playerIndex, transform, texture, shooter);
                }
            }
        }
    }

    void EventDetection(Otter::Core::Orchestrator& ref, size_t playerIndex, utils::EventState state)
    {
        PlayerMovementEvent(ref, playerIndex, state);
        if (state == utils::SHOOT)
            CreateShot(ref, playerIndex);
        if (state == utils::CLOSE) {
            // DO NOTHING FOR THE MOMENT
        }
    }

    void EventHandler(Otter::Core::Orchestrator& ref)
    {
        auto const& players = ref.get_components<components::Player>();
        auto& eventNetworks = ref.get_components<components::EventNetwork>();

        for (size_t i = 0; i < eventNetworks.size() && i < players.size(); i++) {
            auto& eventNetwork = eventNetworks[i];
            auto const& player = players[i];

            if (player && eventNetwork)
                EventDetection(ref, i, static_cast<utils::EventState>(eventNetwork->_data));
            eventNetwork->_data = -1;
        }
    }

} // namespace Otter::Games::RType::System::EventNetwork