#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include<conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>


enum Select
{
	ADD = 1, MODIFY, SORT, SEARCH, DELETE, SAVE, LOAD, INFO, EXIT = 0
};
	//1:추가 2:수정  3:정렬 4:검색  5:삭제  6:저장 7:불러오기 8:정보보기   0:종료

struct ll_StudentL
{
	char Name[10] = { 0 };
	int Kor;				//국영수사과
	int Eng;
	int Math;
	int Society;
	int Science;
	ll_StudentL* pNext;
};

ll_StudentL* g_p_LLHead = 0;
ll_StudentL* g_p_LLTail = 0;

ll_StudentL* NewStudentPtr_inback()
{
	ll_StudentL* pNewstudent = (ll_StudentL*)malloc(sizeof(ll_StudentL));
	memset(pNewstudent, 0, sizeof(ll_StudentL));
	
	if (g_p_LLHead == NULL)
	{
		g_p_LLHead = pNewstudent;
		g_p_LLTail = pNewstudent;
	}
	else
	{
		g_p_LLTail->pNext = pNewstudent;
	
	}
	return pNewstudent;
}
void AddNewStudent()
{
	ll_StudentL* pAddstudent = NewStudentPtr_inback();
	printf("새로운 학생 데이터를 입력합니다.");
	printf("이름 :");
	scanf("%s", pAddstudent->Name);
	printf("국어 :");
	scanf("%s", pAddstudent->Kor);
	printf("영어 :");
	scanf("%s", pAddstudent->Eng);
	printf("수학 :");
	scanf("%s", pAddstudent->Math);
	printf("사회 :");
	scanf("%s", pAddstudent->Society);
	printf("과학 :");
	scanf("%s", pAddstudent->Science);
}
void Free_allMemory()
{
	ll_StudentL* TMP;
	while (g_p_LLHead != NULL)
	{
		TMP = g_p_LLHead;
		g_p_LLHead = g_p_LLHead->pNext;
		free(TMP);
	}	
	printf("모든 메모리 반환");
}
void ShowStudentInfo()
{
	if (g_p_LLHead == NULL)return;
	ll_StudentL* TMP;
	TMP = g_p_LLHead;
		printf("|  이름  |  국어  |  영어  |  수학  |  사회  |  과학  |\n");
		while(TMP->pNext!=NULL)
		{
			printf("  %s  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  \n",   TMP->Name, TMP->Kor,	 TMP->Eng,
																			TMP->Math, TMP->Society, TMP->Science);
			TMP = TMP->pNext;
		}
		printf("아무키나 입력하면 돌아갑니다.");
		_getch;
	}
void SaveStudentData()
{
	ll_StudentL* TMP = g_p_LLHead;
	FILE*fp;
	fp = fopen("test.txt", "wt");
	while (TMP != NULL)
	{
		
		fprintf(fp, );
		TMP = TMP->pNext;
	}

}
void LoadStudentData()
{	
	if (g_p_LLHead != NULL)
	{
		Free_allMemory();
	}
	int iMembers;
	FILE* fp;
	fp = fopen("test.txt", "rt");					//편의상 파일이름은 입력받지 않는다.
	fscanf(fp, "%d\n", iMembers);
	for (int i = 0; i < iMembers; ++i)
	{
		ll_StudentL* pLoadstudent = NewStudentPtr_inback();
		fscanf(fp, "%s %d %d %d %d %d%*c", pLoadstudent->Name, pLoadstudent->Kor,       pLoadstudent->Eng, 
										  pLoadstudent->Math, pLoadstudent->Society,	 pLoadstudent->Science);
	}
	fclose(fp);
	printf("%d명의 데이터 로드. 아무키나 입력하면 돌아갑니다.", iMembers);
	_getch;
}
void InterFace()
{	
	int select;
	switch (select)  //MODIFY, SORT, SEARCH, DELETE, SAVE, LOAD, INFO, EXIT = 0
	{
	case 1:ADD;             //NewStudentPtr_inback + 입력 으로 구성하기.
	case 2:MODIFY;
	case 3:SORT;
	case 4:SEARCH;
	case 5:DELETE;
	case 6:SAVE;
	case 7:LOAD;		//_getch 사용
	case 8:INFO;		//_getch 사용
	case 0:EXIT;
	default:
		break;
	}
}

int main (void)
{
	//NewStudent		Free_allMemory    ////free_allmemory=종료 기동
	//
	//load file,save file.
	//
	//
	//

}