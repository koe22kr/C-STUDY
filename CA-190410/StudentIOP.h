#pragma once
 

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

int MemberNumber = 0;
StudyData* pStData;
FILE* fp;
StudyData* padddata = NULL;
char UsingFileName[25] = { 0 };

//void F_OpenR(const char* FILE_Name)			F_Load�� ����
//{
//	if (fp == NULL)
//	{
//		F_Create(FILE_Name);
//	}
//	fopen(&fp, FILE_Name, "r+");              
//
//}
void F_Create()
{
	printf("������ ������ �̸��� �Է��ϼ���.");
	scanf("%s", UsingFileName);
	fp = fopen(UsingFileName, "w+t");				 //&fp�� ����

}
void F_Load()
{
	if (fp != NULL)fclose(fp);

	if (*UsingFileName == NULL)
	{
		printf("�ҷ��� ������ �̸��� �Է��ϼ���.");
		scanf("%s", UsingFileName);
		fp = fopen(UsingFileName, "r+t"); //&fp�� ����
	}
	else
	{

		fp = fopen(UsingFileName, "r+t");//
	}


	if (pStData != nullptr)
	{
		free(pStData);
	}
	fscanf(fp, "%d\n", &MemberNumber);
	pStData = (StudyData*)malloc(sizeof(StudyData)*MemberNumber);

	for (int i = 0; i < MemberNumber; i++)
	{

		fscanf(fp, "%s	 %d		 %d		 %d		 %d		 %d",
			&pStData[i].Name, &pStData[i].Kor, &pStData[i].Eng,
			&pStData[i].Math, &pStData[i].Society, &pStData[i].Science);

	}

}


void F_Save()      //MemberNumber,Fp   //fclose(fp) free(pStData,padddata) ���̺�� ���ϴ���.
{
	int iDeletecount = 0;
	if (*UsingFileName == NULL)
	{
		printf("���� ������ �����ϴ�.");
		return;
	}
	F_Create();
	fseek(fp, 0, SEEK_SET);
	fprintf(fp, "%d\n", MemberNumber);
	for (int i = 0; i < MemberNumber + iDeletecount; i++)
	{
		if (pStData[i].Name == NULL)
		{
			++iDeletecount;
		}
		else
		{
			fprintf(fp, "%s %d %d %d %d %d\n",
				pStData[i].Name, pStData[i].Kor, pStData[i].Eng,
				pStData[i].Math, pStData[i].Society, pStData[i].Science);
		}
	}



	F_Load();
	fclose(fp);
}

void F_Add()
{
	if (*UsingFileName == NULL)
	{
		printf("���� ������ ��� ���� ����ϴٴϴ�.\n");
		F_Create();
	}


	padddata = (StudyData*)malloc(sizeof(StudyData));
	printf("[�߰�]\n");
	printf("�̸��� �Է����ּ���.");
	scanf("%s", &padddata->Name);
	printf("���� ������ �Է����ּ���.");
	scanf("%d", &padddata->Kor);
	printf("���� ������ �Է����ּ���.");
	scanf("%d", &padddata->Eng);
	printf("���� ������ �Է����ּ���.");
	scanf("%d", &padddata->Math);
	printf("��ȸ ������ �Է����ּ���.");
	scanf("%d", &padddata->Society);
	printf("���� ������ �Է����ּ���.");
	scanf("%d", &padddata->Science);

	fseek(fp, 0, SEEK_SET);
	fprintf(fp, "%d\n", ++MemberNumber);
	fseek(fp, 0, SEEK_END);
	fprintf(fp, "%s %d %d %d %d %d\n",
		padddata->Name, padddata->Kor, padddata->Eng,
		padddata->Math, padddata->Society, padddata->Science);

	free(padddata);
	fclose(fp);
	F_Load();
}
int F_Search() //�̸� �ߺ��� ���ܷ� �Ѵ�. ����ü �����ȯ;
{
	char* psearched;
	char keyward[20];
	printf("�˻��� �̸��� �Է����ּ���. : ");
	scanf("%s", keyward);
	_getch();
	for (int i = 0; i < MemberNumber; i++)
	{
		psearched = strstr(pStData[i].Name, keyward);
		if (psearched != NULL)
		{
			printf("%d�� �̸�:%s ����:%d ����:%d ����:%d ��ȸ:%d ����:%d\n", i + 1, pStData[i].Name, pStData[i].Kor, pStData[i].Eng,
				pStData[i].Math, pStData[i].Society, pStData[i].Science);
			return i;
		}
	}
	printf("�ش� �̸��� ã�� ���Ͽ����ϴ�.\n");
	return 0;
}
void F_Modify()
{


	printf("������ ����� �˻��մϴ�.\n");
	int i = F_Search();
	printf("������ �����մϴ�.\n");
	printf("�̸�:");
	scanf("%s", pStData[i].Name);			//& ���� ����?
	printf("�������� :");
	scanf("%d", &pStData[i].Kor);
	printf("�������� :");
	scanf("%d", &pStData[i].Eng);
	printf("�������� :");
	scanf("%d", &pStData[i].Math);
	printf("��ȸ���� :");
	scanf("%d", &pStData[i].Society);
	printf("�������� :");
	scanf("%d", &pStData[i].Science);
	printf("\n-�����Ϸ�.-\n");
}

