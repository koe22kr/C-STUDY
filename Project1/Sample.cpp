#include <cstdio>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include<time.h>
#include <array>
#include <string>
#define off

#ifdef on


//class test {
//public:
//	test() {
//	}
//	int testest() {
//
//	}
//private:
//	int a;
//};                        이넘도 주석처리 
const std::string astring = "Message";            //아래 꺼 하기위해 전역변수.
const std::string& foo()                          //반환값이 상수+참조형
{
	
	return astring;
}
auto foo2(const std::string& string)           // 파라미터 가 상수 참조형 이고 auto 자료형이 string 자료형 으로.. (상수화 사라짐)
{
	return string;
}



auto func(int i) -> int      //auto 자리에 놓던 리턴값 타입이    -> int 로 뒤에 선언.  메인 함수도 가능
{
	return i + 2;

}

int add(int int1, int int2)
{
	std::cout << "불러올 함수 : " << __func__ << std::endl;
	return int1 + int2;
//	std::cout << __FUNCTION__ << std::endl;
}

int main(void)                           //메인 함수도  auto main() -> int   로 선언 가능 *8행 참조
{
	{
		/*std::shared_ptr<test> t = std::make_shared<test>();
		t->testest();*/ //이넘은 주석처리
		enum MyEnum
		{
			aint = 3, bint, cint

		};

		std::cout << MyEnum::aint << std::endl;
		//enum 에눔?  상수 라고함?
		switch (MyEnum::aint) {
		case 1: {std::cout << "case1" << std::endl; break; }
		case 2: {std::cout << "case2" << std::endl; break; }
		case 3: {std::cout << "case3" << std::endl; break; }
		default: std::cout << "조건 부적합" << std::endl;
		}
		std::cout << ((MyEnum::aint > 2) ? "2보다큼" : "2보다 크지않음");
		//( 계산 
		int i = 0;
		/*i = (2 + 5+7+
			1*5+4+4*
			2+2*2);
		*/
		//array
		std::array<int, 10>IntList = { 1,2,3,4,5,6 };
		std::cout << "IntList size: " << IntList.size() << std::endl;
		for (i = 0; i < IntList.size(); ++i)
		{
			std::cout << IntList[i] << " " << i << std::endl;
		}

		for (int i : IntList) {
			std::cout << i << std::endl;
		}


		std::cout << add(3, 4) << std::endl;

		std::cout << func(10) << std::endl;

		auto nresult = func(10); //리턴타입을 컴파일러 에게 맡기기. 리턴타입이 복잡할때 맡길?

		decltype(nresult) nnresult = 0; // decltype(nresult) 로 nresult의 자료형을 찾아서 그걸 자료형으로 사용.
		//
		//포인터 + 동적할당.
		int* pptr = NULL;
		int* pint = nullptr;
		pint = new int;              //new int  . 인트형 동적할당 받음. (4바이트)32비트. + 뉴 델리트. 한새트
		*pint = 15;

		delete pptr;                  // 동적할당한 메모리 반환.  new 타입으로 int 할당받으면 그게 동적으로 받는거니 델리트 해야함.
		delete pint;                 // new int 로 동적할당 받은것 반환  (강조)
		pptr = nullptr;
		pint = nullptr;

		int arraysize = 10;
		int* intarraylist = new int[arraysize];                     //인트 배열 new int[] 로 동적할당
		for (i = 0; i < arraysize; ++i)                             //
		{
			std::cout << (intarraylist[i] = i) << std::endl;
		}
		delete[] intarraylist;                                         //delete[] 로 동적할당 해제
		intarraylist = nullptr;                                    // nullptr로 지정 해제.

		//new delete ,  new[]  delete[] 짝맞춰서 사용해야함.

		//auto employee = std::make_unique<employee>();*/   //객체 오토 포인터 make_unique 하기
		//std::unique_ptr<employee> anemployee(new employee);  c++14지원 안해주면 이래 해야한담.
	}

	std::string FirstString = "This is First String.";
	std::cout << "String :" << FirstString << std::endl;




	auto f1 = foo();
	const auto& f2 = foo();
	decltype(foo()) f3 = foo();

	
	
}


#endif 
