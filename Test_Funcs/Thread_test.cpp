#include <memory>
#include <iostream>
#include <process.h>
#include <Windows.h>
#include <vector>
#include <map>
using namespace std;
int i = 0;
class Dest_test
{
public:
    int a = 0;
    Dest_test(const Dest_test& dest);
    Dest_test();
    ~Dest_test();

private:

};
Dest_test::Dest_test(const Dest_test& dest)
{
    a = dest.a;
    cout << "Copy" << endl;
}
Dest_test::Dest_test()
{
    cout << "Create" << endl;
}

Dest_test::~Dest_test()
{
    cout << "Destruct" << endl;
}
unsigned int WINAPI Thread_func(LPVOID thread_id)
{
    while (true)
    {
        std::cout << thread_id << std::endl;
        Sleep(2000);
    }
    
}
unsigned int WINAPI Thread_func2(LPVOID dummy)
{
    while (true)
    {
        std::cout << "asdf" << std::endl;
        Sleep(2000);
    }
}

void make_thread(unsigned int& m_hThread, unsigned int& thread_id)
{
    m_hThread = _beginthreadex(NULL, 0, Thread_func2, nullptr, 0, &thread_id);

}

void main()
{

     std::vector<unsigned int> thread_handles;
     std::vector<unsigned int> thread_ids;
     unsigned int temp1[3] = { 0 }, temp2[3] = { 0 };
     for (; i < 3; i++)
     {
         make_thread(temp1[i], temp2[i]);
     }
    
 
    Dest_test one;
    Dest_test two;

    vector< Dest_test> tester;

    tester.push_back(one);
    tester.push_back(two);

    int a = 0;

    tester.clear();

    int b = 0;
    while (true)
    {
        int a = 0;
    }
}