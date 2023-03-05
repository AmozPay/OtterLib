#include "OtterCore.hpp"

#include "baseComponents.hpp"

namespace Otter::Core {

    void OtterCore::_registerBaseComponents(void)
    {
        this->_data.register_component<Core::BaseComponents::Render>();
        this->_data.register_component<Core::BaseComponents::Keyboard>();
        this->_data.register_component<Core::BaseComponents::Parallax>();
        this->_data.register_component<Core::BaseComponents::Dispawnable>();
        this->_data.register_component<Core::BaseComponents::EventNetwork>();
        this->_data.register_component<Core::BaseComponents::Window>();
        this->_data.register_component<Core::BaseComponents::BoxCollider>();
        this->_data.register_component<Core::BaseComponents::Sound>();
        this->_data.register_component<Core::BaseComponents::Music>();
        this->_data.register_component<Core::BaseComponents::Transform>();
        this->_data.register_component<Core::BaseComponents::Velocity>();
        this->_data.register_component<Core::BaseComponents::Player>();
        this->_data.register_component<Core::BaseComponents::Enemy>();
        this->_data.register_component<Core::BaseComponents::Health>();
        this->_data.register_component<Core::BaseComponents::Damage>();
        this->_data.register_component<Core::BaseComponents::Destructible>();
        this->_data.register_component<Core::BaseComponents::Texture>();
        this->_data.register_component<Core::BaseComponents::TextureStorage>();
        this->_data.register_component<Core::BaseComponents::GameStatus>();
    }

    void OtterCore::init()
    {
        _registerBaseComponents();
        registerComponents(this->_data);
        registerSystems(this->_systems);
        _scriptingManager.enableScripting("../scripts");
        createEntityObj(this->_data);
        // _scriptingManager.enableScripting("../scripts/main.lua");
        /// call factory
    }

    void OtterCore::loop()
    {
        _systems(_data, SystemManager::init);
        while (this->_isRunning) {
            _systems(_data, SystemManager::preEvent);
            _systems(_data, SystemManager::event);
            _systems(_data, SystemManager::preUpdate);
            _systems(_data, SystemManager::update);
            _systems(_data, SystemManager::preDraw);
            _systems(_data, SystemManager::draw);
            _systems(_data, SystemManager::subDraw);
        }
        _systems(_data, SystemManager::cleanup);
    }

    int OtterCore::engineStart()
    {
        init();
        loop();
        return 0;
    }

} // namespace Otter::Core
