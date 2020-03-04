// Constexpr_Tester.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "Tester.h"
#include <sstream>
#include <iomanip>
#include <functional>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>

const int const_tester(int i)
{
    return i + 2;
}

int main()
{
    


        std::cout << "Number of lowercase letters in \"Hello, world!\" is ";

        // "Hello, world!"가 ConstString으로 암시적 형반환되어, CountLowercase 함수의 인자로 넘어감.
        // CountLowercase는 컴파일 타임에 평가되었고, 그 결과를 가지고 ConstN 역시 컴파일 타임에 결정됨.
      //  ConstN<CountLowercase("Hello, worlddd2!")> out;
        const char tem[] = "Hello, Worldm";
        int a = 1;
        int b = 2;


        const int c = const_tester(a);


        double F;

        std::stringstream ss;
        std::string in = "String with spaces, and embedded \"quotes\" too";
        std::string out;

        ss << std::quoted(in);
        std::cout << "read in     [" << in << "]\n"
            << "stored as   [" << ss.str() << "]\n";

        ss >> std::quoted(out);
        std::cout << "written out [" << out << "]\n"
            << "and" << ss.str() << std::endl;


        F=Fibonacci<5>::value;
        a = 0;
        F=fibonacci(5);
        a = 0;


        std::string teststr = "hello world";
        int as = std::extent<decltype(out)>::value;
        std::cout << std::extent<decltype(out.c_str())>::value;
        
        std::size_t str_hash = std::hash<std::string>{}(teststr);
        std::size_t str_hash2 = std::hash<int>{}(as);

        std::size_t my_hash = str_hash ^ str_hash2;


        struct A { double x; };
        A* aaa;
        decltype(aaa->x) y=F;
        decltype ((aaa->x)) u = y;
        F = 9;
        y = 8;
        u = 6;
        //as = 7;
        const std::type_info& ti1 = typeid(as);
        const std::type_info& ti2 = typeid(int);
        std::size_t hash_int = std::hash<int>{}(as);
        //const std::type_info ti2 = typeid(*aaa).before;
        //const std::type_info ti3 = typeid(*aaa).hash_code;
        //const std::type_info ti4 = typeid(*aaa).name;
        std::cout << ti1.name() << '\n' << ti1.raw_name()<< '\n' << ti1.hash_code();
        std::cout << ti2.name() << '\n' << ti2.raw_name() << '\n' << ti2.hash_code();
        const std::type_info& r1 = typeid(std::cout << as);

        std::size_t str_hash3 = std::hash<int>{}(as);

        return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
