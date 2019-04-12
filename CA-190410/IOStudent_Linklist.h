#pragma once

#include <iostream>
#include<conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

struct ll_StudentL
{
	char Name[10] = { 0 };
	int Kor;				//국영수사과
	int Eng;
	int Math;
	int Society;
	int Science;

};

ll_StudentL* LL_Head;
ll_StudentL* LL_Tail;

