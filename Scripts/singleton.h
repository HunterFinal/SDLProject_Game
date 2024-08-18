// ---------------------------------------------------------------------------------------------------------------------------------------
// File name:           singleton.h
// Version:             v1.0
// Description:         A template singleton class
// Namespace:           MDesignPattern::MSingleton
// Note:                Example
//                          class SingletonClass :: public Singleton<SingletonClass>
//                          {
//                              friend class Singleton<SingletonClass>;
//                              private:
//                                  SingletonClass() = default;             // Constructor and Destructor need to be private or protected
//                                  ~SingletonClass() = default;            
//                          }
// Update:              2024/06/17  Create
//                      2024/08/15  Change GetInstance to raw-pointer(it was shared_ptr before)
//                                  Add Singleton GC(prevent memory leak if someone forget to release manually)
//
// Author:              MAI ZHICONG
// ---------------------------------------------------------------------------------------------------------------------------------------

#pragma once

//#include <memory>   // std::shared_pt

#include "thread_safe_def.h"
#include <assert.h>

namespace MDesignPattern
{
    namespace MSingleton
    {
        // シングルトン
        template<typename T>
        class Singleton
        {
        private:
            
            // GC class
            class SingletonGC
            {
                public:
                    ~SingletonGC()
                    {
                        if(_instance)
                        {
                            // TODO need test
                            delete _instance;
                            _instance = nullptr;
                        }
                    }
            };

        public:
            //
            // smart pointer version
            //
            // static inline std::shared_ptr<T> GetInstance()
            // {
            //     // インスタンス生成は一回しか実行しない
            //     static std::once_flag flag;
            //     std::call_once(flag,[&]()
            //     {
            //         _instance = std::shared_ptr<T>(new T);
            //     });

            //     return std::make_shared<T>(_instance);
            // }

            /// <summary>
            /// シングルトンを初期化する
            /// </summary>
            /// <typeparam name="...Args">初期化子</typeparam>
            /// <param name="...args"></param>
            template<typename... Args>
            static inline void CreateInstance(Args... args)
            {
                if (!_instance)
                {
                    LOCK(_padlock)
                    if (!_instance)
                    {
                        _instance = new T(args...);
                    }
                }
            }
            static inline T& GetInstance()
            {
                assert(!_instance);

                return *_instance;
            }

            static inline void ReleaseInstance()
            {
                if(_instance)
                {
                    delete _instance;
                    _instance = nullptr;
                }
            }


        protected:
            Singleton() = default;
            virtual ~Singleton() = default;

        private:
            Singleton(const Singleton&) = delete;
            Singleton& operator=(const Singleton&) = delete;

        //private:
        //    void operator delete(void* ptr) noexcept
        //    {
        //        ((T*)ptr)->~T();
        //        free(ptr);
        //    }

        private:
            static T* _instance;
            static std::mutex _padlock;
            static SingletonGC _gcObj;
        };

        // static member initialize
        template<typename T>
        T* Singleton<T>::_instance = nullptr;
        template<typename T>
        std::mutex Singleton<T>::_padlock;
        // TODO
        // need typename in front of it(tell compiler it is a type)
        template<typename T>
        typename Singleton<T>::SingletonGC Singleton<T>::_gcObj;

    }// namespace MSingleton

}// namespace MDesignPattern
