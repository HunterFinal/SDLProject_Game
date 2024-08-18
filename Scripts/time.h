#pragma once

#include "m_type_define.h"

namespace MSystem
{
    class MTime
    {
        // type alias
        using MaxDeltaTime = float;
        using Time = std::chrono::steady_clock::time_point;
      
    public:
        MTime(const MaxDeltaTime);
        ~MTime();

    private:
        // copy disable
        MTime(const MTime&) = delete;
        MTime& operator=(const MTime&) = delete; 

    public:
        void StartUp();
        void UpdateTime();
        void ShutDown() noexcept;

    private:
        float _deltaTime;
        float _maxDeltaTime;

        Time _currentTime;
        Time _previousTime;

        uint8 _isActive : 1;

    public:
        float GetDeltaTime() const; 
        float GetCurrentTime() const;
    };
}