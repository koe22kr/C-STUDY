#include <string>
using namespace std;

int main()
{
	string astr = R"(asdf"asd")"; //�ο� ���ڿ� ���ͷ� 
	string astr2 = R"(Line1				   
	Line2								   
	"Line3")";   //                      // Line1    
										 // Line2
										 // "Line3"             <-��� 3�� ��µ�  (�ٳѰ��� !)
						  
										 //
	string str = R"-("asdasd������\t()"-qw"t()\tt	)-";
  //string str = R"d-char-sequence(r-char-sequence)d-char-sequence" ;
  //             R"        -        (               )          -"


    ifstream file(file_name);


}