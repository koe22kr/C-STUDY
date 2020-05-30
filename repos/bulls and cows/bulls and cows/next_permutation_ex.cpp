#include "next_permutation_ex.h"




std::vector<std::string> make_Unique_Numstr()
{
    //std::string nums = "0123456789";
    std::string nums = "123456789";

    std::vector<std::string> ret_num;
    do
    {
        ret_num.push_back(nums.substr(0, 3));//0번부터 3번 까지
       // std::reverse(nums.begin() + 3, nums.end());

    } while (std::next_permutation(nums.begin(), nums.end()));

    return ret_num;
}