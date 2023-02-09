/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "EntityManager.hpp"

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <functional>
#include <map>

#define COMPONENT_BUILDER(name)                                                                                        \
    inline static std::string __tag = #name;                                                                           \
    static void __initialise(Otter::Core::Entity e, Otter::Core::Orchestrator& core, pt::ptree json)

namespace Otter::Core {
    class Orchestrator;

    namespace pt = boost::property_tree;

    class Component {};

    template <class T>
    concept buildable = requires(T b, Entity e, Orchestrator& core, pt::ptree t) {
                            b.__initialise(e, core, t);
                            {
                                T::__tag
                            };
                        };

    class Factory {
        using initializer_mptr = std::function<void(Entity, Orchestrator& core, pt::ptree)>;

      public:
        Factory();
        ~Factory();
        Entity createFromFile(std::string path, Otter::Core::Orchestrator& core);
        std::vector<Entity> loadEntitiesFromFolder(std::string path, Otter::Core::Orchestrator& core);
        void addComponentSerializer(std::string component_name,
                                    std::function<void(Entity, Orchestrator& core, pt::ptree)> initializer);

      protected:
      private:
        // void _initTexture2DComponent(Entity entity, pt::ptree root);
        std::map<std::string, initializer_mptr> _initializers;
    };

    template <typename T>
    std::vector<T> as_vector(pt::ptree const& tree, pt::ptree::key_type const& key)
    {
        std::vector<T> r;
        for (auto& item : tree.get_child(key))
            r.push_back(item.second.get_value<T>());
        return r;
    }
} // namespace Otter::Core

#endif /* !FACTORY_HPP_ */
