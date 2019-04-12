
#define _CRT_SECURE_NO_WARNINGS  

#include <iostream>
#include<conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>


enum Select
{
	ADD = 1, MODIFY, SORT, SEARCH, DELETE, SAVE, LOAD, INFO, EXIT = 0
	//1:추가 2:수정  3:정렬 4:검색  5:삭제  6:저장 7:불러오기 8:정보보기   9:종료
};
//enum Select {
//	KOR,ENG,MATH,SOSI,SCI
//};
struct StudyData
{

	char Name[10] = { 0 };
	int Kor;				//국영수사과
	int Eng;
	int Math;
	int Society;
	int Science;


};
