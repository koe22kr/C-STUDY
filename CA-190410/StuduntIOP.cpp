
#define _CRT_SECURE_NO_WARNINGS  

#include <iostream>
#include<conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>


enum Select
{
	ADD = 1, MODIFY, SORT, SEARCH, DELETE, SAVE, LOAD, INFO, EXIT = 0
	//1:�߰� 2:����  3:���� 4:�˻�  5:����  6:���� 7:�ҷ����� 8:��������   9:����
};
//enum Select {
//	KOR,ENG,MATH,SOSI,SCI
//};
struct StudyData
{

	char Name[10] = { 0 };
	int Kor;				//���������
	int Eng;
	int Math;
	int Society;
	int Science;


};
