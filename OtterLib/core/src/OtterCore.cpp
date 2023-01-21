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
        _systems(_data, "init");
        while (this->_isRunning) {
            _systems(_data, "preEvent");
            _systems(_data, "event");
            _systems(_data, "preUpdate");
            _systems(_data, "update");
            _systems(_data, "predraw");
            _systems(_data, "draw");
            _systems(_data, "subDraw");
        }
    }

    int OtterCore::engineStart()
    {
        init();
        loop();
        return 0;
    }

} // namespace Otter::Core
