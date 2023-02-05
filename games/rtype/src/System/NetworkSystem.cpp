/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** NetworkSystem
*/

#include "NetworkSystem.hpp"
#include "Components.hpp"
#include "Deserializer.hpp"
#include "Serializer.hpp"
#include "NetworkComponent.hpp"
#include <iostream>
#include <random>
#include <unistd.h>

namespace Otter::Games::RType::System::Network {

    void getAllNetworkUpdatedValue(Otter::Core::Orchestrator& ref)
    {
        auto& components = ref.get_components<Otter::Network::NetworkComponent>();
        auto& component = components[1];

        if (!component)
            return;
        
        std::stringstream data;
        int test = 0;

        component->channel.recv(data);

        if (data.tellp() == 0)
            return;

        test = Otter::Network::Deserializer::loadArchive<int>(data);

        std::cout << "After receive = " << test << std::endl;
    }

    void sendAllNetworkUpdatedValue(Otter::Core::Orchestrator& ref)
    {
        auto& components = ref.get_components<Otter::Network::NetworkComponent>();
        auto& component = components[1];

        if (!component)
            return;
        
        std::stringstream data;
        int range = 1000 - 0 + 1;
        int num = std::rand() % range;

        Otter::Network::Serializer::saveArchive(data, num);

        component->channel.send(component->portToSend, data);

        std::cout << "Before sending = " << num << std::endl;

        sleep(3);
    }
} // namespace Otter::Games::RType::System::Event}
