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

ll_StudentL* g_p_LLHead = NULL;
ll_StudentL* g_p_LLTail = NULL;

ll_StudentL* NewStudentPtr_inback()
{
	ll_StudentL* TMP;
	g_p_LLTail = (ll_StudentL*)malloc(sizeof(ll_StudentL));
	memset(g_p_LLTail, 0, sizeof(ll_StudentL));
	
	if (g_p_LLHead == NULL)
	{
		g_p_LLHead = g_p_LLTail;
	}
	else
	{
		TMP = g_p_LLHead;
		while (TMP->pNext != NULL)
		{

			TMP = TMP->pNext;
		}
		TMP->pNext = g_p_LLTail;
	}
	return g_p_LLTail;
}
void AddNewStudent()
{
	ll_StudentL* g_p_LLTail = NewStudentPtr_inback();
	printf("���ο� �л� �����͸� �Է��մϴ�.");
	printf("�̸� :");
	scanf("%s", &g_p_LLTail->Name);
	printf("���� :");
	scanf("%d", &g_p_LLTail->Kor);
	printf("���� :");
	scanf("%d", &g_p_LLTail->Eng);
	printf("���� :");
	scanf("%d", &g_p_LLTail->Math);
	printf("��ȸ :");
	scanf("%d", &g_p_LLTail->Society);
	printf("���� :");
	scanf("%d", &g_p_LLTail->Science);
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
		while(TMP!=NULL)
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
		
		fprintf(fp, "%s %d %d %d %d %d",    TMP->Name, TMP->Kor, TMP->Eng,
											TMP->Math, TMP->Society, TMP->Science);
		TMP = TMP->pNext;
	}

}
void LoadStudentData()
{	
	if (g_p_LLHead != NULL)
	{
		Free_allMemory();
	}
	int iMembers=0;
	FILE* fp;
	fp = fopen("test.txt", "rt");					//���ǻ� �����̸��� �Է¹��� �ʴ´�.
	if (fp == NULL) 
	{
		printf("fp�� �ּҰ� NULL�Դϴ�.");
	}
	fscanf(fp, "%d", &iMembers);
	for (int i = 0; i < iMembers; ++i)
	{
		ll_StudentL* pLoadstudent = NewStudentPtr_inback();
		fscanf(fp, "%s %d %d %d %d %d%*c", &pLoadstudent->Name, &pLoadstudent->Kor,       &pLoadstudent->Eng, 
										  &pLoadstudent->Math, &pLoadstudent->Society,	 &pLoadstudent->Science);
	}
	fclose(fp);
	printf("%d���� ������ �ε�. �ƹ�Ű�� �Է��ϸ� ���ư��ϴ�.", iMembers);
	puts("");
	_getch();
}
void InterFace()
{
	int select = 1;
	while (select)
	{
		//system("cls");
		printf("========================	��	��	��	��	================== FILE_Name : \n");
		printf("| 1:�߰�  | 2:����  | 3:����  | 4:�˻�  | 5:����  | 6:����  | 7:�ҷ�����  | 8:�л�����  | 0:����  |\n");
		printf("��ɾ� : ");
		scanf("%d%*c", &select);




		switch (select)  //MODIFY, SORT, SEARCH, DELETE, SAVE, LOAD, INFO, EXIT = 0
		{
		case 1:ADD;             //NewStudentPtr_inback + �Է� ���� �����ϱ�.
		{
			AddNewStudent();
			break;
		}
		case 2:MODIFY;
		case 3:SORT;
		case 4:SEARCH;
		case 5:DELETE;
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
		case 0:EXIT;
		default:
			break;
		}
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
	InterFace();
	_getch();
	return 0;
}