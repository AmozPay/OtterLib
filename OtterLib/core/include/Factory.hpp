/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "EntityManager.hpp"
#include "Orchestrator.hpp"

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <functional>
#include <map>

namespace Otter::Core {
    namespace pt = boost::property_tree;

    class Component {};

    class Factory {
        using initializer_mptr = std::function<void(Entity, Orchestrator& core, pt::ptree)>;

      public:
        Factory(Otter::Core::Orchestrator& core);
        ~Factory();
        Entity createFromFile(std::string path);
        std::vector<Entity> loadEntitiesFromFolder(std::string path);
        void addComponentSerializer(std::string component_name,
                                    std::function<void(Entity, Orchestrator& core, pt::ptree)> initializer);

      protected:
      private:
        Otter::Core::Orchestrator& _core;
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
