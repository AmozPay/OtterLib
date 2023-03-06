/*
** EPITECH PROJECT, 2023
** RType
** File description:
** EnemyShotSystem.cpp
*/

#include "EnemyShotSystem.hpp"

#include "GameOverSystem.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::RType::System::EnemyShot {

    namespace core = Otter::Core;
    namespace components = Otter::Games::RType::Components;

    void CreateShotEntity(Otter::Core::Orchestrator& ref, size_t playerIndex, auto const& transform, auto& texture,
                          auto& shooter)
    {
        Otter::Core::Entity newShot = ref.createEntity();

#if defined(TARGET_CLIENT)
        auto& textureStorages = ref.get_components<Otter::Core::BaseComponents::TextureStorage>();

        for (size_t i = 0; i < textureStorages.size(); i++) {
            auto& textureStorage = textureStorages[i];

            if (textureStorage) {
                ref.add_component(newShot, Otter::Core::BaseComponents::Texture(
                                               "../assets/projectile.gif",
                                               textureStorage->findTextureByPath("../assets/projectile.gif"),
                                               Otter::Games::RType::Utils::Rectangle(0, 0, 16, 12)));
            }
        }
        ref.add_component(newShot, Otter::Core::BaseComponents::Render());
#endif
        ref.add_component(newShot, Otter::Core::BaseComponents::Transform(
                                       3, 0,
                                       {transform->_position.x - 48,
                                        transform->_position.y + 16}));

        ref.add_component(newShot, components::Shot(playerIndex));
        if (shooter->_direction == components::LEFT)
            ref.add_component(newShot, Otter::Core::BaseComponents::Velocity(0, 7, {-1, 0}, {0, 0}));
        if (shooter->_direction == components::RIGHT)
            ref.add_component(newShot, Otter::Core::BaseComponents::Velocity(0, 7, {1, 0}, {0, 0}));
        ref.add_component(newShot, components::Obstacle(components::ObstacleType::BULLET, "bullet"));
        ref.add_component(newShot, Otter::Core::BaseComponents::BoxCollider(48, 36));

        if (shooter->_shotNbr != -1)
            shooter->_shotNbr -= 1;
        shooter->_lastShotTimestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());;
    }

    void CreateShot(Otter::Core::Orchestrator& ref, size_t playerIndex)
    {
        auto const& transforms = ref.get_components<Otter::Core::BaseComponents::Transform>();
        auto& textures = ref.get_components<Otter::Core::BaseComponents::Texture>();
        auto& shooters = ref.get_components<components::Shooter>();

        if (playerIndex < transforms.size() && playerIndex < textures.size() && playerIndex < shooters.size()) {
            auto const& transform = transforms[playerIndex];
            auto& texture = textures[playerIndex];
            auto& shooter = shooters[playerIndex];

            if (transform && texture && shooter) {
                std::chrono::milliseconds now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
                if (shooter->_canShoot && (shooter->_shotNbr > 0 || shooter->_shotNbr == -1)) {
                    if ((shooter->_reloadTime == -1 || (now.count() - shooter->_lastShotTimestamp.count()) > shooter->_reloadTime))
                        CreateShotEntity(ref, playerIndex, transform, texture, shooter);
                }
            }
        }
    }

    void AutomaticShotForEntity(Otter::Core::Orchestrator& ref)
    {
        const auto& enemies = ref.get_components<core::BaseComponents::Enemy>();
        const auto& shooters = ref.get_components<components::Shooter>();
        const auto& transforms = ref.get_components<core::BaseComponents::Transform>();

        int num = 0;
        for (size_t i = 0; i < enemies.size() && i < shooters.size() && i < transforms.size(); i++) {
            const auto& enemy = enemies[i];
            const auto& shooter = shooters[i];
            const auto& transform = transforms[i];

            num = rand() % 20;
            if (enemy && shooter && num == 1 && transform && transform->_position.x < 1280) {
                CreateShot(ref, i);
            }
        }
    }

} // namespace Otter::Games::RType::System::EnemyShot