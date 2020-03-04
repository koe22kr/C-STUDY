#include <iostream>
#include <vector>
using namespace std;
//#define Base_Plus
//#define VirtualFunc

int main()
{
    float a = 10.11f;
    int b = 5;
    int c = 15;
    c < b*a * b;

    return 0;
}

#ifdef first
class test
{
public:
    int a = 1;
    int b = 2;
    int c = 3;
    test() {};
    ~test() {};

private:

};
void main()
{
    vector<int> v_int;
    vector<string> v_string;
    vector<test> v_test;


    int temp = v_int; //fail
}
#endif
#ifdef Base_Plus



class Base
{
public:
	Base() { cout << "base func :" << sizeof(this) << endl; };
	~Base() {};
	int a;
	int b;    //8


};

class Plus :public Base
{
public:
	Plus() { cout << "plus func :" <<sizeof(this)<< endl; };
	~Plus() {};
	char alist[33] = { "abcd" };   //40


};



int main()
{
	Base* pbase = new Base;
	Plus* pplus = new Plus;

	
	Base* test = new Plus;
	test->a = 1;
	test->b = 2;
	test = pplus;
	//pplus = test;
	Base* test2 = pplus;
	test2->a = 3;
	test2->b = 4;

	pbase->a = 5;
	pbase->b = 6;


	pplus->a = 7;
	pplus->b = 8;


	return 0;
}

#endif 

#ifdef VirtualFunc

class first
{
public:
	int a=1;
	int b=1;
	int c=1;

	first();
	~first();
	void func()
	{
		cout << a << " " << b << " " << c << " " << a * b*c << " " << "first" << endl;
	}


};

first::first()
{
	b = 2;
	func();
}

first::~first()
{
}
class second : public first
{
public:

	second();
	~second();

 void func()
	{
		
		cout << a << " " << b << " " << c << " " << a * b*c << " " << "second" << endl;
	}

};

second::second()
{
	c = 3;
	func();
}


second::~second()
{
}
class third : public second
{
public:
	
	third();
	~third();
	
 void func()
	{
		
		cout << a <<" "<< b << " " << c << " " << a * b*c << " " << "third" << endl;
	}





};

third::third()
{
	func();
	
	

}

third::~third()
{
}

int main()
{

	first* a = new first;
	second* b = new second;
	third* c = new third;
	
	
	
	third* t = new third;

	second* s = t;
	s->func();
	first* f = s;
	f->func();

	second* s2 = new third;
	second* s3 = new second;
	

	first* f2 = new third;
	first* f3 = new second;
	first* f4 = new first;

	










	return 0;
}


#endif // VirtualFunc

#ifdef DEBUG

#include <stdio.h>
#include <string.h>
#include <tchar.h>
int main()
{
    char name[5][10];
    int i, n;
    n = 3;

    printf(" [%d] 명의 이름 입력\n 학", n);
    FILE* fp = NULL;
    fopen_s(&fp, _T("김형기.txt"), "rt");
    for (i = 0; i < n; i++)
    {


        printf(" [%d]번째 이름 : ", i);
        fgets(name[i], sizeof(char[10]), fp);
        //name[i][strlen(name[i]) - 1] = 0;
    }

    puts(" \n * 출 력 * ");
    for (i = 0; i < n; i++)
    {
        printf(" [%d]번 째 이름 ==> %s", i, name[i]);
    }

    return 0;
}
#endif // DEBUG
