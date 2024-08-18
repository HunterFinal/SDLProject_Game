// ----------------------------------------------------
// File         : MFramework.h
// Author       : MAI ZHICONG
// Summary      : Framework of My game
// Update Msg   : create file : 2024/08/16 23:26
// ----------------------------------------------------

#include "singleton.h"
#include "m_type_define.h"

class MSystem::MTime;

namespace MFramework
{  
    using MDesignPattern::MSingleton::Singleton;

    using TimeSystem = MSystem::MTime;

    class Framework : public Singleton<Framework>
    {
        friend class Singleton<Framework>;
        friend class FrameworkHelper;

        public:
            bool InitFramework();
            void UpdateFramework();
            void ShutDownFramework() noexcept;

        private:
            Framework();
            ~Framework();

        private:
            TimeSystem* _time;
    };  

}
