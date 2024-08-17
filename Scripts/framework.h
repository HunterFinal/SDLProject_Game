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

// 更新する必要があるシステム
class IDynamicSystem;

class IStaticSystem;

namespace MFramework
{
    // システム実行優先順位
    // TODO もっといい方法があるか
    // システム間の依存関係を考慮した上で作った
    enum class ESystemPriority : uint8
    {
        None        = 0,    // 優先順位なし
        High        = 1,    // 一番優先
        Mid_High    = 2,    // ちょっと優先
        Middle      = 3,    // そこそこ優先
        Mid_Low     = 4,    // 優先しなくていい
        Low         = 5,    // 重要でない
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