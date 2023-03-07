/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitGameSystem
*/

#include "InitLobbySystem.hpp"

#include "InitEnemyClient.hpp"
#include "InitInvisibleWallClient.hpp"
#include "InitMobsClient.hpp"
#include "InitObstacleClient.hpp"
#include "InitParallaxesClient.hpp"
#include "InitPlayerClient.hpp"

namespace Otter::Games::RType::System::InitLobby {

    void InitLobby(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity)
    {
        Otter::Core::Entity menu = ref.createEntity();
        auto& textureStorages = ref.get_components<Otter::Core::BaseComponents::TextureStorage>();


        ref.add_component(menu, Otter::Core::BaseComponents::Texture(
                                     "../assets/menu.png",
                                     textureStorages[baseEntity]->findTextureByPath("../assets/menu.png"),
                                     Otter::Games::RType::Utils::Rectangle(0, 0, 1280, 720)));
        ref.add_component(menu, Otter::Core::BaseComponents::Render());
        ref.add_component(menu, Otter::Core::BaseComponents::Transform(1, 0, {0, 0}));
        ref.add_component(menu, Otter::Games::RType::Components::Menu());
    }

    void HandleInitLobby(Otter::Core::Orchestrator& ref, std::vector<std::size_t>&)
    {
        auto& gameStatuses = ref.get_components<Otter::Core::BaseComponents::GameStatus>();

        for (std::size_t i = 0; i < gameStatuses.size(); i++) {
            if (!gameStatuses[i]) {
                continue;
            }

            InitLobby(ref, static_cast<Otter::Core::Entity>(i));
            gameStatuses[i]->gameStatusType = Otter::Core::BaseComponents::LOBBY;
            return;
        }
    }
} // namespace Otter::Games::RType::System::InitGame
