#include "Client.hpp"
#include "ClientComponent.hpp"
#include "NetworkComponent.hpp"
#include "OtterCore.hpp"
#include "Server.hpp"
#include "ServerComponent.hpp"

#include <iostream>

void test_upd(Otter::Core::Orchestrator& ref)
{
    auto& sock = ref.get_components<Otter::Network::SocketComponent>();
    auto& serv = ref.get_components<Otter::Network::ServerComponent>();

    for (int i = 0; i < sock.size(); i++) {
        if (!sock[i]) {
            continue;
        }
        std::cout << sock[i]->channel << std::endl;
        if (serv[i])
            std::cout << "serv exist with socket" << std::endl;
        else
            std::cout << "serv doest exist" << std::endl;
    }
}

void setupNetwork(Otter::Core::Orchestrator& ref) {}

void test_conect_serv(Otter::Core::Orchestrator& ref)
{
    auto& cl = ref.get_components<Otter::Network::ClientComponent>();
    /**
    if (cl.size() != 0) {
      for (int i = 0; i < cl.size(); i++) {
      }*/
}

namespace Otter::Core {

    void createEntityObj(Otter::Core::Orchestrator& ref)
    {
        Entity e = ref.createEntity();
        std::cout << "sockec on id " << e << std::endl;

        ref.builder.createFromFile("../scripts/serverSetup.conf", ref, 0);
        //	ref.add_component(0, Otter::Network::ServerComponent());
    }

    void registerComponents(Otter::Core::Orchestrator& ref)
    {
        ref.register_component<Otter::Network::SocketComponent>();
        ref.register_component<Otter::Network::ServerComponent>();
        ref.register_component<Otter::Network::ClientComponent>();
    }

    void configureScripting(Otter::Scripting::ScriptingManager&) {}

    void registerSystems(Otter::Core::SystemManager& ref)
    {
#if defined(TARGET_CLIENT)
        std::cout << "iam client" << std::endl;
        ref.registerSystem(&Otter::Network::Client::init, Otter::Core::SystemManager::init);
        ref.registerSystem(&test_upd, Otter::Core::SystemManager::init);
        ref.registerSystem(&Otter::Network::Client::update, Otter::Core::SystemManager::update);
        //       ref.registerSystem(&test_conect_serv, Otter::Core::SystemManager::update);

#endif
#if defined(TARGET_SERVER)
        std::cout << "iam server" << std::endl;
        ref.registerSystem(&Otter::Network::Server::init, Otter::Core::SystemManager::init);
        ref.registerSystem(&test_upd, Otter::Core::SystemManager::init);
        ref.registerSystem(&Otter::Network::Server::update, Otter::Core::SystemManager::update);
        ref.registerSystem(&test_conect_serv, Otter::Core::SystemManager::update);
#endif
        std::cout << "end of register system" << std::endl;
    }

} // namespace Otter::Core
