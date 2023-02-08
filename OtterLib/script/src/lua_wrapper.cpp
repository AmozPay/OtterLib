#include "lua_wrapper.hpp"

#include <stdexcept>
#include <filesystem>
#include <iostream>

namespace Otter::Script {

    LuaContext::LuaContext():
    L(luaL_newstate())
    {
        luaL_openlibs(L);
    }

    LuaContext::~LuaContext()
    {
        lua_close(L);
    }

    void LuaContext::doFile(std::string path)
    {
        if (!std::filesystem::is_regular_file(path)) {
            throw std::runtime_error("Invalid file path");
        }
        LUA_ERR_WRAP(luaL_dofile(L, path.c_str()));
    }

    void LuaContext::doString(std::string luaString)
    {
        LUA_ERR_WRAP(luaL_dostring(L, luaString.c_str()));
    }

    bool LuaContext::_callFn(std::string name, std::string argsTypes, va_list args, unsigned int nb_return_vals)
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

    LuaValue LuaContext::operator[](std::string name)
    {
        return LuaValue(L, name);
    }

    LuaValue::LuaValue(lua_State *state, std::string key):
    L(state)
    {
        _keys.emplace_back(key);
    }

    LuaValue::LuaValue(lua_State *state, std::vector<std::string> keys, std::string key):
    L(state), _keys(keys)
    {
        _keys.emplace_back(key);
    }

    LuaValue LuaValue::operator[](std::string key)
    {
        return LuaValue(L, _keys, key);
    }

    void LuaValue::_traverseTable(void)
    {
        if (_keys.size() == 1)
            return;
        for (unsigned int i = 1; i < _keys.size(); i++) {
            lua_pushstring(L, _keys[i].c_str());
            LUA_ERR_WRAP(lua_istable(L, -2));
            lua_gettable(L, -2);
        }
    }

    void LuaValue::_cleanup(void)
    {
        lua_pop(L, -1);
        for (unsigned int i = 1; i < _keys.size(); i++) {
            lua_pop(L, -1);
            lua_pop(L, -1);
        }
    }

    bool LuaValue::toBool()
    {
        bool res;
        lua_getglobal(L, _keys[0].c_str());
        _traverseTable();
        LUA_ERR_WRAP(lua_isboolean(L, -1));
        res = lua_toboolean(L, -1);
        _cleanup();
        return res;
    }

    long long LuaValue::toInteger()
    {
        long long res;
        lua_getglobal(L, _keys[0].c_str());
        _traverseTable();
        LUA_ERR_WRAP(lua_isinteger(L, -1));
        res = lua_tointeger(L, -1);
        _cleanup();
        return res;
    }

    double LuaValue::toDouble()
    {
        double res;
        lua_getglobal(L, _keys[0].c_str());
        _traverseTable();
        LUA_ERR_WRAP(lua_isnumber(L, -1));
        res = lua_tonumber(L, -1);
        _cleanup();
        return res;
    }

    void *LuaValue::toVoidPtr()
    {
        void *res;
        lua_getglobal(L, _keys[0].c_str());
        _traverseTable();
        LUA_ERR_WRAP(lua_islightuserdata(L, -1));
        res = lua_touserdata(L, -1);
        _cleanup();
        return res;
    }

    std::string LuaValue::toString()
    {
        std::string res;
        lua_getglobal(L, _keys[0].c_str());
        _traverseTable();
        LUA_ERR_WRAP(lua_isstring(L, -1));
        res = lua_tostring(L, -1);
        _cleanup();
        return res;
    }

    bool LuaValue::isTable()
    {
        lua_getglobal(L, _keys[0].c_str());
        _traverseTable();
        bool res = lua_istable(L, -1);
        _cleanup();
        return res;
    }
}