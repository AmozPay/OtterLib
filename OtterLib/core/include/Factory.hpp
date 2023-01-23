/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

namespace Otter::Core {
    namespace pt = boost::property_tree;
    using map_2d = std::vector<std::string>;

    class Factory {
        using initializer_mptr = void (Factory::*)(Entity, pt::ptree);

      public:
        Factory(Engine::World& world);
        ~Factory();
        Entity createFromFile(std::string path);

      protected:
      private:
        Otter::Core::Orchestrator& _core;
        void _initTexture2DComponent(Entity entity, pt::ptree root);
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
