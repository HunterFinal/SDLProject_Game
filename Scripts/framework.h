// ----------------------------------------------------
// File         : MFramework.h
// Author       : MAI ZHICONG
// Summary      : Framework of My game
// Update Msg   : create file : 2024/08/16 23:26
// ----------------------------------------------------

#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include "singleton.h"
#include "m_type_define.h"

// �X�V����K�v������V�X�e��
class IDynamicSystem;

class IStaticSystem;

namespace MFramework
{
    // �V�X�e�����s�D�揇��
    // TODO �����Ƃ������@�����邩
    // �V�X�e���Ԃ̈ˑ��֌W���l��������ō����
    enum class ESystemPriority : uint8
    {
        None        = 0,    // �D�揇�ʂȂ�
        High        = 1,    // ��ԗD��
        Mid_High    = 2,    // ������ƗD��
        Middle      = 3,    // ���������D��
        Mid_Low     = 4,    // �D�悵�Ȃ��Ă���
        Low         = 5,    // �d�v�łȂ�
    };
    
    using MDesignPattern::MSingleton::Singleton;

    using ConstString = const std::string;
    using SystemName = std::string;

    class Framework : public Singleton<Framework>
    {
        public:
            void UpdateFramework();

        private:
            template<typename T>
            T* getSystem(ConstString&);

        private:
        // TODO need refactoring
            struct SystemInfo
            {
                ESystemPriority Priority;
                std::string SystemName;

                bool operator <(const SystemInfo& other)
                {
                    return Priority < other.Priority;
                }
            };

        friend class Singleton<Framework>;
        friend class FrameworkHelper;

        using DynamicSystemTable = std::map<SystemName,IDynamicSystem*>;
        using StaticSystemTable = std::map<SystemName,IStaticSystem*>;


        private:
            void RegisterStaticSystem(ConstString&,IStaticSystem*);
            void RegisterDynamicSystem(ConstString&,IDynamicSystem*,const ESystemPriority);

        private:
            StaticSystemTable _staticSystems;

            std::map<SystemInfo,DynamicSystemTable,std::less<SystemInfo>> _dynamicSystems;

        private:
            Framework();
            ~Framework();
    };  

    class FrameworkHelper
    {
        #define Time Framework::GetSystem("Time");
        public:
            template<typename T>
            T* GetSystem(ConstString&);
    };

}