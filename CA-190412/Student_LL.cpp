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
	//1:�߰� 2:����  3:���� 4:�˻�  5:����  6:���� 7:�ҷ����� 8:��������   0:����

struct ll_StudentL
{
	char Name[10] = { 0 };
	int Kor;				//���������
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
	printf("���ο� �л� �����͸� �Է��մϴ�.");
	printf("�̸� :");
	scanf("%s", pAddstudent->Name);
	printf("���� :");
	scanf("%s", pAddstudent->Kor);
	printf("���� :");
	scanf("%s", pAddstudent->Eng);
	printf("���� :");
	scanf("%s", pAddstudent->Math);
	printf("��ȸ :");
	scanf("%s", pAddstudent->Society);
	printf("���� :");
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
	printf("��� �޸� ��ȯ");
}
void ShowStudentInfo()
{
	if (g_p_LLHead == NULL)return;
	ll_StudentL* TMP;
	TMP = g_p_LLHead;
		printf("|  �̸�  |  ����  |  ����  |  ����  |  ��ȸ  |  ����  |\n");
		while(TMP->pNext!=NULL)
		{
			printf("  %s  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  \n",   TMP->Name, TMP->Kor,	 TMP->Eng,
																			TMP->Math, TMP->Society, TMP->Science);
			TMP = TMP->pNext;
		}
		printf("�ƹ�Ű�� �Է��ϸ� ���ư��ϴ�.");
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
	fp = fopen("test.txt", "rt");					//���ǻ� �����̸��� �Է¹��� �ʴ´�.
	fscanf(fp, "%d\n", iMembers);
	for (int i = 0; i < iMembers; ++i)
	{
		ll_StudentL* pLoadstudent = NewStudentPtr_inback();
		fscanf(fp, "%s %d %d %d %d %d%*c", pLoadstudent->Name, pLoadstudent->Kor,       pLoadstudent->Eng, 
										  pLoadstudent->Math, pLoadstudent->Society,	 pLoadstudent->Science);
	}
	fclose(fp);
	printf("%d���� ������ �ε�. �ƹ�Ű�� �Է��ϸ� ���ư��ϴ�.", iMembers);
	_getch;
}
void InterFace()
{	
	int select;
	switch (select)  //MODIFY, SORT, SEARCH, DELETE, SAVE, LOAD, INFO, EXIT = 0
	{
	case 1:ADD;             //NewStudentPtr_inback + �Է� ���� �����ϱ�.
	case 2:MODIFY;
	case 3:SORT;
	case 4:SEARCH;
	case 5:DELETE;
	case 6:SAVE;
	case 7:LOAD;		//_getch ���
	case 8:INFO;		//_getch ���
	case 0:EXIT;
	default:
		break;
	}
}

int main (void)
{
	//NewStudent		Free_allMemory    ////free_allmemory=���� �⵿
	//
	//load file,save file.
	//
	//
	//

}