#include "script.hpp"

#include <stdexcept>
#include <filesystem>

namespace Otter::Script {

    Lua::Lua():
    L(luaL_newstate())
    {
        luaL_openlibs(L);
    }

    Lua::~Lua()
    {
        lua_close(L);
    }

    void Lua::doFile(std::string path)
    {
        if (!std::filesystem::is_regular_file(path)) {
            throw std::runtime_error("Invalid file path");
        }
        LUA_ERR_WRAP(luaL_dofile(L, path.c_str()));
    }

    void Lua::doString(std::string luaString)
    {
        LUA_ERR_WRAP(luaL_dostring(L, luaString.c_str()));
    }

    bool Lua::_callFn(std::string name, std::string argsTypes, va_list args, unsigned int nb_return_vals)
    {

        unsigned int nb_args = 0;
        lua_getglobal(L, name.c_str());

        if (!lua_isfunction(L, -1)) {
            lua_pop(L, -1);
            return false;
        }

        for (auto i: argsTypes) {
            switch (i)
            {
                case 'b':
                    lua_pushboolean(L, static_cast<bool>(va_arg(args, int)));
                    break;
                case 'd':
                    lua_pushnumber(L, va_arg(args, double));
                    break;
                case 's':
                    {
                        const std::string str(va_arg(args, const char *));
                        lua_pushstring(L, str.c_str());
                    }
                    break;
                case 'n':
                    lua_pushnil(L);
                    va_arg(args, int);
                    break;
                case 'p':
                    lua_pushlightuserdata(L, va_arg(args, void *));
                    break;
                case 'l':
                    lua_pushinteger(L, va_arg(args, long long));
                    break;
                default:
                    throw std::invalid_argument("Invalid fmt string");
                    break;
            }
            nb_args++;
        }
        lua_call(L, nb_args, nb_return_vals);
        return true;
    }
}