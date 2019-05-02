#pragma once
//#include "Std.h"
#ifdef no_use_array

#define NAME_LEN 10

class Student
{
	
public:
	Student();
	Student(char name[NAME_LEN],int kor,int eng,int math)
	{
		
		strcpy(Name, name);
		Kor = kor;
		Eng = eng;
		Math = math;
		Total = kor + eng + math;
		Average = Total / 3;
	}
	Student(const Student &cpy_obj) //: Student(cpy_obj.Name, cpy_obj.Kor, cpy_obj.Eng, cpy_obj.Math)
	{
		strcpy(Name, cpy_obj.Name);
		Kor = cpy_obj.Kor;
		Eng = cpy_obj.Eng;
		Math = cpy_obj.Math;
		Total = cpy_obj.Total;
		Average = cpy_obj.Average;
	}

	int status_num=6;

	char status1[NAME_LEN] = "index";
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

	//배열에 넣고, 입출력?  
	

	//int setindex();
	//int setKor();
	//int setEng();
	//int setMath();
	//int setTotal();
	//int setAverage();
	//void setdata();

	//int getindex();
	void getdata();
	void setindex(int inindex);
	void Printdata();
	char* GetName();
};


void Student::getdata()
{


}


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
char* Student::GetName()
{
	return Name;
}

#endif // DEBUG

