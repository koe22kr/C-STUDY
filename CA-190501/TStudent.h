#pragma once
#include "Std.h"

class Student
{
public:
	Student();

	int status_num;

	char status1[10] = "index";
	int index;
	
	char status2[10] = "Name";
	char status3[10] = "Kor";
	char status4[10] = "Eng";
	char status5[10] = "Math";
	char status6[10] = "Total";
	char status7[10] = "Average";

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
	void setindex(int inindex);
	void Printdata();


};
void Student::setindex(int inindex)
{
	index = inindex;
}


void Student::Printdata()
{
	//	| 이름 | 번호 | 국어 | 영어 | 수학 | 총점 | 평균 |
	cout << " |이름: " << Name << " |번호: " << index << " |국어: " << Kor << " |영어: " << Eng
		<< " |수학: " << Math << " |총점: " << Total << " |평균: " << Average << " |" << endl;
}


