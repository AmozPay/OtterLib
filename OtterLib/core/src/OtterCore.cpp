#include "OtterCore.hpp"

namespace Otter::Core {
    void OtterCore::init()
    {
        registerComponents(this->_data);
        registerSystems(this->_systems);
        createEntityObj(this->_data);
        _scriptingManager.enableScripting("../scripts/main.lua");
        /// call factory
    }

    void OtterCore::loop()
    {
      std::cout << "enter init" <<  std::endl;
      _systems(_data, SystemManager::init);
      std::cout << "end init" <<  std::endl;
        while (this->_isRunning) {
            _systems(_data, SystemManager::preEvent);
            _systems(_data, SystemManager::event);
            _systems(_data, SystemManager::preUpdate);
            _systems(_data, SystemManager::update);
            _systems(_data, SystemManager::preDraw);
            _systems(_data, SystemManager::draw);
            _systems(_data, SystemManager::subDraw);
        }
        _systems(_data, SystemManager::end);
    }

    int OtterCore::engineStart()
    {
        init();
        loop();
        return 0;
    }

} // namespace Otter::Core
