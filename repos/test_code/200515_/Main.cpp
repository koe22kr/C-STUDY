#include "Main.h"
#include <list>
#include <iostream>
#include <string>
#include <memory>

class LogPrinter
{
public:
    LogPrinter() = delete;
    LogPrinter(std::string&& log)
    {
        /*Print Log*/ 
        std::cout << "Print Log!" << std::endl;
        std::cout << log << std::endl;
    }
};

enum class Event
{
    A,
    B,
    C
};

class Observer
{
public:
    virtual void OnNotify(Event event) {/*if A, B, C ~~*/};
    
};


class Subject
{
public:
    void AddObserver(std::weak_ptr<Observer>& observer)
    {
        mObserber_List.push_back(observer);
    };
    void DeleteObserver(std::weak_ptr<Observer>& wptr)
    {
        mObserber_List.remove(wptr);
    };
    void Notify(Event notify)
    {
        for (auto& wptr :mObserber_List)
        {
            auto sptr = wptr.lock();
            if ((wptr.lock() != nullptr))
            {
                sptr->OnNotify(notify);
            }
      
        }
    }
    void RefreshObserver()
    {
        for (auto _Cur = mObserber_List.begin(); _Cur != mObserber_List.end(); )
        {
            if (_Cur->lock() == nullptr)
                mObserber_List.erase(_Cur);
            else
                ++_Cur;
        }
    }
private:
    std::list<std::weak_ptr<Observer>> mObserber_List; //
};



class base
{
public:

private:

};

class Derived :public base
{
public:

private:

};

void main()
{
    base* pBase = new Derived;
    Derived* pDerived;
    //pDerived = pBase;
    pDerived = static_cast<Derived*>(pBase);



    LogPrinter("Log!");
    LogPrinter(std::string("Log2"));
}