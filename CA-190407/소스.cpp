#include<iostream>

int ex = 99;


namespace aaa 
{
	int a = 1;
	
		namespace aab {

			namespace abb {

				namespace bbb {

					int bbb = 22;
				}
			}
		}
}



namespace bbb {

	int b = 1;
}

void main()
{
	
char alist[]="HelloWorld";
alist[5] = '1';
alist[10] = '3';   //¿À¹ö·± ¤¸¤¸

//alist[11] = '4';
//alist[12] = '5';
		int bbc = 0;
		int ex = 11;

		aaa::aab::abb::bbb::bbb = 10;
		std::cout << aaa::aab::abb::bbb::bbb << std::endl;
		std::cout << ::ex<< std::endl;



}