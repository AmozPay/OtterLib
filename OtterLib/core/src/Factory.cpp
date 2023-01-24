/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Factory
*/

#include "Factory.hpp"

#include <filesystem>
#include <fstream>
#include <map>
#include <memory>
#include <sstream>

namespace Otter::Core {
    namespace pt = boost::property_tree;

    Factory::Factory(Otter::Core::Orchestrator& core) : _core(core) {}

    Factory::~Factory() {}

    void Factory::addComponentSerializer(std::string component_name,
                                         std::function<void(Entity, Orchestrator& core, pt::ptree)> initializer)
    {
        _initializers[component_name] = initializer;
    }

    Otter::Core::Entity Factory::createFromFile(std::string path)
    {
        pt::ptree root;
        Otter::Core::Entity e = _core.createEntity();
        std::function<void(Entity, Orchestrator & core, pt::ptree)> initializer;

        if (!std::filesystem::exists(path))
            throw std::runtime_error("This file does not exist: " + path);
        pt::read_json(path, root);
        pt::ptree& components = root.get_child("components");
        for (auto& it : components) {
            auto& key = it.first;
            auto& value = it.second;
            if (_initializers.find(key) == _initializers.end()) {
                _core.remove_entity(e);
                throw std::runtime_error("No initializing method found for component: " + key);
            }
            initializer = _initializers.at(key);
            initializer(e, _core, value);
        }
        return e;
    }

    std::vector<Entity> Factory::loadEntitiesFromFolder(std::string path)
    {
        std::vector<Entity> entities;

        for (const auto& dirEntry : std::filesystem::recursive_directory_iterator(path)) {
            auto file_path = std::filesystem::absolute(path) / dirEntry;
            Entity e = this->createFromFile(file_path);
            entities.emplace_back(e);
        }

        return entities;
    }

    // Component Factory::_initTexture2DComponent(pt::ptree root)
    // {
    //     GameComponents::Texture2D component;
    //     auto& transform = _world.getComponent<GameComponents::Transform>(entity);
    //     Vector2 vecou = {transform.position.x, transform.position.y};

    //     component.path = root.get<std::string>("path");

    //     component.sprite = std::make_shared<Raylib::RaylibTexture>(component.path);
    //     component.sprite->setPosition(vecou);
    //     component.sprite->setScale(transform.scale.x);
    //     component.sprite->setRotation(transform.rotation.x);
    //     _world.addComponent(entity, component);
    // }

} // namespace Otter::Core
