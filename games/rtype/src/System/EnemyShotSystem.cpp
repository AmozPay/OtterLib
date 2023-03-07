/*
** EPITECH PROJECT, 2023
** RType
** File description:
** EnemyShotSystem.cpp
*/

#include "EnemyShotSystem.hpp"
#include "ShotSystem.hpp"

#include "GameOverSystem.hpp"
#include "baseComponents.hpp"

namespace Otter::Games::RType::System::EnemyShot {

    namespace core = Otter::Core;
    namespace components = Otter::Games::RType::Components;

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
                Otter::Games::RType::System::Shot::CreateShot(ref, i, true);
            }
        }
    }

} // namespace Otter::Games::RType::System::EnemyShot