#include "lua_wrapper.hpp"

#include "lua.h"

#include <cstring>
#include <filesystem>
#include <iostream>
#include <stdexcept>

namespace Otter::Scripting {

    LuaContext::LuaContext() : L(luaL_newstate()), _isOriginal(true) { luaL_openlibs(L); }

    LuaContext::LuaContext(lua_State* state) : L(state), _isOriginal(false) {}

    LuaContext::~LuaContext()
    {
        if (_isOriginal)
            lua_close(L);
    }

    void LuaContext::doFile(std::string path)
    {
        if (!std::filesystem::is_regular_file(path)) {
            throw std::runtime_error("Invalid file path");
        }
        LUA_ERR_WRAP(luaL_dofile(L, path.c_str()));
    }

    void LuaContext::doString(std::string luaString) { LUA_ERR_WRAP(luaL_dostring(L, luaString.c_str())); }

    bool LuaContext::_callFn(std::string name, std::string argsTypes, va_list args, unsigned int nb_return_vals)
    {

        unsigned int nb_args = 0;
        lua_getglobal(L, name.c_str());

        if (!lua_isfunction(L, -1)) {
            lua_pop(L, 1);
            return false;
        }

        for (auto i : argsTypes) {
            switch (i) {
            case 'b':
                lua_pushboolean(L, static_cast<bool>(va_arg(args, int)));
                break;
            case 'd':
                lua_pushnumber(L, va_arg(args, double));
                break;
            case 's': {
                lua_pushstring(L, va_arg(args, const char*));
            } break;
            case 'n':
                lua_pushnil(L);
                va_arg(args, int);
                break;
            case 'p':
                lua_pushlightuserdata(L, va_arg(args, void*));
                break;
            case 'i':
                lua_pushinteger(L, va_arg(args, lua_Integer));
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

    void LuaContext::registerFunction(std::string name, lua_CFunction function)
    {
        lua_pushcfunction(L, function);
        lua_setglobal(L, name.c_str());
    }

    void LuaContext::push(lua_Integer integer) { lua_pushinteger(L, integer); }

    void LuaContext::push(double number) { lua_pushnumber(L, number); }

    void LuaContext::push(char const* str) { lua_pushstring(L, str); }

    void LuaContext::push(bool boolean) { lua_pushboolean(L, boolean); }

    void LuaContext::push(void* ptr) { lua_pushlightuserdata(L, ptr); }

    void LuaContext::setGlobal(std::string name, void* value)
    {
        this->push(value);
        lua_setglobal(L, name.c_str());
    }

    void LuaContext::setGlobal(std::string name, char const* value)
    {
        this->push(value);
        lua_setglobal(L, name.c_str());
    }

    void LuaContext::setGlobal(std::string name, lua_Integer value)
    {
        this->push(value);
        lua_setglobal(L, name.c_str());
    }

    void LuaContext::setGlobal(std::string name, double value)
    {
        this->push(value);
        lua_setglobal(L, name.c_str());
    }

    void LuaContext::setGlobal(std::string name, bool value)
    {
        this->push(value);
        lua_setglobal(L, name.c_str());
    }

    std::vector<luaTypes> LuaContext::getArgs(std::string typesFmt)
    {
        std::reverse(typesFmt.begin(), typesFmt.end());
        return this->getStackValues(typesFmt, false);
    }

    std::vector<luaTypes> LuaContext::getStackValues(const std::string returnTypes, bool popValue)
    {
        std::vector<luaTypes> returnValues;
        unsigned int i = 1;

        for (auto type : returnTypes) {
            switch (type) {
            case 'b':
                LUA_ERR_WRAP(lua_isboolean(L, -i));
                returnValues.emplace_back(static_cast<bool>(lua_toboolean(L, -i)));
                break;
            case 'd':
                LUA_ERR_WRAP(lua_isnumber(L, -i));
                returnValues.emplace_back(lua_tonumber(L, -i));
                break;
            case 's':
                LUA_ERR_WRAP(lua_isstring(L, -i));
                returnValues.emplace_back(lua_tostring(L, -i));
                break;
            case 'i':
                LUA_ERR_WRAP(lua_isinteger(L, -i));
                returnValues.emplace_back(lua_tointeger(L, -i));
                break;
            case 'p':
                LUA_ERR_WRAP(lua_isuserdata(L, -i));
                returnValues.emplace_back(lua_touserdata(L, -i));
                break;
            default:
                throw std::invalid_argument("Invalid fmt string");
                break;
            }
            if (popValue) {
                lua_pop(L, 1);
            } else {
                i++;
            }
        }
        std::reverse(returnValues.begin(), returnValues.end());
        return returnValues;
    }

    LuaValue LuaContext::operator[](std::string name) { return LuaValue(L, name); }

    LuaValue::LuaValue(lua_State* state, std::string key) : L(state) { _keys.emplace_back(key); }

    LuaValue::LuaValue(lua_State* state, std::vector<std::string> keys, std::string key) : L(state), _keys(keys)
    {
        _keys.emplace_back(key);
    }

    LuaValue LuaValue::operator[](std::string key) { return LuaValue(L, _keys, key); }

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
        lua_pop(L, 1);
        for (unsigned int i = 1; i < _keys.size(); i++) {
            lua_pop(L, 1);
            // lua_pop(L, 1); should work, dunno why it does this: PANIC: unprotected error in call to Lua API (attempt
            // to call a nil value)
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

    lua_Integer LuaValue::toInteger()
    {
        lua_Integer res;
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

    void* LuaValue::toVoidPtr()
    {
        void* res;
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

    unsigned long long LuaValue::getTableLength()
    {
        std::string path = _keys[0];
        for (unsigned int i = 1; i < _keys.size(); i++) {
            path += "." + _keys[i];
        }
        LuaContext ctx(L);
        std::string getLen = "function __getTableLen()\n return "
                             "#" +
                             path + " \nend \n";
        ctx.doString(getLen);
        auto retVals = ctx.callFn("__getTableLen", "i");
        unsigned long long len = std::get<lua_Integer>(retVals[0]);
        return len;
    }

} // namespace Otter::Scripting