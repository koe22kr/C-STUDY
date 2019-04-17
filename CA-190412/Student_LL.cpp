#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include<conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
enum Select
{
	ADD = 1, MODIFY, SORT, SEARCH, DELETE, SAVE, LOAD, INFO, RANDOM, EXIT = 0
};
	//1:추가 2:수정  3:정렬 4:검색  5:삭제  6:저장 7:불러오기 8:정보보기 9:랜덤 학생 생성  0:종료

struct ll_StudentL
{
	char Name[10] = { 0 };
	int Kor;				//국영수사과
	int Eng;
	int Math;
	int Society;
	int Science;
	int Total;
	int SortFLAG = 1;
	ll_StudentL* pNext=NULL;
	ll_StudentL* pPrev = NULL;

};
int MemNum = 0;
ll_StudentL* g_pLHead = new ll_StudentL;
ll_StudentL* g_pLTail = new ll_StudentL;

bool SortIncorDec(int up_or_down, ll_StudentL* Target, ll_StudentL* TMPj);

void DeleteStudentData(ll_StudentL* delpoint);
void SwapStudentData_without_pre_next(ll_StudentL* P1, ll_StudentL* P2);
ll_StudentL* NewStudentPtr_inLast()
{

	ll_StudentL* TMP;
	ll_StudentL* newSt = new ll_StudentL;
	TMP = g_pLTail->pPrev;

	g_pLTail->pPrev = newSt;
	newSt->pNext = g_pLTail;
	
	TMP->pNext = newSt;
	newSt->pPrev = TMP;
	

	return newSt;   //헤드 넥스트값
}


void ER_CHECK_NOT_OPEN_DATA()//추가,로드 말고 다 이걸 불러오기. 학생데이터 없어도 기능하는것 빼고 다 달기.
{
	if (g_pLHead->pNext == g_pLTail)
	{
		printf("ER:학생정보가 없습니다.(head의next가 tail입니다.");
		return;
	}
}

void AddRandomStudent(int n)
{

	for (int i = 0; i < n; i++)
	{
		ll_StudentL* newStatus = NewStudentPtr_inLast();
		char c[4] = { 0 };
		c[0] = rand() % 26 + 65;
		c[1] = rand() % 26 + 65;
		c[2] = rand() % 26 + 65;
		strcpy(newStatus->Name, c);
		newStatus->Kor = rand() % 101;
		newStatus->Eng = rand() % 101;
		newStatus->Math = rand() % 101;
		newStatus->Society = rand() % 101;
		newStatus->Science = rand() % 101;
		newStatus->Total = (newStatus->Kor + newStatus->Eng + newStatus->Math + newStatus->Society + newStatus->Science);
		MemNum++;
	}
}

void RandomStudent()
{
	int n = 0;
	printf("랜덤 제작 횟수를 입력 :");
	scanf("%d", &n);
	if (n == 0)
	{
		return;
	}
	AddRandomStudent(n);
}


void AddNewStudent()
{
	ll_StudentL* newStatus = NewStudentPtr_inLast();

	printf("새로운 학생 데이터를 입력합니다.");
	printf("이름 :");
	scanf("%s", &newStatus->Name);
	printf("국어 :");
	scanf("%d", &newStatus->Kor);
	printf("영어 :");
	scanf("%d", &newStatus->Eng);
	printf("수학 :");
	scanf("%d", &newStatus->Math);
	printf("사회 :");
	scanf("%d", &newStatus->Society);
	printf("과학 :");
	scanf("%d", &newStatus->Science);
	newStatus->Total = (newStatus->Kor + newStatus->Eng + newStatus->Math + newStatus->Society + newStatus->Science);
	MemNum++;
}

void Free_allMemoryforHead(ll_StudentL* HEAD)
{
	ER_CHECK_NOT_OPEN_DATA();
	
	
	ll_StudentL* DelHead;
	while (g_pLHead->pNext != g_pLTail)//
	{
		DelHead = HEAD->pNext;
		DeleteStudentData(DelHead);		
		
	}	
	printf("모든 메모리 반환");
	HEAD->pNext = NULL;
}

void DeleteStudentData(ll_StudentL* delpoint)
{
	ll_StudentL* TMPpre;
	ll_StudentL* TMPnext;
	TMPpre = delpoint->pPrev;
	TMPnext = delpoint->pNext;

	TMPnext->pPrev = TMPpre;
	TMPpre->pNext = TMPnext;
	delete delpoint;

}