void F_SortScoreKor()			////sort ��ȯ�� ���� �ϳ��� �ϴ°� �ƴ϶� �� ��°�� ��ȯ �ؾ���.
{
	StudyData TMP;
	printf("������ ������������ ����");
	for (int i = 0; i < MemberNumber - 1; ++i)
	{
		for (int j = i; j < MemberNumber; ++j)
		{
			if (pStData[i].Kor < pStData[j].Kor)
			{
				TMP = pStData[i];
				pStData[i] = pStData[j];
				pStData[j] = TMP;
			}
		}
	}
}
void F_SortScoreEng()
{
	StudyData TMP;
	printf("������ ������������ ����");
	for (int i = 0; i < MemberNumber - 1; ++i)
	{
		for (int j = i; j < MemberNumber; ++j)
		{
			if (pStData[i].Eng < pStData[j].Eng)
			{
				TMP = pStData[i];
				pStData[i] = pStData[j];
				pStData[j] = TMP;
			}
		}
	}
}
void F_SortScoreMath()
{
	StudyData TMP;
	printf("������ ������������ ����");
	for (int i = 0; i < MemberNumber - 1; ++i)
	{
		for (int j = i; j < MemberNumber; ++j)
		{
			if (pStData[i].Math < pStData[j].Math)
			{
				TMP = pStData[i];
				pStData[i] = pStData[j];
				pStData[j] = TMP;
			}
		}
	}
}
void F_SortScoreSoci()
{
	StudyData TMP;
	printf("������ ������������ ����");
	for (int i = 0; i < MemberNumber - 1; ++i)
	{
		for (int j = i; j < MemberNumber; ++j)
		{
			if (pStData[i].Society < pStData[j].Society)
			{
				TMP = pStData[i];
				pStData[i] = pStData[j];
				pStData[j] = TMP;
			}
		}
	}
}
void F_SortScoreSci()
{
	StudyData TMP;
	printf("������ ������������ ����");
	for (int i = 0; i < MemberNumber - 1; ++i)
	{
		for (int j = i; j < MemberNumber; ++j)
		{
			if (pStData[i].Society < pStData[j].Society)
			{
				TMP = pStData[i];
				pStData[i] = pStData[j];
				pStData[j] = TMP;
			}
		}
	}
}
void F_SortNameDown()
{
	StudyData TMP;
	printf("�̸��� ������������ ����");
	for (int i = 0; i < MemberNumber - 1; ++i)
	{
		for (int j = i + 1; j < MemberNumber; ++j)
		{
			if (strcmp(pStData[i].Name, pStData[j].Name) < 0)
			{
				TMP = pStData[i];
				pStData[i] = pStData[j];
				pStData[j] = TMP;
			}
		}
	}
}
void F_SortNameUp()
{
	StudyData TMP;
	printf("�̸��� �ø��������� ����");
	for (int i = 0; i < MemberNumber - 1; ++i)
	{
		for (int j = i + 1; j <= MemberNumber; ++j)
		{
			if (strcmp(pStData[i].Name, pStData[j].Name) > 0)
			{
				TMP = pStData[i];
				pStData[i] = pStData[j];
				pStData[j] = TMP;
			}
		}
	}
}


