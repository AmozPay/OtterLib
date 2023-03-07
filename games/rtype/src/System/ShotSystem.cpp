/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** ShotSystem
*/

#include "ShotSystem.hpp"
#include "baseComponents.hpp"
#include "Animation.hpp"
#include "AnimationComponent.hpp"

#include <chrono>

namespace Otter::Games::RType::System::Shot {

    namespace components = Otter::Games::RType::Components;
    namespace utils = Otter::Games::RType::Utils;

    void CreatePlayerShotEntity(Otter::Core::Orchestrator& ref, size_t playerIndex, auto const& transform, auto& texture,
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
                                       {transform->_position.x + (texture->_texture.getWidth() * transform->_scale),
                                        transform->_position.y}));

        ref.add_component(newShot, components::Shot(playerIndex));
        if (shooter->_direction == components::LEFT)
            ref.add_component(newShot, Otter::Core::BaseComponents::Velocity(0, 5, {-1, 0}, {0, 0}));
        if (shooter->_direction == components::RIGHT)
            ref.add_component(newShot, Otter::Core::BaseComponents::Velocity(0, 5, {1, 0}, {0, 0}));
        ref.add_component(newShot, components::Obstacle(components::ObstacleType::BULLET, "player_bullet"));
        ref.add_component(newShot, Otter::Core::BaseComponents::BoxCollider(48, 36));

        if (shooter->_shotNbr != -1)
            shooter->_shotNbr -= 1;
        shooter->_lastShotTimestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());;
    }

    void CreateEnemyShotEntity(Otter::Core::Orchestrator& ref, size_t enemyIndex, auto const& transform, auto& texture,
                          auto& shooter)
    {
        Otter::Core::Entity newShot = ref.createEntity();

#if defined(TARGET_CLIENT)
        auto& textureStorages = ref.get_components<Otter::Core::BaseComponents::TextureStorage>();

        for (size_t i = 0; i < textureStorages.size(); i++) {
            auto& textureStorage = textureStorages[i];

            if (textureStorage) {
                ref.add_component(newShot, Otter::Core::BaseComponents::Texture(
                                               "../assets/ennemyShoot2-16x16.png",
                                               textureStorage->findTextureByPath("../assets/ennemyShoot2-16x16.png"),
                                               Otter::Games::RType::Utils::Rectangle(0, 0, 16, 16)));
            }
        }
        ref.add_component(newShot, Otter::Core::BaseComponents::Render());
#endif
        ref.add_component(newShot, Otter::Core::BaseComponents::Transform(
                                       3, 0,
                                       {transform->_position.x - 48,
                                        transform->_position.y + 10}));

        ref.add_component(newShot, components::Shot(enemyIndex));
        if (shooter->_direction == components::LEFT)
            ref.add_component(newShot, Otter::Core::BaseComponents::Velocity(0, 7, {-1, 0}, {0, 0}));
        if (shooter->_direction == components::RIGHT)
            ref.add_component(newShot, Otter::Core::BaseComponents::Velocity(0, 7, {1, 0}, {0, 0}));
        ref.add_component(newShot, components::Obstacle(components::ObstacleType::BULLET, "enemy_bullet"));
        ref.add_component(newShot, Otter::Core::BaseComponents::BoxCollider(48, 48));

        utils::AnimRectVect animRectVect;
        animRectVect.push_back(utils::Rectangle(0, 0, 16, 16));
        animRectVect.push_back(utils::Rectangle(16, 0, 16, 16));
        animRectVect.push_back(utils::Rectangle(16 * 2, 0, 16, 16));
        animRectVect.push_back(utils::Rectangle(16 * 3, 0, 16, 16));
        utils::Animation anim("../assets/ennemyShoot2-16x16.png", animRectVect, 200);

        components::IdAnimMap idAnimMap;
        idAnimMap.emplace(components::STANDUP_ANIM, anim);

        ref.add_component(newShot, components::AnimationComponent(idAnimMap, components::STANDUP_ANIM));

        if (shooter->_shotNbr != -1)
            shooter->_shotNbr -= 1;
        shooter->_lastShotTimestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());;
    }

    void CreateShot(Otter::Core::Orchestrator& ref, size_t entityIndex, bool isEnemy)
    {
        auto const& transforms = ref.get_components<Otter::Core::BaseComponents::Transform>();
        auto& textures = ref.get_components<Otter::Core::BaseComponents::Texture>();
        auto& shooters = ref.get_components<components::Shooter>();

        if (entityIndex < transforms.size() && entityIndex < textures.size() && entityIndex < shooters.size()) {
            auto const& transform = transforms[entityIndex];
            auto& texture = textures[entityIndex];
            auto& shooter = shooters[entityIndex];

            if (transform && texture && shooter) {
                std::chrono::milliseconds now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
                if (shooter->_canShoot && (shooter->_shotNbr > 0 || shooter->_shotNbr == -1)) {
                    std::cout << now.count() << " " << shooter->_lastShotTimestamp.count() << std::endl;
                    if ((shooter->_reloadTime == -1 || (now.count() - shooter->_lastShotTimestamp.count()) > shooter->_reloadTime)) {
                        if (isEnemy)
                            CreateEnemyShotEntity(ref, entityIndex, transform, texture, shooter);
                        else
                            CreatePlayerShotEntity(ref, entityIndex, transform, texture, shooter);
                    }
                }
            }
        }
    }

}