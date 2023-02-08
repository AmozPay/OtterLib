#pragma once

extern "C"
{
  #include "lua.h"
  #include "lualib.h"
  #include "lauxlib.h"
}

#include <string>
#include <vector>
#include <variant>
#include <map>
#include <cstdarg>
#include <stdexcept>
#include <algorithm>

namespace Otter::Script {

    using luaTypes = std::variant<long long, double, bool, std::string, void *>;
    #define LUA_ERR_WRAP(expr) if ((expr) != LUA_OK && (expr) != LUA_YIELD) throw LuaError::create(L)

    class Lua {
        public:

            Lua();
            ~Lua();

            class LuaError: public std::exception {
                public:
                    LuaError(std::string str): _what(str) {}
                    ~LuaError() = default;
                    const std::string what()
                    {
                        return _what;
                    }

                    static LuaError create(lua_State *L)
                    {
                        std::string error = lua_tostring(L, -1);
                        return LuaError(error);
                    }
                private:
                    const std::string _what;
            };

            /**
             * @brief Execute a Lua script file
             * @param path the path to the script file
             */
            void doFile(std::string path);

            /**
             * @brief Execute a string as a lua script
             * @param luaString valid lua script as a string
             */
            void doString(std::string luaString);


            /**
             * @brief call a lua function, with no parameters
             * @details valid return types in string: b -> bool, d -> double, l -> long long, s -> const std::string
             * @param returnTypes a string indicating the lua types of the return values
             * @return std::vector<std::variant<Ts...>>
             */
            std::vector<luaTypes> callFn(std::string name, std::string returnTypes)
            {
                return this->callFn(name, returnTypes, "");
            }

            /**
             * @brief call a lua function
             * @details valid return types in string: b -> bool, d -> double, l -> long long, s -> const std::string, p -> void *
             * @details valid args types in string: b -> bool, d -> double, l -> long long, s -> std::string, n -> nil, p -> void *
             * @details if nil is specified, you must pass 0 at the same index of the variadic argument
             * @param returnTypes a string indicating the lua types of the return values
             * @param argsTypes a string indicating the lua types of the passed parameters
             * @param variadicArgs all the next params are treated as variadic, types determined by argsTypes
             * @return std::vector<std::variant<bool, int, double, std::string>>
             */
            std::vector<luaTypes> callFn(const std::string name, const std::string returnTypes, const std::string argsTypes, ...)
            {
                va_list args;
                va_start(args, argsTypes);
                bool success = _callFn(name, argsTypes, args, returnTypes.length());
                va_end(args);

                if (!success) {
                    throw LuaError("Request Lua function does not exist!");
                }

                std::vector<luaTypes> returnValues;

                for (auto i: returnTypes) {
                    switch (i)
                    {
                        case 'b':
                            LUA_ERR_WRAP(lua_isboolean(L, -1));
                            returnValues.emplace_back(static_cast<bool>(lua_toboolean(L, -1)));
                            break;
                        case 'd':
                            LUA_ERR_WRAP(lua_isnumber(L, -1));
                            returnValues.emplace_back(lua_tonumber(L, -1));
                            break;
                        case 's':
                            LUA_ERR_WRAP(lua_isstring(L, -1));
                            returnValues.emplace_back(lua_tostring(L, -1));
                            break;
                        case 'l':
                            LUA_ERR_WRAP(lua_isinteger(L, -1));
                            returnValues.emplace_back(lua_tointeger(L, -1));
                            break;
                        case 'p':
                            LUA_ERR_WRAP(lua_isuserdata(L, -1));
                            returnValues.emplace_back(lua_touserdata(L, -1));
                            break;
                        default:
                            throw std::invalid_argument("Invalid fmt string");
                            break;
                    }
                    lua_pop(L, 1);
                }
                std::reverse(returnValues.begin(), returnValues.end());
                return returnValues;
            }

        private:
            lua_State *L;

            bool _callFn(std::string name, std::string argsTypes, va_list, unsigned int nb_return_vals);
    };
}