void F_Delete()
{
	int i = 0;
	printf("������ ����� �˻��մϴ�.");
	i = F_Search();
	if (i == NULL)return;

	printf("%s�� ������ �����ұ��? y/n", pStData[i].Name);
;	if (('n' || 'N') == getchar())
	{
		return;
	}
	memset(&pStData[i], 0, sizeof(StudyData));
	printf("�����Ϸ�.. �̸� ������ �ǽ��մϴ�.");
	F_SortNameDown();
	fseek(fp, 0, SEEK_SET);
	fprintf(fp, "%d\n", --MemberNumber);
	F_Save();
}

void F_Sort()
{

	int select;//1:�̸� 2:�� 3:�� 4:�� 5:�� 6:��
	printf("�������ڸ� �����ϼ���.");
	printf("|1: �̸� | 2: ����| 3: ����| 4: ����| 5: ��ȸ| 6: ����| 0:����|");
	scanf("%d%*c", &select);
	switch (select)
	{
	case 1:
	{
		F_SortNameUp();
		break;
	}
	case 2: //����
	{
		F_SortScoreKor();
		break;
	}
	case 3:
	{
		F_SortScoreEng();
		break;
	}
	case 4:
	{
		F_SortScoreMath();
		break;
	}
	case 5:
	{
		F_SortScoreSoci();
		break;
	}
	case 6:
	{
		F_SortScoreSci();
		break;
	}
	default:
		printf("�߸��� ���ڸ� �Է�");
	}


}

void ShowInfo()
{
	printf("|  �̸�  |  ����  |  ����  |  ����  |  ��ȸ  |  ����  |\n");
	for (int i = 0; i < MemberNumber; ++i)
	{
		printf("  %s     %4d     %4d     %4d     %4d     %4d     \n", pStData[i].Name, pStData[i].Kor, pStData[i].Eng,
			pStData[i].Math, pStData[i].Society, pStData[i].Science);
	}
}
void ShowMain()
{
	int select = 1;
	while (select)
	{
		//system("cls");
		printf("========================	��	��	��	��	================== FILE_Name : %s\n", UsingFileName);
		printf("| 1:�߰�  | 2:����  | 3:����  | 4:�˻�  | 5:����  | 6:����  | 7:�ҷ�����  | 8:�л�����  | 0:����  |\n");
		printf("��ɾ� : ");
		scanf("%d%*c", &select);

		switch (select)
		{
		case Select::ADD:
		{
			F_Add();
			break;
		}
		case Select::MODIFY:
		{
			F_Modify();
			break;
		}
		case Select::SORT: // ������ ȣ����ҿ���
		{
			F_Sort();
			break;
		}
		case Select::SEARCH:     //������ ȣ����� ����
		{
			F_Search();
			break;
		}
		case Select::DELETE:			//���ο��� ���� ȣ��
		{
			F_Delete();
			break;
		}
		case Select::SAVE:
		{
			F_Save();
			break;
		}
		case Select::LOAD:
		{
			memset(UsingFileName, 0, sizeof(UsingFileName));

			F_Load();
			break;
		}
		case Select::INFO:
		{
			ShowInfo();
			break;
		}
		case Select::EXIT:
		{
			printf("�����մϴ�.");
			break;
		}
		default:
		{
			//printf("�ùٸ� ��ɾ �Է����ּ���.");
			system("cls");
		}

		}
	}
	if (pStData != nullptr)
	{
		free(pStData);
	}
}

//#endif // DEBUG