#pragma once
#include "Std.h"

class Student
{
public:
	char Name[10] = { 0 };
	int Kor;				//국영수사과
	int Eng;
	int Math;
	int Society;
	int Science;
	int Total;
	int MemNum;
//	int SortFLAG = 1;
	
	Student() ;
	~Student();

	void setmemnum(int memnum);
	int getmemnum();
};

