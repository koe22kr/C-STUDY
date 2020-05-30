#pragma once
#include <memory>


template<typename T>
class My_Object_Pool
{
    std::shared_ptr<T> m_Sptr;
    std::weak_ptr<T> m_Wptr;



public:
    My_Object_Pool();
    virtual ~My_Object_Pool();
};


template<typename T>
My_Object_Pool<T>::My_Object_Pool()
{
}

template<typename T>
My_Object_Pool<T>::~My_Object_Pool()
{
}
