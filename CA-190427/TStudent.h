#pragma once
#include "Std.h"

class Student
{
public:
	Student();
	int index;
	char Name[10] = { 0 };
	int Kor;				//국영수사과
	int Eng;
	int Math;
	int Total;
	int Average;
};
