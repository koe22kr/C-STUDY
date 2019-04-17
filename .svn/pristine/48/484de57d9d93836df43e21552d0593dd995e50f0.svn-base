#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#define off
#ifdef on
int main()
{
	// 유니폼 초기화를 이용해서 string 의 vector 생성
	std::vector<std::string> myVector = { "A first string","A second string" };

	//몇몇 string 은 push_back 메서드를 이용해서 vector에 추가
	myVector.push_back("A third string");
	myVector.push_back("The last string in the vector");
	//push_back 이 뭔지 찾아보자 09:12
	
	//구간 지정 for 루프를 이용해서 항목 출력.
	for (const auto& str : myVector)
		std::cout << str << std::endl;

	//반복자를 이용해서 vector를 순회하면서 한 번 더 항목 출력
	for (auto iterator = cbegin(myVector);
		iterator != cend(myVector); ++iterator) {
		std::cout << *iterator << std::endl;
		}
	
	return 0;
	   
	int i = 0, j = 0;
	int a = ((i++) + (++j));
	return 0;
}
#endif