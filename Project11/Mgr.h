#pragma once

#include "FileIO.h"
using namespace std;
enum Select
{
	ADD = 1, MODIFY, SORT, SEARCH, DELETE, SAVE, LOAD, INFO, RANDOM, EXIT = 0
};
//1:�߰� 2:����  3:���� 4:�˻�  5:����  6:���� 7:�ҷ����� 8:�������� 9:���� �л� ����  0:����



class Mgr
{
public:
	Mgr();
	~Mgr();
	Linklist* pll;
	Student* pst;
	FileIO* pfile;

	void ER_CHECK_NOT_OPEN_DATA();
	void AddRandomStudent(int n);
	void RandomStudent();
	void AddNewStudent();
	void ShowStudentInfo();
	Linklist* SearchStudent_byname();
	void ModySTudentData(Linklist* Target);
	void SortStudentUPorDOWN(bool up_1_down_0);
	bool SortIncorDec(bool up_or_down, Linklist* Target, Linklist* TMPj);

	void SwapStudentData_without_pre_next(Linklist* P1, Linklist* P2);
	void InterFace();
};

