/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitEnemy
*/

#include "InitEnemyClient.hpp"

namespace Otter::Games::GameClient::Init {
    
    InitEnemy::InitEnemy(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                         Otter::Games::RType::Utils::Vector2 pos)
    {
        // srand(42);
        int enemyType = rand() % 2;

        if (enemyType == 1)
            InitBasicEnemy(ref, baseEntity, id, pos);
        else
            InitShootingEnemy(ref, baseEntity, id, pos);
    }

    void InitEnemy::InitShootingEnemy(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                         Otter::Games::RType::Utils::Vector2 pos)
    {
        Otter::Core::Entity enemy = ref.createEntity();
        Otter::Core::Entity enemyHealth = ref.createEntity();

        auto& textureStorages = ref.get_components<Otter::Core::BaseComponents::TextureStorage>();
        ref.add_component(enemy, Otter::Core::BaseComponents::Texture(
                                     "../assets/enemy1-34x34.png",
                                     textureStorages[baseEntity]->findTextureByPath("../assets/enemy1-34x34.png"),
                                     Otter::Games::RType::Utils::Rectangle(0, 0, 34, 34)));
        ref.add_component(enemy, Otter::Core::BaseComponents::Render());
        ref.add_component(enemy, Otter::Core::BaseComponents::Transform(2, 0, {pos.x, pos.y}));
        ref.add_component(enemy, Otter::Core::BaseComponents::Velocity(2, 2, {-1, 0}, {0, 0}));
        ref.add_component(enemy, Otter::Core::BaseComponents::Enemy(25, id));
        ref.add_component(enemy, Otter::Core::BaseComponents::BoxCollider(68, 68));
        ref.add_component(enemy, Otter::Core::BaseComponents::Damage(10));
        ref.add_component(enemy, Otter::Core::BaseComponents::Health(10));

        ref.add_component(enemy, components::Shooter(components::ShotDirection::LEFT, true, -1, 2000));

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

        // Enemy health text
        ref.add_component(enemyHealth, Otter::Core::BaseComponents::Text("", 16, "health", enemy));
        ref.add_component(enemyHealth, Otter::Core::BaseComponents::Transform(1, 0, {0, 0}));
    }

    void InitEnemy::InitBasicEnemy(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity, std::string id,
                         Otter::Games::RType::Utils::Vector2 pos)
    {
        Otter::Core::Entity enemy = ref.createEntity();
        Otter::Core::Entity enemyHealth = ref.createEntity();

        auto& textureStorages = ref.get_components<Otter::Core::BaseComponents::TextureStorage>();
        ref.add_component(enemy, Otter::Core::BaseComponents::Texture(
                                     "../assets/enemy2-29x22.png",
                                     textureStorages[baseEntity]->findTextureByPath("../assets/enemy2-29x22.png"),
                                     Otter::Games::RType::Utils::Rectangle(0, 0, 29, 22)));
        ref.add_component(enemy, Otter::Core::BaseComponents::Render());
        ref.add_component(enemy, Otter::Core::BaseComponents::Transform(2, 0, {pos.x, pos.y}));
        ref.add_component(enemy, Otter::Core::BaseComponents::Velocity(2, 2, {-1, 0}, {0, 0}));
        ref.add_component(enemy, Otter::Core::BaseComponents::Enemy(25, id));
        ref.add_component(enemy, Otter::Core::BaseComponents::BoxCollider(58, 44));
        ref.add_component(enemy, Otter::Core::BaseComponents::Damage(10));
        ref.add_component(enemy, Otter::Core::BaseComponents::Health(20));

        utils::AnimRectVect animRectVect;
        animRectVect.push_back(utils::Rectangle(0, 0, 29, 22));
        animRectVect.push_back(utils::Rectangle(29, 0, 29, 22));
        animRectVect.push_back(utils::Rectangle(29 * 2, 0, 29, 22));
        animRectVect.push_back(utils::Rectangle(29 * 3, 0, 29, 22));
        animRectVect.push_back(utils::Rectangle(29 * 4, 0, 29, 22));
        animRectVect.push_back(utils::Rectangle(29 * 5, 0, 29, 22));
        utils::Animation anim("../assets/enemy2-29x22.png", animRectVect, 200);
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

        // Enemy health text
        ref.add_component(enemyHealth, Otter::Core::BaseComponents::Text("", 16, "health", enemy));
        ref.add_component(enemyHealth, Otter::Core::BaseComponents::Transform(1, 0, {0, 0}));
    }

    InitEnemy::~InitEnemy() {}
} // namespace Otter::Games::GameClient::Init
