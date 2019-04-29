#pragma once
#include "Std.h"

class Student
{
public:
	Student();

	int status_num;

	char status1[10] = "index";
	char status2[10] = "Name";
	char status3[10] = "Kor";
	char status4[10] = "Eng";
	char status5[10] = "Math";
	char status6[10] = "Total";
	char status7[10] = "Average";

	int index;
	char Name[10] = { 0 };
	int Kor;
	int Eng;
	int Math;
	int Total;
	int Average;

	//int setindex();
	//int setKor();
	//int setEng();
	//int setMath();
	//int setTotal();
	//int setAverage();
	//void setdata();

	//int getindex();
	//int getKor();
	//int getEng();
	//int getMath();
	//int getTotal();
	//int getAverage();
	//void getdata();


};

