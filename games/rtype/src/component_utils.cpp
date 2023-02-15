#include "Utils.hpp"

#include <boost/property_tree/ptree.hpp>

namespace pt = boost::property_tree;

namespace Otter::Games::RType::Components {
    Otter::Games::RType::Utils::Vector2 getVector2(pt::ptree json, std::string key)
    {
        pt::ptree child = json.get_child(key);
        return Otter::Games::RType::Utils::Vector2(child.get<float>("x"), child.get<float>("y"));
    }
} // namespace Otter::Games::RType::Components