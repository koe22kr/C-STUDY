#include <algorithm>
#include <vector>
#include <string>
#include <array>
#include <iostream>

#include <Windows.h>
struct member_info
{
    uint32_t age;
    std::string name="none";
    member_info(int in) :age(in)
    {
        
    }
    member_info(int in,std::string str):age(in),name(str)
    {

    }
    bool operator==(int in)
    {
        return age == in;
    }
    member_info& operator=(int in)
    {
        age = in;
        return *this;
    }
};




void main()
{

#pragma region make_case

#pragma endregion

    //���� �۾� partition
    auto is_even = [](int i) { return i % 2 == 0; };
    std::vector<int> Vector_int = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> Vector_true(10);
    std::vector<int> Vector_false(10);
    std::vector<int> Vector_copy(10);
    auto is_not_partitioned = std::is_partitioned(Vector_int.begin(), Vector_int.end(), is_even);

    auto partition = std::partition(Vector_int.begin(), Vector_int.end(), is_even);
    auto is_partitioned = std::is_partitioned(Vector_int.begin(), Vector_int.end(), is_even);

    
    auto partition_copy = std::partition_copy(Vector_int.begin(), Vector_int.end(), Vector_true.begin(), Vector_false.begin(), is_even);//true, false �ٷ� ����.

    Vector_int = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };//�ʱ�ȭ
   auto stable_partition = std::stable_partition(Vector_int.begin(), Vector_int.end(), is_even);  //246813579
   
   auto partition_point = std::partition_point(Vector_int.begin(), Vector_int.end(), is_even); //2468 '1' 3579 1�� ���ͷ�����.
   //////

   //���� sort
   Vector_int = { 1, 2, 3, 4, 5,4, 6, 7, 8, 9 };//���� �ʱ�ȭ
   auto is_sorted = std::is_sorted(Vector_int.begin(), Vector_int.end());
   auto is_sorted_until = std::is_sorted_until(Vector_int.begin(), Vector_int.end());//���ĵ� ����� �� ���� ���ͷ����� ��ȯ
   auto sorted_size = is_sorted_until - Vector_int.begin(); // ���ĵ� ��� ����



   Vector_int = { 1, 3, 5, 7, 9, 2, 4, 6, 8 };//������ �ʱ�ȭ
   std::sort(Vector_int.begin(), Vector_int.end());// ����� sort
   
   Vector_int = { 1, 3, 5, 7, 9, 2, 4, 6, 8 };//������ �ʱ�ȭ
   std::partial_sort(Vector_int.begin(), Vector_int.begin() + 5, Vector_int.end());//temp�� ���� �� n������ŭ ������ ����
   
   Vector_int = { 1, 3, 5, 7, 9, 2, 4, 6, 8 };//������ �ʱ�ȭ
   std::partial_sort_copy(Vector_int.begin(), Vector_int.end(), Vector_copy.begin(), Vector_copy.end());//���� ����


   std::vector<member_info> Vector_member = { {20,"kim"},{20,"bak"},{19,"rim"},{21,"vec"} };
   std::stable_sort(Vector_member.begin(), Vector_member.end(), [](member_info lhs, member_info rhs) {return lhs.age < rhs.age; });//�������� ���� ���� ����.

#pragma region make_case
   Vector_int.resize(40);
   int counter = 0;
   for (int& elm : Vector_int)
   {
       elm = counter++;
   }
   std::random_shuffle(Vector_int.begin(), Vector_int.end());
#pragma endregion
   std::nth_element(Vector_int.begin(), Vector_int.begin() + 5, Vector_int.end()); //n�� ����� ���ĸ� �����.
                                                                                   //������ > n > ū��
#ifdef Active_Testcode

#pragma region Tested_code

   std::vector<member_info> mem_testcase1, mem_testcase2;

   Vector_int.resize(40000);
   for (size_t i = 0; i < Vector_int.size(); i++)
   {
       Vector_int[i] = i * i * 32;
       mem_testcase1.push_back(i*i * 32);
   }
   std::random_shuffle(Vector_int.begin(), Vector_int.end());
   std::random_shuffle(mem_testcase1.begin(), mem_testcase1.end());
   mem_testcase2 = mem_testcase1;
   std::vector<int> testcase = Vector_int;
   std::vector<int> testcase2 = Vector_int;
   std::vector<int> testcase3 = Vector_int;



   DWORD start, tick;

   start = GetTickCount();
   std::partial_sort(mem_testcase1.begin(), mem_testcase1.begin() + 1500, mem_testcase1.end(), [&](member_info lhs, member_info rhs) {return lhs.age < rhs.age; });//62 tick
   tick = GetTickCount() - start;
   std::cout << tick << std::endl;

   start = GetTickCount();
   std::nth_element(mem_testcase2.begin(), mem_testcase2.begin() + 1500, mem_testcase2.end(), [&](member_info lhs, member_info rhs) {return lhs.age < rhs.age; });//140 tick
   tick = GetTickCount() - start;
   std::cout << tick << std::endl;

   start = GetTickCount();
   std::sort(mem_testcase1.begin(), mem_testcase1.end(), [&](member_info lhs, member_info rhs) {return lhs.age < rhs.age; }); //1266 tick
   tick = GetTickCount() - start;
   std::cout << tick << std::endl;

   start = GetTickCount();
   std::stable_sort(mem_testcase2.begin(), mem_testcase2.end(), [&](member_info lhs, member_info rhs) {return lhs.age < rhs.age; });//968 tick
   tick = GetTickCount() - start;
   std::cout << tick << std::endl;

#pragma endregion

#endif // Active_Testcode

    int end = 0;

    
}



