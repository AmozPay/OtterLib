/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** InitParallaxes
*/

#include "InitParallaxesClient.hpp"

namespace Otter::Games::GameClient::Init {
    InitParallaxes::InitParallaxes(Otter::Core::Orchestrator& ref, Otter::Core::Entity baseEntity)
    {
        Otter::Core::Entity parallaxes[3];

        for (unsigned int& parallax : parallaxes) {
            parallax = ref.createEntity();
        }

        auto& textureStorages = ref.get_components<Otter::Core::BaseComponents::TextureStorage>();

        for (unsigned int& parallax : parallaxes) {
            ref.add_component(parallax,
                              Otter::Core::BaseComponents::Texture(
                                  "../assets/parallax-1920x1080.png",
                                  textureStorages[baseEntity]->findTextureByPath("../assets/parallax-1920x1080.png"),
                                  Otter::Core::Utils::Rectangle(0, 0, 1920, 1080)));
            ref.add_component(parallax, Otter::Core::BaseComponents::Render());
            ref.add_component(parallax, Otter::Core::BaseComponents::Parallax());
        }

        for (int i = 0; i < 3; i++) {
            ref.add_component(parallaxes[i],
                              Otter::Core::BaseComponents::Transform(1, 0, {static_cast<float>(i * 1920), 0}));
            ref.add_component(parallaxes[i], Otter::Core::BaseComponents::Velocity(0, 5, {-1, 0}, {0, 0}));
        }
    }

    InitParallaxes::~InitParallaxes() {}
} // namespace Otter::Games::GameClient::Init
