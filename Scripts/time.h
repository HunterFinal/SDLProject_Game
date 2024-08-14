#pragma once

#include "singleton.h"

using MDesignPattern::MSingleton::Singleton;
 
class MTime : public Singleton<MTime>
{
    friend class Singleton<MTime>;
private:
    // 外部からのインスタンス作成禁止
    MTime() = default;

public:
    ~MTime() = default;

private:
    // copy disable
    MTime(const MTime& other) = delete;
    MTime& operator=(const MTime& other) = delete; 

public:
    void UpdateDeltaTime(const float deltaTime);

private:
    static float _sDeltaTime;

public:
    static float GetDeltaTime();  
};