#include <string>
using namespace std;

int main()
{
	string astr = R"(asdf"asd")"; //로우 문자열 리터럴 
	string astr2 = R"(Line1				   
	Line2								   
	"Line3")";   //                      // Line1    
										 // Line2
										 // "Line3"             <-라고 3열 출력됨  (줄넘겨짐 !)
						  
										 //
	string str = R"-("asdasdㅂㅈㄷ\t()"-qw"t()\tt	)-";
  //string str = R"d-char-sequence(r-char-sequence)d-char-sequence" ;
  //             R"        -        (               )          -"


    ifstream file(file_name);


}