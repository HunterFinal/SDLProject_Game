#include "framework.h"

#include "time.h"

#include "system_params.h"


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
        _time = new MSystem::MTime(MAX_DELTATIME);
        _time->StartUp();

        return true;
    }

    void Framework::UpdateFramework()
    {
        _time->UpdateTime();
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
    MSystem::MTime* Framework::GetTimeSystem()
    {
        assert(_time);

        return _time;
    }
}
