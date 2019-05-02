#pragma once
#include "Std.h"

#define NAME_LEN 10
#define MAX_NUM_DATA 10

class Student
{

public:
	enum DATA_NAME
	{NAME=0,KOR,ENG,MATH,TOTAL,AVERAGE

	};
	
	char Name[10] = { 0 };
	int Count = 6;		//0~5 6개씩
	int m_Student_Data[MAX_NUM_DATA];
	const char* m_Data_Name[MAX_NUM_DATA] = { "Name","Kor","Eng","Math","Total","Average" }; 

	Student();
	Student(char name[NAME_LEN], int kor, int eng, int math);
	
	Student(const Student &cpy_obj); //: Student(cpy_obj.Name, cpy_obj.Kor, cpy_obj.Eng, cpy_obj.Math)
	
	char status1[NAME_LEN] = "index";
	int index;
	
	//int setindex();
	//int setKor();
	//int setEng();
	//int setMath();
	//int setTotal();
	//int setAverage();
	//void setdata();

	//int getindex();
	void Set_Data(int data_num);
	auto Get_Data(int data_num);
	const char* Get_Data_Name(int data_num);

	void setindex(int inindex);
	void Printdata();
	char* GetName();
};

Student::Student(char name[NAME_LEN], int kor, int eng, int math)
{
	strcpy(Name, name);
	m_Student_Data[1] = kor;
	m_Student_Data[2] = eng;
	m_Student_Data[3] = math;
	m_Student_Data[4] = kor + eng + math;
	m_Student_Data[5] = m_Student_Data[3] / 3;
}
Student::Student(const Student &cpy_obj) //: Student(cpy_obj.Name, cpy_obj.Kor, cpy_obj.Eng, cpy_obj.Math)
{
	strcpy(Name, cpy_obj.Name);
	m_Student_Data[1] = cpy_obj.m_Student_Data[0];
	m_Student_Data[2] = cpy_obj.m_Student_Data[1];
	m_Student_Data[3] = cpy_obj.m_Student_Data[2];
	m_Student_Data[4] = cpy_obj.m_Student_Data[3];
	m_Student_Data[5] = cpy_obj.m_Student_Data[4];
}




void Student::Set_Data(int data_num)
{
	switch (data_num)
	{
	case NAME:
		m_Student_Data[NAME]
	case KOR:
		return m_Student_Data[KOR];
	case ENG:
		return m_Student_Data[ENG];
	case MATH:
		return m_Student_Data[MATH];
	case TOTAL:
		return m_Student_Data[TOTAL];
	case AVERAGE:
		return m_Student_Data[AVERAGE];

	default:
		break;
	}

}

auto Student::Get_Data(int data_num)
{
	switch (data_num)
	{
	case NAME:
		return m_Student_Data[NAME];
	case KOR:
		return m_Student_Data[KOR];
	case ENG:
		return m_Student_Data[ENG];
	case MATH:
		return m_Student_Data[MATH];
	case TOTAL:
		return m_Student_Data[TOTAL];
	case AVERAGE:
		return m_Student_Data[AVERAGE];

	default:
		break;
	}
}

const char* Student::Get_Data_Name(int data_num)
{
	switch (data_num)
	{
	case NAME:
		return m_Data_Name[NAME];
	case KOR:
		return m_Data_Name[KOR];
	case ENG:
		return m_Data_Name[ENG];
	case MATH:
		return m_Data_Name[MATH];
	case TOTAL:
		return m_Data_Name[TOTAL];
	case AVERAGE:
		return m_Data_Name[AVERAGE];
	default:
		break;
	}
}

void Student::setindex(int inindex)
{
	index = inindex;
}


void Student::Printdata()
{
	//	| 이름 | 번호 | 국어 | 영어 | 수학 | 총점 | 평균 |
	cout << " |이름: " << Name << " |번호: " << index << " |국어: " << m_Student_Data[0] << " |영어: " << m_Student_Data[1]
		<< " |수학: " << m_Student_Data[2] << " |총점: " << m_Student_Data[3] << " |평균: " << m_Student_Data[4] << " |" << endl;
}
char* Student::GetName()
{
	return Name;
}