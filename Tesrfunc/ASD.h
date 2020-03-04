#pragma once
#include <vector>
#include <string>

struct StaticTester
{
    static int a;
    static std::vector<std::string> Sstring_vector;
    static std::vector<int*> Spint_vector;
};
class ASD :public StaticTester
{
public:
	ASD();
	~ASD();
};
class ASD2 :public StaticTester
{
public:
    ASD2();
    ~ASD2();

private:

};

class Tester
{
public:
    Tester();
    ~Tester();

private:

};
