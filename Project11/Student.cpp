#include "Student.h"


void Student::setmemnum(int memnum) 
{
	MemNum = memnum;
}

int Student::getmemnum()
{
	return MemNum;
}

Student::Student()
{

	MemNum++;
};
Student::~Student()
{
	MemNum--;
};