void ShowStudentInfo()
{
	ER_CHECK_NOT_OPEN_DATA();

	ll_StudentL* TMP;
	TMP = g_pLHead->pNext;
		printf("|  이름  |  국어  |  영어  |  수학  |  사회  |  과학  |  총점  |\n");
		while(TMP!=g_pLTail)
		{
			printf("    %s  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  \n",   TMP->Name, TMP->Kor,	 TMP->Eng,
																			TMP->Math, TMP->Society, TMP->Science, TMP->Total);
			TMP = TMP->pNext;
		}
		printf("아무키나 입력하면 돌아갑니다.\n");
		_getch();
	}

void SaveStudentData()
{
	ER_CHECK_NOT_OPEN_DATA();

	ll_StudentL* TMP = g_pLHead->pNext;
	FILE*fp;
	fp = fopen("../../output/test.txt", "wt");
	fprintf(fp, "%d\n", MemNum);
	while (TMP != g_pLTail)
	{
		fprintf(fp, "%s %d %d %d %d %d %d\n",    TMP->Name, TMP->Kor, TMP->Eng,
												TMP->Math, TMP->Society, TMP->Science,
												TMP->Kor + TMP->Eng + TMP->Math + TMP->Society + TMP->Science);
		TMP = TMP->pNext;
	}
	fclose(fp);
}

void LoadStudentData()
{	
	if (g_pLHead->pNext != g_pLTail)
	{
		Free_allMemoryforHead(g_pLHead);
	}
	FILE* fp;
	fp = fopen("../../output/test.txt", "rt");					//편의상 파일이름은 입력받지 않는다.
	if (fp == NULL) 
	{
		printf("fp의 주소가 NULL. 파일을 열지 못하였습니다.");
	}
	fscanf(fp, "%d%*c", &MemNum);
	for (int i = 0; i < MemNum; i++)
	{	
		
		ll_StudentL* pLoadstudent = NewStudentPtr_inLast();
		fscanf(fp,"%s %d %d %d %d %d %d",  &pLoadstudent->Name, &pLoadstudent->Kor, &pLoadstudent->Eng,
											&pLoadstudent->Math, &pLoadstudent->Society, &pLoadstudent->Science, &pLoadstudent->Total);
		
		
		pLoadstudent->SortFLAG = 1;
		//pLoadstudent->pNext = NULL;

	}
	fclose(fp);
	//printf("%d명의 데이터 로드. 아무키나 입력하면 돌아갑니다.\n",);
	puts("");
	_getch();
}

ll_StudentL* SearchStudent_byname()
{
	ER_CHECK_NOT_OPEN_DATA();

	ll_StudentL* TMP = g_pLHead->pNext;
	char Name_for_search[30] = { 0 };
	printf("검색할 이름을 입력해주세요.");
	scanf("%s%*c", Name_for_search);
	
	if (TMP == g_pLTail)
	{
		printf("데이터가 존재하지 않습니다.");
		return 0;
	}
	while (TMP != g_pLTail)
	{
		if (strstr(TMP->Name, Name_for_search) != NULL)
		{
			return TMP;
		}
		
		TMP = TMP->pNext;
		
	}
	printf("|  이름  |  국어  |  영어  |  수학  |  사회  |  과학  |  총점  |\n");
	printf("|    %s  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  \n",   TMP->Name, TMP->Kor, TMP->Eng,
																			TMP->Math, TMP->Society, TMP->Science, TMP->Total);
	return TMP;
}

//ll_StudentL* SearchStudentUP_Total()
//{
//
//	ll_StudentL* TMP = g_pLHead;
//	if (g_pLHead->pNext == NULL) printf("학생이 존재하지 않습니다.");
//	//if (TMP->pNext == NULL)
//	
//	while (TMP != NULL)
//	{
//
//		TMP = TMP->pNext;
//	}
//}

void ModySTudentData(ll_StudentL* Target)
{
	ll_StudentL* find=SearchStudent_byname();
	if (find == g_pLTail)return;
	printf("  %s  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  \n",   find->Name, find->Kor, find->Eng,
																			find->Math, find->Society, find->Science, find->Total);
	printf("이름 :");
	scanf("%s", &find->Name);
	printf("국어 :");
	scanf("%d", &find->Kor);
	printf("영어 :");
	scanf("%d", &find->Eng);
	printf("수학 :");
	scanf("%d", &find->Math);
	printf("사회 :");
	scanf("%d", &find->Society);
	printf("과학 :");
	scanf("%d", &find->Science);
	find->Total = (find->Kor + find->Eng + find->Math + find->Society + find->Science);
	
}

