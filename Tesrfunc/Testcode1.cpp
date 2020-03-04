#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <map>
#include "ASD.h"
using namespace std;
//throw std::out_of_range("");
//ifstream file(char file_name); // ???
//
//class test
//{
//public:
//    explicit test(int& a) :x(a) {};
//  explicit operator int() { return x; }
//    ~test();
//    int x;
//};
//test::~test()
//{
//
//}
constexpr int testfunc(int n)
{
    return n - 1;
}

int main()
{
 //   string astr = R"(asdf"asd")"; //로우 문자열 리터럴 
 //   string astr2 = R"(Line1				   
	//Line2								   
	//"Line3")";   //                      // Line1    
 //                                        // Line2
 //                                        // "Line3"             <-라고 3열 출력됨  (줄넘겨짐 !)

 //                                        //
 //   string str = R"-("asdasdㅂㅈㄷ\t()"-qw"t()\tt	)-";
 //   //string str = R"d-char-sequence(r-char-sequence)d-char-sequence" ;
 //   //             R"        -        (               )          -"

 //    // double abc=3.14;
 //    // test testclass(abc);//explecit
 //    // int a = testclass;


 //   string buffer = "20 10";
 //   
//    double dbl1 = 12.34541f;
//    cout << setw(10)<<fixed<< setfill('a') << dbl1 << endl;
//    cout <<setw(11)<<setfill('@')<< noshowpoint << dbl1 << endl;
//    cout << setw(12) << dbl1 << endl;    
    //time_t t_t = time(nullptr);
    //tm t;
    //
    //localtime_s(&t, &t_t);
    //cout << put_time(&t, "%c") << endl;

   //stringstream strstream;
   //ostringstream ostrstream;
   //istringstream istrstream;
   //string ostrstream2;
   //string a;
   //string b;
   //string c;
   //int a1;
   //int b1;
   //
   //char ch;

    //while (cin)
    //{
    //    string str;
    //    cout << "::";
    //    cin >> str;
    //    if (str == "done")
    //    {
    //        break;
    //    }
    //    strstream << str;
    //}
    //cout << strstream.str() << endl;
   // ostrstream << "abc bc c 12 3";
    //strstream.str() = ostrstream;
   // strstream << ostrstream.str();
   // strstream >> a >> b >> c >> a1 >> b1;
    //long longg = 100;
    //char lint=static_cast<char>(longg);
    //void* anyvoid = reinterpret_cast<void*>(longg);
    //const int max_int = INT_MAX;
    //const int min_int = INT_MIN;
    //const int in = WINT_MAX;
    //const long max_long = LONG_MAX;
    //
    //const unsigned int uint = UINT_MAX;
    const unsigned long long ulong = ULLONG_MAX;
    //const unsigned uint2 = numeric_limits<unsigned int>::max();
    //const unsigned ulong2 = numeric_limits<unsigned long>::max();
    //const unsigned uint3 = numeric_limits<unsigned int>::infinity();
    //const unsigned ulon3 = numeric_limits<unsigned long>::infinity();
    //int bada = 00;
    //   
    //size_t ttt = -1;
    //ptrdiff_t yyy = -1;
    //int asdasf = 0;

    //int a = -1;           // 0xFFFFFFFFi32
    //ptrdiff_t b = a;      // 0xFFFFFFFFFFFFFFFFi64
    //size_t c = size_t(b); // 0xFFFFFFFFFFFFFFFFui64
    //size_t d = numeric_limits<size_t>::max();
    //int result1 = 1 << 30;
    //size_t result2 = 1 << 30;
   //int array[4] = { 1, 2, 3, 4 };
   //enum ENumbers { ZERO, ONE, TWO, THREE, FOUR };
   ////safe cast (for MSVC2005)
   //ENumbers *enumPtr = (ENumbers *)(array);
   //cout << enumPtr[0] << enumPtr[1] << enumPtr[2] << enumPtr[3] << enumPtr[4] << " ";
   ////unsafe cast
   //size_t *sizetPtr = (size_t *)(array);
   //cout << sizetPtr[0] << endl;
    //char a[10] = { "abc" };
    
    //memcpy(a, nullptr, 0);
   /* map<wstring, int> intmap;

    wstring astr = L"ASTR";
    wstring bstr = { L"A" };
    wstring cstr = { L"B" };
    intmap.insert(make_pair(astr, 1));
    intmap.insert(make_pair(bstr, 5));
    intmap.insert(make_pair(cstr, 7));
    auto b = L"ASTR";
    wchar_t c[10] = { L"B" };
    auto iter = intmap.find(L"A");
    int k = 0;
    iter = intmap.find(cstr.c_str());
    k = 9;
    iter = intmap.find(astr);
    k = 8;
*/

  //  struct test
  //  {
  //      unsigned int a : 1;
  //      unsigned int b : 1;
  //      unsigned int c : 1;
  //      unsigned int d : 1;

  //      unsigned int e : 1;
  //      unsigned int f : 1;
  //      unsigned int g : 1;
  //      unsigned int h : 1;

  //      unsigned int a1: 1;
  //      unsigned int a2: 1;
  //      unsigned int a3: 1;
  //      unsigned int a4: 1;
  //      unsigned int a5: 1;
  //      unsigned int a6: 1;
  //      unsigned int a7: 1;
  //      unsigned int a8: 1;
  //      unsigned int b3: 16;

  //      //unsigned int a0 : 1;

  //  };
  //  test as;
  //  as.a = 3;
  //  as.b = 7;
  //  as.c = 31;
  //  cout << as.a << as.b << as.c << endl;
  //  int d = sizeof(test);
  //  
  //  //  int  b=1;
  ////  int c=2;
  ////  int d=9;
  ////  int a = static_cast<int>(b, c, d);

  //  int retun = 0;
    ASD Stester1;
    ASD2 Stester2;
    Stester1.a = 9;
    Stester1.a = 5;

    Stester2.a = 22;
    Stester2.a = 33;

    Stester1.a = 99;
    std::vector<Tester*> testlist;
    Tester* tester1 = new Tester;
    Tester* tester2 = new Tester;
    testlist.push_back(tester1);
    testlist.push_back(tester2);

    int kk = 99;
    testlist.clear();

    


    struct Tester
    {
        int xxx;
        int yyyy;

    };
    int ll = 13;
    int const1 = testfunc(kk);
    int const2 = testfunc(ll+3);

    return 0;
}