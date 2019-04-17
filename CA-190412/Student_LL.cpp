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
	//1:�߰� 2:����  3:���� 4:�˻�  5:����  6:���� 7:�ҷ����� 8:�������� 9:���� �л� ����  0:����

struct ll_StudentL
{
	char Name[10] = { 0 };
	int Kor;				//���������
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
	

	return newSt;   //��� �ؽ�Ʈ��
}


void ER_CHECK_NOT_OPEN_DATA()//�߰�,�ε� ���� �� �̰� �ҷ�����. �л������� ��� ����ϴ°� ���� �� �ޱ�.
{
	if (g_pLHead->pNext == g_pLTail)
	{
		printf("ER:�л������� �����ϴ�.(head��next�� tail�Դϴ�.");
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
	printf("���� ���� Ƚ���� �Է� :");
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

	printf("���ο� �л� �����͸� �Է��մϴ�.");
	printf("�̸� :");
	scanf("%s", &newStatus->Name);
	printf("���� :");
	scanf("%d", &newStatus->Kor);
	printf("���� :");
	scanf("%d", &newStatus->Eng);
	printf("���� :");
	scanf("%d", &newStatus->Math);
	printf("��ȸ :");
	scanf("%d", &newStatus->Society);
	printf("���� :");
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
	printf("��� �޸� ��ȯ");
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
		printf("|  �̸�  |  ����  |  ����  |  ����  |  ��ȸ  |  ����  |  ����  |\n");
		while(TMP!=g_pLTail)
		{
			printf("    %s  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  \n",   TMP->Name, TMP->Kor,	 TMP->Eng,
																			TMP->Math, TMP->Society, TMP->Science, TMP->Total);
			TMP = TMP->pNext;
		}
		printf("�ƹ�Ű�� �Է��ϸ� ���ư��ϴ�.\n");
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
	fp = fopen("../../output/test.txt", "rt");					//���ǻ� �����̸��� �Է¹��� �ʴ´�.
	if (fp == NULL) 
	{
		printf("fp�� �ּҰ� NULL. ������ ���� ���Ͽ����ϴ�.");
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
	//printf("%d���� ������ �ε�. �ƹ�Ű�� �Է��ϸ� ���ư��ϴ�.\n",);
	puts("");
	_getch();
}

ll_StudentL* SearchStudent_byname()
{
	ER_CHECK_NOT_OPEN_DATA();

	ll_StudentL* TMP = g_pLHead->pNext;
	char Name_for_search[30] = { 0 };
	printf("�˻��� �̸��� �Է����ּ���.");
	scanf("%s%*c", Name_for_search);
	
	if (TMP == g_pLTail)
	{
		printf("�����Ͱ� �������� �ʽ��ϴ�.");
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
	printf("|  �̸�  |  ����  |  ����  |  ����  |  ��ȸ  |  ����  |  ����  |\n");
	printf("|    %s  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  \n",   TMP->Name, TMP->Kor, TMP->Eng,
																			TMP->Math, TMP->Society, TMP->Science, TMP->Total);
	return TMP;
}

//ll_StudentL* SearchStudentUP_Total()
//{
//
//	ll_StudentL* TMP = g_pLHead;
//	if (g_pLHead->pNext == NULL) printf("�л��� �������� �ʽ��ϴ�.");
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
	printf("�̸� :");
	scanf("%s", &find->Name);
	printf("���� :");
	scanf("%d", &find->Kor);
	printf("���� :");
	scanf("%d", &find->Eng);
	printf("���� :");
	scanf("%d", &find->Math);
	printf("��ȸ :");
	scanf("%d", &find->Society);
	printf("���� :");
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
		printf("========================	��	��	��	��	======================================\n ");
		printf("| 1:�߰�  | 2:����  | 3:����  | 4:�˻�  | 5:����  | 6:����  | 7:�ҷ�����  | 8:�л�����| 9:����  | 0:����  |\n");
		printf("��ɾ� : ");
		scanf("%d%*c", &select);




		switch (select)  //
		{
		case 1:ADD;             //NewStudentPtr_inback + �Է� ���� �����ϱ�.
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
			SortStudentUPorDOWN(1);//1�ø� 0����
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
		case 7:LOAD;		//_getch ���
		{
			LoadStudentData();
			break;
		}
		case 8:INFO;		//_getch ���
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
	
	//NewStudent		Free_allMemory    ////free_allmemory=���� �⵿
	
	Init_Head_Tail();


	InterFace();
	Free_allMemoryforHead(g_pLHead);
	
	delete g_pLHead;
	delete g_pLTail;

	_getch();
	return 0;
}