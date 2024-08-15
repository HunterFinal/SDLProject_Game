

#pragma once

#include "singleton.h"

using MDesignPattern::MSingleton::Singleton;
 
namespace MSystem
{
    class MTime : public Singleton<MTime>
    {
        // type alias
        using MaxDeltaTime = float;

        // friend class
        friend class Singleton<MTime>;
        
    private:
        // �O������̃C���X�^���X�쐬�֎~
        // �f���^�^�C���̍ő�l���R���X�g���N�^�ɓn��
        MTime(const MaxDeltaTime);
        ~MTime();

    private:
        // copy disable
        MTime(const MTime& other) = delete;
        MTime& operator=(const MTime& other) = delete; 

    public:
        void UpdateTime();

    private:
        float _deltaTime;
        float _currentTime;
        float _previousTime;
        float _maxDeltaTime;

    public:
        float GetDeltaTime() const; 
        float GetCurrentTime() const;
    };
}