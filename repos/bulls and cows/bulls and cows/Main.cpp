#include "Main.h"

int solution(std::vector<std::vector<int>> baseball) {
    size_t case_size = baseball.size();
    int answer = 0;

    int b, s;
    bool case_result;

    for (size_t hund = 1; hund < 10; hund++)
    {
        for (size_t ten = 1; ten < 10; ten++)
        {
            if (hund==ten)
            {
                continue;
            }
            
            for (size_t one = 1; one < 10; one++)
            {
                if (hund==one||ten == one)
                {
                    continue;
                }
                // 같은숫자 중복 예외 처리는 일단 보류 TODO;
                
                for (auto& cases : baseball)//cases[3] = 세자리숫자, 스트라이크, 볼
                {
                    b = 0;
                    s = 0;
                    case_result = true;
                    /////////////////////


                    int case_one = cases[0] % 10;
                    int case_ten = cases[0] / 10 % 10;
                    int case_hund = cases[0] / 100 /*% 10*/;

                    if (hund == case_hund || ten == case_hund || one == case_hund)
                    {
                        if (hund == case_hund)
                            s++;
                        else
                            b++;
                    }
                    if (hund == case_ten || ten == case_ten || one == case_ten)
                    {
                        if (ten == case_ten)
                            s++;
                        else
                            b++;
                    }
                    if (hund == case_one || ten == case_one || one == case_one)
                    {
                        if (one == case_one)
                            s++;
                        else
                            b++;
                    }
                    

                    if (cases[1] != s || cases[2] != b)
                    {
                        case_result = false;
                        break;
                    }
                    else
                    {
                        int temp = 0;
                    }

                    //if (cases[1] == s && cases[2] == b)
                    //{
                    //    //Ok 비교해야하나?
                    //}
                    

                }
                if (case_result)
                {
                    answer++;

                }

            }

        }
        


    }

    return answer;
}




void main()
{

    std::vector<std::string> ret = make_Unique_Numstr();



    std::vector<std::vector<int>> temp = { {123, 1, 1} ,{356, 1, 0},{327, 2, 0},{489, 0, 1 } };

    int res = solution(temp);
    int aaa = 00;
}