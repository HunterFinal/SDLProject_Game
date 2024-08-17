#include "framework.h"

namespace MFramework
{

    void Framework::RegisterStaticSystem(ConstString& name, IStaticSystem* system)
    {
        assert(!name.empty());
        assert(system);

        if(_staticSystems.contains(name))
        {
            //TODO pop error window
            return;
        }

        _staticSystems.emplace(name,system);
    }
    void Framework::RegisterDynamicSystem(ConstString& name, IDynamicSystem* system,const ESystemPriority priority)
    {
        assert(!name.empty());
        assert(system);
        assert(priority != ESystemPriority::None);

        auto& dynamicSystemTable = _dynamicSystems[priority];
        if(dynamicSystemTable.contains(name))
        {
            //TODO pop error window
            return;
        }

        dynamicSystemTable.emplace(name,system);
    }
    void Framework::UpdateFramework()
    {
        for(auto& table : _dynamicSystems)
        {
            if(table.second.count() < 1)
            {
                
            }
        }
    }
}