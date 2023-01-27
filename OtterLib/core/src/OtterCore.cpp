#include "OtterCore.hpp"

namespace Otter::Core {
    void OtterCore::init()
    {
        registerComponents();
        registerSystems();
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
    }

    int OtterCore::engineStart()
    {
        init();
        loop();
        return 0;
    }

} // namespace Otter::Core
