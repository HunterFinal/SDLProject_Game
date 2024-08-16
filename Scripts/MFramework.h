// ----------------------------------------------------
// File         : MFramework.h
// Author       : MAI ZHICONG
// Summary      : Framework of My game
// Update Msg   : create file : 2024/08/16 23:26
// ----------------------------------------------------

#include <vector>
#include "singleton.h"

class ISystem;

namespace MFramework
{  
    using MDesignPattern::MSingleton::Singleton;

    class Framework : public Singleton<Framework>
    {
        friend class Singleton<Framework>;

        public:
            void RegisterSystem(ISystem*);
            void UpdateFramework();
        private:
            std::vector<ISystem*> _systems;
    };
}