#pragma once
#include "Std.h"

class Student
{
public:
	Student();
	int index;
	char Name[10] = { 0 };
	int Kor;				//���������
	int Eng;
	int Math;
	int Total;
	int Average;
};
