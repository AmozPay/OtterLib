#include "lua_wrapper.hpp"
#include "Orchestrator.hpp"
#include "baseComponents.hpp"

namespace Otter::Scripting::Bindings::Orchestrator {

    int createEntity(lua_State *L)
    {
        Otter::Scripting::LuaContext ctx(L);
        Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
        Otter::Core::Entity e = orchestrator->createEntity();
        ctx.push(static_cast<long long>(e));
        return 1;
    }

    int removeEntity(lua_State *L)
    {
        Otter::Scripting::LuaContext ctx(L);
        Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
        std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("l");
        auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
        Otter::Core::Entity e = orchestrator->createEntity();
        orchestrator->remove_entity(entity);
        return 0;
    }

} // namespace Otter::Scripting::Bindings::Orchestrator

namespace Otter::Scripting::Bindings {
    class EnumException {
        public:
            EnumException(std::string str): _what(str) {}
            std::string what()
            {
                return _what;
            }
            std::string _what;
    };
}

namespace Otter::Scripting::Bindings::BaseComponents {

    namespace Window {
        int createAndAdd(lua_State *L)
        {
            Otter::Scripting::LuaContext ctx(L);
            Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
            std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("lllsl");
            auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
            auto width = static_cast<int>(std::get<long long>(args[1]));
            auto height = static_cast<int>(std::get<long long>(args[2]));
            auto title = std::string(std::get<char const *>(args[3]));
            auto fps = static_cast<int>(std::get<long long>(args[4]));
            orchestrator->add_component(entity, Core::BaseComponents::Window(width, height, title, fps));
            return 0;
        }
    }

    namespace BoxCollider {
        int createAndAdd(lua_State *L)
        {
            Otter::Scripting::LuaContext ctx(L);
            Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
            std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("lll");
            auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
            auto width = static_cast<float>(std::get<double>(args[1]));
            auto height = static_cast<float>(std::get<double>(args[2]));
            orchestrator->add_component(entity, Core::BaseComponents::BoxCollider(width, height));
            return 0;
        }
    }

    namespace Sound {
        int createAndAdd(lua_State *L)
        {
            auto str_to_enum = std::map<std::string, Core::BaseComponents::SoundStatus>();
            str_to_enum["PLAYING"] = Core::BaseComponents::SoundStatus::PLAYING;
            str_to_enum["PAUSED"] = Core::BaseComponents::SoundStatus::PAUSED;
            str_to_enum["STOPPED"] = Core::BaseComponents::SoundStatus::STOPPED;
            Otter::Scripting::LuaContext ctx(L);
            Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
            std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("lsds");
            auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
            auto path = std::string(std::get<char const *>(args[1]));
            auto volume = static_cast<float>(std::get<double>(args[2]));
            char const *str = std::get<char const *>(args[3]);
            if (str_to_enum.find(str) == str_to_enum.end())
                throw Bindings::EnumException(std::string("Invalid enum str value for Core::BaseComponents::SoundStatus: " + std::string(str)));
            auto status = str_to_enum[str];
            orchestrator->add_component(entity, Core::BaseComponents::Sound(path, volume, status));
            return 0;
        }

        int set_status(lua_State *L)
        {
            auto str_to_enum = std::map<std::string, Core::BaseComponents::SoundStatus>();
            str_to_enum["PLAYING"] = Core::BaseComponents::SoundStatus::PLAYING;
            str_to_enum["PAUSED"] = Core::BaseComponents::SoundStatus::PAUSED;
            str_to_enum["STOPPED"] = Core::BaseComponents::SoundStatus::STOPPED;
            Otter::Scripting::LuaContext ctx(L);
            Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
            std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("ls");
            auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
            char const *str = std::get<char const *>(args[1]);
            if (str_to_enum.find(str) == str_to_enum.end())
                throw Bindings::EnumException(std::string("Invalid enum str value for Core::BaseComponents::SoundStatus: " + std::string(str)));
            orchestrator->get_components<Core::BaseComponents::Sound>()[entity]->_status = str_to_enum[str];
            return 0;
        }

        int get_status(lua_State *L)
        {
            auto enum_to_str = std::map<Core::BaseComponents::SoundStatus, std::string>();
            enum_to_str[Core::BaseComponents::SoundStatus::PLAYING] = "PLAYING";
            enum_to_str[Core::BaseComponents::SoundStatus::PAUSED] = "PAUSED";
            enum_to_str[Core::BaseComponents::SoundStatus::STOPPED] = "STOPPED";
            Otter::Scripting::LuaContext ctx(L);
            Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
            std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("ls");
            auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
            auto status = orchestrator->get_components<Core::BaseComponents::Sound>()[entity]->_status;
            std::string status_str = enum_to_str[status];
            ctx.push(status_str.c_str());
            return 1;
        }
    }

    namespace Music {
        int createAndAdd(lua_State *L)
        {
            auto str_to_enum = std::map<std::string, Core::BaseComponents::SoundStatus>();
            str_to_enum["PLAYING"] = Core::BaseComponents::SoundStatus::PLAYING;
            str_to_enum["PAUSED"] = Core::BaseComponents::SoundStatus::PAUSED;
            str_to_enum["STOPPED"] = Core::BaseComponents::SoundStatus::STOPPED;
            Otter::Scripting::LuaContext ctx(L);
            Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
            std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("lsdbs");
            auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
            auto path = std::string(std::get<char const *>(args[1]));
            auto volume = static_cast<float>(std::get<double>(args[2]));
            auto isLooping = std::get<bool>(args[3]);
            char const *str = std::get<char const *>(args[4]);
            if (str_to_enum.find(str) == str_to_enum.end())
                throw Bindings::EnumException(std::string("Invalid enum str value for Core::BaseComponents::SoundStatus: " + std::string(str)));
            auto status = str_to_enum[str];
            orchestrator->add_component(entity, Core::BaseComponents::Music(path, volume, isLooping, status));
            return 0;
        }

