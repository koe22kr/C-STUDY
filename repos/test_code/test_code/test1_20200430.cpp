//프로그래머스 완주하지 못한 선수

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//string solution(vector<string> participant, vector<string> completion)
//{
//
//    sort(participant.begin(), participant.end());
//    sort(completion.begin(), completion.end());
//    for (size_t i = 0; i < completion.size(); i++)
//    {
//        if (participant[i]!= completion[i])
//        {
//          
//            return  participant[i];
//        }
//    }
//
//    return  participant[participant.size() - 1];
//}
//
//int main()
//{
//    vector<string> participant = { "leo", "kiki", "eden" };
//    vector<string> completion = { "eden", "kiki" };
//
//    string result = solution(participant, completion);
//    
//    cout << result << endl; 
//    
//    int a = 0;
//
//}