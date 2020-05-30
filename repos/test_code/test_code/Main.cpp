
#include <unordered_map>
#include <list>
#include <iostream>

class Base_Functor
{
public:
    virtual bool Execute() {};
    {
        virtual Base_Functor* Get() { return this; };
        Base_Functor() {};
        virtual ~Base_Functor() {};
    }
};

class isRunning_Functor : public Base_Functor
{
public:
    virtual bool Execute() {};
    {
    isRunning_Functor* Get() { return this; };
    isRunning_Functor() :Base_Functor() {};
    }
};
class Connect_Functor;


void main()
{

    ////////////////////////////////////////////////
    //init

    Base_Functor* running = new isRunning_Functor();
    

    std::unordered_map<int, Base_Functor*> func_map;
    //func_map[key]=
    //
    //
    std::list<std::list<Base_Functor*>> Execute_List;


    ////////////////////////////////////////////////
    //Load

    //for (size_t i = 0; i < main_size; i++)
    //{


   // for (size_t i = 0; i < sub_size; i++)
   // {
   //
   //[0][n] if문 배열 추가
    std::list<Base_Functor*> temp_sub_list;
    temp_sub_list.push_back(running);
   //
   // }


    //}

    Execute_List.push_back(temp_sub_list);

    ////////////////////////////////////////////////
    //Excute
    for (size_t i = 0; i < main_size; i++)
    {
        for (size_t j = 0; j < sub_size; j++)
        {
            bool bresult = Execute_List[i][j].Excute(); //
            if (Execute_List[i].size() > 1 && !bresult) //if문 예외처리
            {
                break;
            }
        }
    }
        
}