        int set_status(lua_State *L)
        {
            auto str_to_enum = std::map<std::string, Core::BaseComponents::SoundStatus>();
            str_to_enum["PLAYING"] = Core::BaseComponents::SoundStatus::PLAYING;
            str_to_enum["PAUSED"] = Core::BaseComponents::SoundStatus::PAUSED;
            str_to_enum["STOPPED"] = Core::BaseComponents::SoundStatus::STOPPED;
            Otter::Scripting::LuaContext ctx(L);
            Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
            std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("ls");
            auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
            char const *str = std::get<char const *>(args[1]);
            if (str_to_enum.find(str) == str_to_enum.end())
                throw Bindings::EnumException(std::string("Invalid enum str value for Core::BaseComponents::SoundStatus: " + std::string(str)));
            orchestrator->get_components<Core::BaseComponents::Music>()[entity]->_status = str_to_enum[str];
            return 0;
        }

        int get_status(lua_State *L)
        {
            auto enum_to_str = std::map<Core::BaseComponents::SoundStatus, std::string>();
            enum_to_str[Core::BaseComponents::SoundStatus::PLAYING] = "PLAYING";
            enum_to_str[Core::BaseComponents::SoundStatus::PAUSED] = "PAUSED";
            enum_to_str[Core::BaseComponents::SoundStatus::STOPPED] = "STOPPED";
            Otter::Scripting::LuaContext ctx(L);
            Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
            std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("ls");
            auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
            auto status = orchestrator->get_components<Core::BaseComponents::Music>()[entity]->_status;
            std::string status_str = enum_to_str[status];
            ctx.push(status_str.c_str());
            return 1;
        }
    }

    namespace Transform {
        int createAndAdd(lua_State *L)
        {
            Otter::Scripting::LuaContext ctx(L);
            Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
            std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("ldddd");
            auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
            float scale = std::get<double>(args[1]);
            float rotation = std::get<double>(args[2]);
            float pos_x = std::get<double>(args[3]);
            float pos_y = std::get<double>(args[4]);
            orchestrator->add_component(entity, Core::BaseComponents::Transform(scale, rotation, {.x=pos_x, .y=pos_y}));
            return 0;
        }
    }

    namespace Velocity {
        int createAndAdd(lua_State *L)
        {
            Otter::Scripting::LuaContext ctx(L);
            Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
            std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("ldddddd");
            auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
            float speed = std::get<double>(args[1]);
            float constantSpeed = std::get<double>(args[2]);
            float acc_pos_x = std::get<double>(args[3]);
            float acc_pos_y = std::get<double>(args[4]);
            float c_acc_pos_x = std::get<double>(args[5]);
            float c_acc_pos_y = std::get<double>(args[6]);
            orchestrator->add_component(entity, Core::BaseComponents::Velocity(speed, constantSpeed, {.x=acc_pos_x, .y=acc_pos_y}, {.x=c_acc_pos_x, .y=c_acc_pos_y}));
            return 0;
        }
    }

    namespace Player {
        int createAndAdd(lua_State *L)
        {
            std::cout << 1 << std::endl;
            Otter::Scripting::LuaContext ctx(L);
            std::cout << 2 << std::endl;
            Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
            std::cout << 3 << std::endl;
            std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("lls");
            std::cout << 4 << std::endl;
            auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
            std::cout << 5 << std::endl;
            int id = std::get<long long>(args[1]);
            std::cout << 6 << std::endl;
            std::string tag = std::get<char const *>(args[2]);
            std::cout << 7 << std::endl;
            orchestrator->add_component(entity, Core::BaseComponents::Player(id, tag));
            std::cout << 888 << std::endl;
            return 0;
        }
    }

    namespace Enemy {
        int createAndAdd(lua_State *L)
        {
            Otter::Scripting::LuaContext ctx(L);
            Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
            std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("lls");
            auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
            int id = std::get<long long>(args[1]);
            std::string tag = std::get<char const *>(args[2]);
            orchestrator->add_component(entity, Core::BaseComponents::Enemy(id, tag));
            return 0;
        }
    }

    namespace Health {
        int createAndAdd(lua_State *L)
        {
            Otter::Scripting::LuaContext ctx(L);
            Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
            std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("ll");
            auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
            unsigned int hp = std::get<long long>(args[1]);
            orchestrator->add_component(entity, Core::BaseComponents::Health(hp));
            return 0;
        }
    }

    namespace Damage {
        int createAndAdd(lua_State *L)
        {
            Otter::Scripting::LuaContext ctx(L);
            Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
            std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("ll");
            auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
            unsigned int damage = std::get<long long>(args[1]);
            orchestrator->add_component(entity, Core::BaseComponents::Damage(damage));
            return 0;
        }
    }

    namespace Destructible {
        int createAndAdd(lua_State *L)
        {
            Otter::Scripting::LuaContext ctx(L);
            Otter::Core::Orchestrator *orchestrator = static_cast<Otter::Core::Orchestrator *>(ctx["__orchestrator"].toVoidPtr());
            std::vector<Otter::Scripting::luaTypes> args = ctx.getArgs("lb");
            auto entity = static_cast<Otter::Core::Entity>(std::get<long long>(args[0]));
            bool isDestructible = std::get<bool>(args[1]);
            orchestrator->add_component(entity, Core::BaseComponents::Destructible(isDestructible));
            return 0;
        }
    }

}
