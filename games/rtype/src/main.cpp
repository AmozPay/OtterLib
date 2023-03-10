/*
** EPITECH PROJECT, 2023
** OtterLib [WSL : Ubuntu]
** File description:
** main
*/

#include "OtterCore.hpp"

#if defined(TARGET_CLIENT)
#include "GameClient.hpp"
#elif defined(TARGET_SERVER)
#include "GameServer.hpp"
#endif

namespace Otter::Core {

    DllExport void createEntityObj(Otter::Core::Orchestrator& ref)
    {
#if defined(TARGET_CLIENT)
        Otter::Games::GameClient::createEntityObj(ref);
#elif defined(TARGET_SERVER)
        Otter::Games::GameServer::createEntityObj(ref);
#endif
    }

    DllExport void registerComponents(Otter::Core::Orchestrator& ref)
    {
#if defined(TARGET_CLIENT)
        Otter::Games::GameClient::registerComponents(ref);
#elif defined(TARGET_SERVER)
        Otter::Games::GameServer::registerComponents(ref);
#endif
    }

    DllExport void registerSystems(Otter::Core::SystemManager& ref)
    {
#if defined(TARGET_CLIENT)
        Otter::Games::GameClient::registerSystems(ref);
#elif defined(TARGET_SERVER)
        Otter::Games::GameServer::registerSystems(ref);
#endif
    }

    DllExport void configureScripting(Otter::Scripting::ScriptingManager& scriptingManager)
    {
#if defined(TARGET_CLIENT)
        Otter::Games::GameClient::configureScripting(scriptingManager);
#elif defined(TARGET_SERVER)
        Otter::Games::GameServer::configureScripting(scriptingManager);
#endif
    }
} // namespace Otter::Core
