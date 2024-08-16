// ----------------------------------------------------
// File         : ISystem.h
// Author       : MAI ZHICONG
// Summary      : Framework System Interface
// Update Msg   : create file : 2024/08/17 0:11
// ----------------------------------------------------

#pragma once

namespace MFramework
{
    class ISystem
    {
        public:
            virtual void InitSystem()   = 0;
            virtual void UpdateSystem() = 0;
            virtual void TermSystem()   = 0;
        public:
            virtual ~ISystem() { TermSystem(); }
    };
}

