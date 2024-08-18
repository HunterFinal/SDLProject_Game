#include "framework.h"

#include "time.h"

#include "system_params.h"

using namespace MSystem;

namespace MFramework
{
    Framework::Framework()
        : _time(nullptr)
    {

    }

    Framework::~Framework()
    {
        ShutDownFramework();
    }

    bool Framework::InitFramework()
    {
        _time = new MTime(MAX_DELTATIME);
        _time->StartUp();

        return true;
    }

    void Framework::UpdateFramework()
    {

    }
    void Framework::ShutDownFramework() noexcept
    {
        if(_time)
        {
            _time->ShutDown();
            delete _time;
            _time = nullptr;
        }
    }
}
