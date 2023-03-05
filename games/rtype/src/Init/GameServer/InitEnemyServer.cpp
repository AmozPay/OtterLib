/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitEnemy
*/

#include "InitEnemyServer.hpp"


namespace Otter::Games::GameServer::Init
{
    InitEnemy::InitEnemy(
        Otter::Core::Orchestrator& ref,
        Otter::Core::Entity baseEntity,
        std::string id,
        Otter::Games::RType::Utils::Vector2 pos
    )
    {

        Otter::Core::Entity enemy = ref.createEntity();

        auto& textureStorages = ref.get_components<Otter::Core::BaseComponents::TextureStorage>();
        ref.add_component(enemy,
                          Otter::Core::BaseComponents::Texture("../assets/enemy1-34x34.png",
                                              textureStorages[baseEntity]->findTextureByPath("../assets/enemy1-34x34.png"),
                                              Otter::Games::RType::Utils::Rectangle(0, 0, 34, 34)));
        ref.add_component(enemy, Otter::Core::BaseComponents::Render());
        ref.add_component(enemy, Otter::Core::BaseComponents::Transform(2, 0, {pos.x, pos.y}));
        ref.add_component(enemy, Otter::Core::BaseComponents::Velocity(2, 2, {-1, 0}, {0, 0}));
        ref.add_component(enemy, Otter::Core::BaseComponents::Enemy(25, id));
        ref.add_component(enemy, Otter::Core::BaseComponents::BoxCollider(34, 34));
        ref.add_component(enemy, Otter::Core::BaseComponents::Damage(20));
        ref.add_component(enemy, Otter::Core::BaseComponents::Health(10));

        utils::AnimRectVect animRectVect;
        animRectVect.push_back(utils::Rectangle(0, 0, 34, 34));
        animRectVect.push_back(utils::Rectangle(34, 0, 34, 34));
        animRectVect.push_back(utils::Rectangle(34 * 2, 0, 34, 34));
        animRectVect.push_back(utils::Rectangle(34 * 3, 0, 34, 34));
        utils::Animation anim("../assets/enemy1-34x34.png", animRectVect, 200);
        utils::AnimRectVect animRectVect2;
        animRectVect2.push_back(utils::Rectangle(0, 26 * 2, 28, 28));
        animRectVect2.push_back(utils::Rectangle(30, 26 * 2, 28, 28));
        animRectVect2.push_back(utils::Rectangle(62, 26 * 2, 28, 28));
        animRectVect2.push_back(utils::Rectangle(96, 26 * 2, 33, 36));
        animRectVect2.push_back(utils::Rectangle(132, 26 * 2, 33, 36));
        animRectVect2.push_back(utils::Rectangle(166, 26 * 2, 33, 36));
        utils::Animation anim2("../assets/r-typesheet43.gif", animRectVect2, 100, true);
        components::IdAnimMap idAnimMap;
        idAnimMap.emplace(components::STANDUP_ANIM, anim);
        idAnimMap.emplace(components::DEATH_ANIM, anim2);
        ref.add_component(enemy, components::AnimationComponent(idAnimMap, components::STANDUP_ANIM));
    }

    InitEnemy::~InitEnemy()
    {

    }
}
