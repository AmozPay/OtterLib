/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitPlayer
*/

#include "InitPlayer.hpp"

namespace Otter::Games::GameClient::Init {
    InitPlayer::InitPlayer(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity)
    {
        Otter::Core::Entity player = ref.createEntity();

        std::cout << "Player id = " << std::to_string(player) << std::endl;

        auto& textureStorages = ref.get_components<Otter::Core::BaseComponents::TextureStorage>();

        ref.add_component(player, Otter::Core::BaseComponents::Texture(
                                      "../assets/spaceship.gif",
                                      textureStorages[baseEntity]->findTextureByPath("../assets/spaceship.gif"),
                                      Otter::Games::RType::Utils::Rectangle(0, 0, 32, 14)));
        ref.add_component(player, Otter::Core::BaseComponents::Render());
        ref.add_component(player, Otter::Core::BaseComponents::Keyboard());
        ref.add_component(player, Otter::Core::BaseComponents::EventNetwork());
        ref.add_component(player, Otter::Core::BaseComponents::Transform(3, 0, {200, 200}));
        ref.add_component(player, Otter::Core::BaseComponents::Player(20, "test"));
        ref.add_component(player, Otter::Core::BaseComponents::Velocity(5, 0, {1, 10}, {1, 1}));
        ref.add_component(player, Otter::Core::BaseComponents::BoxCollider(96, 42));
        ref.add_component(player, Otter::Core::BaseComponents::Health(100));
        ref.add_component(player, components::Shooter(components::ShotDirection::RIGHT, true, -1, 0.001));
        ref.add_component(player, Otter::Core::BaseComponents::Damage(10));

        auto& keyboards = ref.get_components<Otter::Core::BaseComponents::Keyboard>();

        keyboards[player]->setKey(keyboards[player]->_keyboard.LEFT, utils::EventState::BACKWARD);
        keyboards[player]->setKey(keyboards[player]->_keyboard.RIGHT, utils::EventState::FORWARD);
        keyboards[player]->setKey(keyboards[player]->_keyboard.UP, utils::EventState::UP);
        keyboards[player]->setKey(keyboards[player]->_keyboard.DOWN, utils::EventState::DOWN);
        keyboards[player]->setKey(keyboards[player]->_keyboard.SHIFT, utils::EventState::SHOOT);
    }

    InitPlayer::~InitPlayer() {}
} // namespace Otter::Games::GameClient::Init