void SortStudentUPorDOWN(bool up_1_down_0)		
{
	ER_CHECK_NOT_OPEN_DATA();
	
	
	ll_StudentL* Target = nullptr;
	for (ll_StudentL* TMPi = g_pLHead->pNext; TMPi != g_pLTail; TMPi = TMPi->pNext)
	{
		Target = TMPi;

		for (ll_StudentL* TMPj = TMPi->pNext; TMPj != g_pLTail; TMPj= TMPj->pNext)
		{
			
			if(SortIncorDec(up_1_down_0,Target,TMPj))
				Target = TMPj;
		}		
		SwapStudentData_without_pre_next(Target,TMPi);
		
	}
	ShowStudentInfo();
}

bool SortIncorDec(bool up_1_down_0, ll_StudentL* Target, ll_StudentL* TMPj)
{
	if (up_1_down_0 == 1)
	{
		if (Target->Total > TMPj->Total)
		{
			return 1;
		}
			
	}
	else if (up_1_down_0 == 0)
	{
		if (Target->Total < TMPj->Total)
		{
			return 1;
		}
	}
	return 0;
}

void SwapStudentData_without_pre_next(ll_StudentL* ppre, ll_StudentL* pnext)
{
	
	ll_StudentL* TMP = new ll_StudentL;
	strcpy(TMP->Name, ppre->Name);
	TMP->Kor = ppre->Kor;
	TMP->Eng = ppre->Eng;
	TMP->Math = ppre->Math;
	TMP->Society = ppre->Society;
	TMP->Science = ppre->Science;
	TMP->Total = ppre->Total;

	strcpy(ppre->Name, pnext->Name);
	ppre->Kor = pnext->Kor;
	ppre->Eng = pnext->Eng;
	ppre->Math = pnext->Math;
	ppre->Society = pnext->Society;
	ppre->Science = pnext->Science;
	ppre->Total = pnext->Total;

	strcpy(pnext->Name, TMP->Name);
	pnext->Kor = TMP->Kor;
	pnext->Eng = TMP->Eng;
	pnext->Math = TMP->Math;
	pnext->Society = TMP->Society;
	pnext->Science = TMP->Science;
	pnext->Total = TMP->Total;

	delete TMP;
}

void InterFace()
{
	int select = 1;
	while (select)
	{
		system("cls");
		printf("========================	성	적	관	리	======================================\n ");
		printf("| 1:추가  | 2:수정  | 3:정렬  | 4:검색  | 5:삭제  | 6:저장  | 7:불러오기  | 8:학생정보| 9:랜덤  | 0:종료  |\n");
		printf("명령어 : ");
		scanf("%d%*c", &select);




		switch (select)  //
		{
		case 1:ADD;             //NewStudentPtr_inback + 입력 으로 구성하기.
		{
			AddNewStudent();
			break;
		}
		case 2:MODIFY;
		{
			ModySTudentData(SearchStudent_byname());
			break;
		}
		case 3:SORT;
		{
			SortStudentUPorDOWN(1);//1올림 0내림
			break;
		}
		case 4:SEARCH;
		{
			SearchStudent_byname();
			break;
		}
		case 5:DELETE;
		{
			DeleteStudentData(g_pLHead);
			break;
		}
		case 6:SAVE;
		{
			SaveStudentData();
			break;
		}
		case 7:LOAD;		//_getch 사용
		{
			LoadStudentData();
			break;
		}
		case 8:INFO;		//_getch 사용
		{
			ShowStudentInfo();
			break;
		}
		case 9:RANDOM;
		{
			RandomStudent();
			break;
		}
		case 0:EXIT;
		break;
		}
	}
}

void Init_Head_Tail()
{
	memset(g_pLHead, 0, sizeof(ll_StudentL));
	memset(g_pLTail, 0, sizeof(ll_StudentL));
	g_pLHead->pNext = g_pLTail;
	g_pLTail->pPrev = g_pLHead;
}

int main (void)
{
	int a = sizeof(ll_StudentL::Name);
	
	//NewStudent		Free_allMemory    ////free_allmemory=종료 기동
	
	Init_Head_Tail();


	InterFace();
	Free_allMemoryforHead(g_pLHead);
	
	delete g_pLHead;
	delete g_pLTail;

	_getch();
	return 0;
}