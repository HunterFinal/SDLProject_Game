// ----------------------------------------------------
// File         : MFramework.h
// Author       : MAI ZHICONG
// Summary      : Framework of My game
// Update Msg   : create file : 2024/08/16 23:26
// ----------------------------------------------------
#pragma once

#ifndef M_FRAMEWORK
#define M_FRAMEWORK

#include "singleton.h"
#include "m_type_define.h"

#define Time (*(MFramework::Framework::GetInstance()->GetTimeSystem()))

namespace MSystem
{
    class MTime;
}

namespace MFramework
{    

    using MDesignPattern::MSingleton::Singleton;

    class Framework : public Singleton<Framework>
    {
        friend class Singleton<Framework>;
        friend class FrameworkHelper;

        public:
            bool InitFramework();
            void UpdateFramework();
            void ShutDownFramework() noexcept;

        public:
            MSystem::MTime* GetTimeSystem();

        private:
            Framework();
            ~Framework();

        private:
            MSystem::MTime* _time;
    };  

}

#endif
