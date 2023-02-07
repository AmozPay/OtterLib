#include "script.hpp"

#include <stdexcept>
#include <filesystem>

namespace Otter::Script {

    Lua::Lua():
    _lua(luaL_newstate())
    {
        luaL_openlibs(_lua);
    }

    Lua::~Lua()
    {
        lua_close(_lua);
    }

    int Lua::doFile(std::string path)
    {
        return luaL_dofile(_lua, path.c_str());
    }

    int Lua::doString(std::string luaString)
    {
        return luaL_dostring(_lua, luaString.c_str());
    }

    bool Lua::_callFn(std::string name, std::string argsTypes, va_list args, unsigned int nb_return_vals)
    {
        unsigned int nb_args = 0;
        lua_getglobal(_lua, name.c_str());

        if (!lua_isfunction(_lua, -1)) {
            lua_pop(_lua, -1);
            return false;
        }

        for (auto i: argsTypes) {
            switch (i)
            {
                case 'b':
                    lua_pushboolean(_lua, static_cast<bool>(va_arg(args, int)));
                    break;
                case 'd':
                    lua_pushnumber(_lua, va_arg(args, double));
                    break;
                case 's':
                    {
                        const std::string str(va_arg(args, const char *));
                        lua_pushstring(_lua, str.c_str());
                    }
                    break;
                case 'n':
                    lua_pushnil(_lua);
                    va_arg(args, int);
                    break;
                case 'p':
                    lua_pushlightuserdata(_lua, va_arg(args, void *));
                    break;
                case 'l':
                    lua_pushinteger(_lua, va_arg(args, long long));
                    break;
                default:
                    throw std::invalid_argument("Invalid fmt string");
                    break;
            }
            nb_args++;
        }
        lua_call(_lua, nb_args, nb_return_vals);
        return true;
    }

    void Lua::loadFile(std::string path)
    {
        if (!std::filesystem::is_regular_file(path)) {
            throw std::runtime_error("Invalid file path");
        }
        int res = luaL_loadfile(_lua, path.c_str());
        if (res != LUA_OK) {
            _error();
            throw LuaError("Could not load file");
        }
    }

    void Lua::_error(void)
    {
        luaL_error(_lua, "Error: %s\n", lua_tostring(_lua, -1));
    }

}