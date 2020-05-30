//프로그래머스 완주하지 못한 선수
//unordered_map 써서

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <Windows.h>
#include <ppl.h>
using namespace std;
#include <unordered_map>

template<typename Function>
size_t time_call(Function&& f)
{
    size_t begin = GetTickCount();
    f();
    return GetTickCount() - begin;
}

string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> strmap;
    for (size_t i = 0; i < completion.size(); i++)
    {
        auto result = strmap.insert(make_pair(completion[i], 1));
        if (!result.second)
        {
            strmap[completion[i]]++;
        }
    }
    for (size_t i = 0; i < participant.size(); i++)
    {
        if (strmap[participant[i]] > 0)
        {
            strmap[participant[i]]--;
        }
        else
        {
            return participant[i];
        }
    }
   



    return 0;
}

//int main()
//{
//    
//    vector<string> participant = { "leo", "kiki", "eden" };
//    vector<string> completion = { "eden", "kiki" };
//
//
//    unordered_map<string, int> tester1;
//    //insert의 리턴값 = first 에 해당 힌트 이터레이터,second에 성공여부.
//    auto te1 = tester1.insert(make_pair("1", 1));
//    auto te2 = tester1.insert(make_pair("1", 3));
//    tester1[te2.first->first]++;
//    auto as = tester1["3"];
//    cout << tester1["1"];
//    GetTickCount();
//    map<int, int> testtttt;
//    auto bbbb = testtttt[1];
//    string result;
//    size_t elapsed = time_call([&] 
//    {
//        result = solution(participant, completion);
//    });
//    //string result = solution(participant, completion);
//    //
//    //cout << result << endl;
//
//
//    int CallNum = 0;
//    int Numbers[50] = {};
//    Concurrency::parallel_for(0, 50 - 1, [&](int n) 
//    {
//
//        ++CallNum;
//        Numbers[n] += CallNum;
//
//    });
//
//
//
//
//
//    int a = 0;
//
//}