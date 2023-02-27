/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** NetworkSystem
*/

#include "NetworkSystem.hpp"

#include "Components.hpp"
#include "Deserializer.hpp"
#include "NetworkComponent.hpp"
#include "Networkable.hpp"
#include "Serializer.hpp"

#include <iostream>
#include <random>
#include <unistd.h>

namespace Otter::Games::RType::System::Network {

    using baseMap = std::unordered_map<std::size_t, std::pair<std::type_index, std::any&>>;
    /*
      namespace {

          void getLocalNetworkableVariableUpdates(
              Otter::Core::Orchestrator& ref,
              Otter::Network::NetworkComponent component
          ) {
              auto& components = ref.get_map_fromBase<Otter::Network::Networkable::Class>();
              Otter::Network::Networkable::Class newtorkableClass;
              std::optional<std::stringstream> optStream;

              for (auto& [key, value] : components) {
                  newtorkableClass = std::any_cast<Otter::Network::Networkable::Class>(value.second);
                  optStream = newtorkableClass.getUpdatedNetworkableVariable(key);
                  if (!optStream)
                      continue;
                  component.channel->send(component.portToSend, *optStream);
              }
          }

          void updateLocalNetworkableVariable(Otter::Core::Orchestrator& ref, std::stringstream& data)
          {
              auto& components = ref.get_map_fromBase<Otter::Network::Networkable::Class>();
              std::stringstream::pos_type writePos = data.tellg();
              std::size_t componentId = 0;
              baseMap::iterator it;
              Otter::Network::Networkable::Class networakbleClass;

              while (data.tellg() < writePos) {
                  componentId = Otter::Network::Deserializer::loadArchive<std::size_t>(data);
                  it = components.find(componentId);
                  if (it == components.end())
                      continue;
                  networakbleClass = std::any_cast<Otter::Network::Networkable::Class>(it->second.second);
                  networakbleClass.updateNetworkableVariables(data);
              }
          }

      } // namespace

      void initNetwork(Otter::Core::Orchestrator& ref)
      {
          std::cout << "initNetwork" << std::endl;
          auto& net = ref.get_components<Otter::Network::NetworkComponent>();

          for (int i = 0; i < net.size(); i++) {
              if (net[i])
                  net[i]->init();
          }
      }

      void getAllNetworkUpdatedValue(Otter::Core::Orchestrator& ref)
      {
          std::cout << "getAllNetworkUpdatedValue" << std::endl;
          std::stringstream data;
          auto& networkComps = ref.get_components<Otter::Network::NetworkComponent>();


          /*        component->channel.recv(data);

          if (data.tellp() == 0)
              return;

          test = Otter::Network::Deserializer::loadArchive<int>(data);

          std::cout << "After receive = " << test << std::endl;
          if (!networkComp)
              return;

          networkComp->channel->recv(data);
          updateLocalNetworkableVariable(ref, data);

           }
    */
    /*    void sendAllNetworkUpdatedValue(Otter::Core::Orchestrator& ref)
        {
                  std::cout << "sendAllNetworkUpdatedValue" << std::endl;
            auto& networkComps = ref.get_components<Otter::Network::NetworkComponent>();
            auto& networkComp = networkComps[0];

            if (!networkComp)
                return;
            getLocalNetworkableVariableUpdates(ref, *networkComp);

            }*/
} // namespace Otter::Games::RType::System::Network
