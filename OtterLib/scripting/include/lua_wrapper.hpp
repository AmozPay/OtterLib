#pragma once

extern "C" {
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"
}

#include <algorithm>
#include <cstdarg>
#include <functional>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <variant>
#include <vector>

namespace Otter::Scripting {

    /**
     * @brief Just interfacing lua_State
     */
    typedef lua_State lua_State;
    typedef int (*lua_CFunction)(lua_State* L);
    typedef std::variant<lua_Integer, double, bool, char const*, void*> luaTypes;
#define LUA_ERR_WRAP(expr)                                                                                             \
    if ((expr) != LUA_OK && (expr) != LUA_YIELD)                                                                       \
    throw LuaError::create(L)

    class LuaError : public std::exception {
      public:
        LuaError(std::string str) : _what(str) {}

        ~LuaError() = default;

        const std::string what() { return _what; }

        static LuaError create(lua_State* L)
        {
            std::string error = lua_tostring(L, -1);
            return LuaError(error);
        }

      private:
        const std::string _what;
    };

    /**
     * @brief A container that holds a lua value that can be accessed globally
     */
    class LuaValue {
      public:
        LuaValue(lua_State* state, std::string key);
        LuaValue(lua_State* state, std::vector<std::string> keys, std::string key);
        ~LuaValue() = default;
        bool toBool();
        lua_Integer toInteger();
        double toDouble();
        void* toVoidPtr();
        std::string toString();
        bool isTable();
        unsigned long long getTableLength();
        LuaValue operator[](std::string key);
        void printPath();

      private:
        lua_State* L;
        std::vector<std::string> _keys;

        void _traverseTable(void);
        void _cleanup(void);
    };

    class LuaContext {
      public:
        LuaContext();
        LuaContext(lua_State*);
        ~LuaContext();

        /**
         * @brief Execute a LuaContext script file
         * @param path the path to the script file
         */
        void doFile(std::string path);

        /**
         * @brief Execute a string as a lua script
         * @param luaString valid lua script as a string
         */
        void doString(std::string luaString);

        std::vector<luaTypes> getArgs(std::string typesFmt);

        /**
         * @brief call a lua function, with no parameters
         * @details valid return types in string: b -> bool, d -> double, i -> lua_Integer, s -> const std::string
         * @param returnTypes a string indicating the lua types of the return values
         * @return std::vector<std::variant<Ts...>>
         */
        std::vector<luaTypes> callFn(std::string name, std::string returnTypes)
        {
            return this->callFn(name, returnTypes, "");
        }

        /**
         * @brief call a lua function
         * @details valid return types in string: b -> bool, d -> double, i -> lua_Integer, s -> const std::string, p ->
         * void *
         * @details valid args types in string: b -> bool, d -> double, i -> lua_Integer, s -> std::string, n -> nil, p ->
         * void *
         * @details if nil is specified, you must pass 0 at the same index of the variadic argument
         * @param returnTypes a string indicating the lua types of the return values
         * @param argsTypes a string indicating the lua types of the passed parameters
         * @param variadicArgs all the next params are treated as variadic, types determined by argsTypes
         * @return std::vector<std::variant<bool, int, double, std::string>>
         */
        std::vector<luaTypes> callFn(const std::string name, const std::string returnTypes, const std::string argsTypes,
                                     ...)
        {
            va_list args;
            va_start(args, argsTypes);
            bool success = _callFn(name, argsTypes, args, returnTypes.length());
            va_end(args);

            if (!success) {
                throw LuaError("Request LuaContext function does not exist!");
            }

            return this->getStackValues(returnTypes, true);
        }

        /**
         * @brief get function call parameters from lua or return values after function call
         * @param types
         * @return std::vector<luaTypes>
         */
        std::vector<luaTypes> getStackValues(const std::string typesFmt, bool popValue);

        /**
         * @brief bind a lua function to C
         * @tparam Args the parameters types of the created function
         * @param name name of the lua function to call
         * @param returnTypes valid return types in string: b -> bool, d -> double, i -> lua_Integer, s -> const
         * std::string, p -> void *
         * @param argsTypes valid args types in string: b -> bool, d -> double, i -> lua_Integer, s -> std::string, n ->
         * nil, p -> void *
         * @return std::function<std::vector<luaTypes>(Args...)> A callable function which wraps a lua function
         */
        template <typename... Args>
        std::function<std::vector<luaTypes>(Args...)> bind(const std::string name, const std::string returnTypes,
                                                           const std::string argsTypes)
        {
            return [this, &name, &returnTypes, &argsTypes](Args... args)
            { return this->callFn(name, returnTypes, argsTypes, args...); };
        }

        LuaValue operator[](std::string key);

        void registerFunction(std::string name, lua_CFunction);
        void setGlobal(std::string name, void* ptr);
        void setGlobal(std::string name, lua_Integer integer);
        void setGlobal(std::string name, double number);
        void setGlobal(std::string name, char const* str);
        void setGlobal(std::string name, bool boolean);

        void push(lua_Integer integer);
        void push(double number);
        void push(char const* str);
        void push(bool boolean);
        void push(void* ptr);

      private:
        lua_State* L;
        bool _isOriginal;
        bool _callFn(std::string name, std::string argsTypes, va_list, unsigned int nb_return_vals);
    };
} // namespace Otter::Scripting