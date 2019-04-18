#define _CRT_SECURE_NO_WARNINGS

#include "Mgr.h"




Mgr::Mgr()
{
}

Mgr::~Mgr()
{
}



//struct ll_StudentL
//{
//	char Name[10] = { 0 };
//	int Kor;				//���������
//	int Eng;
//	int Math;
//	int Society;
//	int Science;
//	int Total;
//	int SortFLAG = 1;
//	ll_StudentL* pNext = NULL;
//	ll_StudentL* pPrev = NULL;
//
//};
//int MemNum = 0;
//ll_StudentL* gethead() = new ll_StudentL;
//ll_StudentL* gettail() = new ll_StudentL;



//ll_StudentL* NewStudentPtr_inLast()
//{
//
//	ll_StudentL* pTMP;
//	ll_StudentL* newSt = new ll_StudentL;
//	pTMP = gettail()->pPrev;
//
//	gettail()->pPrev = newSt;
//	newSt->pNext = gettail();
//
//	pTMP->pNext = newSt;
//	newSt->pPrev = pTMP;
//
//
//	return newSt;   //��� �ؽ�Ʈ��
//}


void Mgr::ER_CHECK_NOT_OPEN_DATA()//�߰�,�ε� ���� �� �̰� �ҷ�����. �л������� ��� ����ϴ°� ���� �� �ޱ�.
{
	if (pll->gethead()->pNext == pll->gettail())
	{
		printf("ER:�л������� �����ϴ�.(head��next�� tail�Դϴ�.");
		return;
	}
}

void Mgr::AddRandomStudent(int n)
{

	for (int i = 0; i < n; i++)
	{
		Linklist* newStudent = pll->NewStudentPtr_inLast();
		char c[4] = { 0 };
		c[0] = rand() % 26 + 65;
		c[1] = rand() % 26 + 65;
		c[2] = rand() % 26 + 65;
		strcpy(newStudent->pst->Name, c);
		newStudent->pst->Kor = rand() % 101;
		newStudent->pst->Eng = rand() % 101;
		newStudent->pst->Math = rand() % 101;
		newStudent->pst->Society = rand() % 101;
		newStudent->pst->Science = rand() % 101;
		newStudent->pst->Total = (newStudent->pst->Kor + newStudent->pst->Eng + newStudent->pst->Math + newStudent->pst->Society + newStudent->pst->Science);
		
	}
}

void Mgr::RandomStudent()
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


void Mgr::AddNewStudent()
{
	Linklist* newStudent = pll->NewStudentPtr_inLast();

	printf("���ο� �л� �����͸� �Է��մϴ�.");
	printf("�̸� :");
	scanf("%s", &newStudent->pst->Name);
	printf("���� :");
	scanf("%d", &newStudent->pst->Kor);
	printf("���� :");
	scanf("%d", &newStudent->pst->Eng);
	printf("���� :");
	scanf("%d", &newStudent->pst->Math);
	printf("��ȸ :");
	scanf("%d", &newStudent->pst->Society);
	printf("���� :");
	scanf("%d", &newStudent->pst->Science);
	newStudent->pst->Total = (newStudent->pst->Kor + newStudent->pst->Eng + newStudent->pst->Math + newStudent->pst->Society + newStudent->pst->Science);
	
}

//void Free_allMemoryforHead(ll_StudentL* HEAD)
//{
//	ER_CHECK_NOT_OPEN_DATA();
//
//
//	ll_StudentL* DelHead;
//	while (gethead()->pNext != gettail())//
//	{
//		DelHead = HEAD->pNext;
//		DeleteStudentData(DelHead);
//
//	}
//	printf("��� �޸� ��ȯ");
//	HEAD->pNext = NULL;
//}
//
//void DeleteStudentData(ll_StudentL* delpoint)
//{
//	ll_StudentL* TMPpre;
//	ll_StudentL* TMPnext;
//	TMPpre = delpoint->pPrev;
//	TMPnext = delpoint->pNext;
//
//	TMPnext->pPrev = TMPpre;
//	TMPpre->pNext = TMPnext;
//	delete delpoint;
//
//}

void Mgr::ShowStudentInfo()
{
	ER_CHECK_NOT_OPEN_DATA();

	Linklist* pTMP;
	pTMP = pll->gethead()->pNext;
	printf("|  �̸�  |  ����  |  ����  |  ����  |  ��ȸ  |  ����  |  ����  |\n");
	while (pTMP != pll->gettail())
	{
		printf("    %s  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  \n", pTMP->pst->Name, pTMP->pst->Kor, pTMP->pst->Eng,
			pTMP->pst->Math, pTMP->pst->Society, pTMP->pst->Science, pTMP->pst->Total);
		pTMP = pTMP->pNext;
	}
	printf("�ƹ�Ű�� �Է��ϸ� ���ư��ϴ�.\n");
	_getch();
}

//
//void SaveStudentData()
//{
//	ER_CHECK_NOT_OPEN_DATA();
//
//	ll_StudentL* pTMP = gethead()->pNext;
//	FILE*fp;
//	fp = fopen("../../output/test.txt", "wt");
//	fprintf(fp, "%d\n", MemNum);
//	while (pTMP != gettail())
//	{
//		fprintf(fp, "%s %d %d %d %d %d %d\n", pTMP->Name, pTMP->Kor, pTMP->Eng,
//			pTMP->Math, pTMP->Society, pTMP->Science,
//			pTMP->Kor + pTMP->Eng + pTMP->Math + pTMP->Society + pTMP->Science);
//		pTMP = pTMP->pNext;
//	}
//	fclose(fp);
//}
//
//void LoadStudentData()
//{
//	if (gethead()->pNext != gettail())
//	{
//		Free_allMemoryforHead(gethead());
//	}
//	FILE* fp;
//	fp = fopen("../../output/test.txt", "rt");					//���ǻ� �����̸��� �Է¹��� �ʴ´�.
//	if (fp == NULL)
//	{
//		printf("fp�� �ּҰ� NULL. ������ ���� ���Ͽ����ϴ�.");
//	}
//	fscanf(fp, "%d%*c", &MemNum);
//	for (int i = 0; i < MemNum; i++)
//	{
//
//		ll_StudentL* pLoadstudent = NewStudentPtr_inLast();
//		fscanf(fp, "%s %d %d %d %d %d %d", &pLoadstudent->Name, &pLoadstudent->Kor, &pLoadstudent->Eng,
//			&pLoadstudent->Math, &pLoadstudent->Society, &pLoadstudent->Science, &pLoadstudent->Total);
//
//
//		pLoadstudent->SortFLAG = 1;
//		//pLoadstudent->pNext = NULL;
//
//	}
//	fclose(fp);
//	//printf("%d���� ������ �ε�. �ƹ�Ű�� �Է��ϸ� ���ư��ϴ�.\n",);
//	puts("");
//	_getch();
//}

Linklist* Mgr::SearchStudent_byname()
{
	ER_CHECK_NOT_OPEN_DATA();

	Linklist* pTMP = pll->gethead()->pNext;
	char Name_for_search[30] = { 0 };
	printf("�˻��� �̸��� �Է����ּ���.");
	scanf("%s%*c", Name_for_search);

	if (pTMP == pll->gettail())
	{
		printf("�����Ͱ� �������� �ʽ��ϴ�.");
		return 0;
	}
	while (pTMP != pll->gettail())
	{
		if (strstr(pTMP->pst->Name, Name_for_search) != NULL)
		{
			return pTMP;
		}

		pTMP = pTMP->pNext;

	}
	printf("|  �̸�  |  ����  |  ����  |  ����  |  ��ȸ  |  ����  |  ����  |\n");
	printf("|    %s  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  \n", pTMP->pst->Name, pTMP->pst->Kor, pTMP->pst->Eng,
		pTMP->pst->Math, pTMP->pst->Society, pTMP->pst->Science, pTMP->pst->Total);
	return pTMP;
}
//ll_StudentL* SearchStudentUP_Total()
//{
//
//	ll_StudentL* pTMP = gethead();
//	if (gethead()->pNext == NULL) printf("�л��� �������� �ʽ��ϴ�.");
//	//if (pTMP->pNext == NULL)
//	
//	while (pTMP != NULL)
//	{
//
//		pTMP = pTMP->pNext;
//	}
//}

void Mgr::ModySTudentData(Linklist* Target)
{
	Linklist* find = SearchStudent_byname();
	if (find == pll->gettail())return;
	printf("  %s  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  \n", find->pst->Name, find->pst->Kor, find->pst->Eng,
		find->pst->Math, find->pst->Society, find->pst->Science, find->pst->Total);
	printf("�̸� :");
	scanf("%s", &find->pst->Name);
	printf("���� :");
	scanf("%d", &find->pst->Kor);
	printf("���� :");
	scanf("%d", &find->pst->Eng);
	printf("���� :");
	scanf("%d", &find->pst->Math);
	printf("��ȸ :");
	scanf("%d", &find->pst->Society);
	printf("���� :");
	scanf("%d", &find->pst->Science);
	find->pst->Total = (find->pst->Kor + find->pst->Eng + find->pst->Math + find->pst->Society + find->pst->Science);

}

void Mgr::SortStudentUPorDOWN(bool up_1_down_0)
{
	ER_CHECK_NOT_OPEN_DATA();


	Linklist* Target = nullptr;
	for (Linklist* TMPi = pll->gethead()->pNext; TMPi != pll->gettail(); TMPi = TMPi->pNext)
	{
		Target = TMPi;

		for (Linklist* TMPj = TMPi->pNext; TMPj != pll->gettail(); TMPj = TMPj->pNext)
		{

			if (SortIncorDec(up_1_down_0, Target, TMPj))
				Target = TMPj;
		}
		SwapStudentData_without_pre_next(Target, TMPi);

	}
	ShowStudentInfo();
}

bool Mgr::SortIncorDec(bool up_1_down_0, Linklist* Target, Linklist* TMPj)
{
	if (up_1_down_0 == 1)
	{
		if (Target->pst->Total > TMPj->pst->Total)
		{
			return true;
		}

	}
	else if (up_1_down_0 == 0)
	{
		if (Target->pst->Total < TMPj->pst->Total)
		{
			return true;
		}
	}
	return false;
}

void Mgr::SwapStudentData_without_pre_next(Linklist* ppre, Linklist* pnext)
{

	Linklist* pTMP = new Linklist;
	strcpy(pTMP->pst->Name, ppre->pst->Name);
	pTMP->pst->Kor = ppre->pst->Kor;
	pTMP->pst->Eng = ppre->pst->Eng;
	pTMP->pst->Math = ppre->pst->Math;
	pTMP->pst->Society = ppre->pst->Society;
	pTMP->pst->Science = ppre->pst->Science;
	pTMP->pst->Total = ppre->pst->Total;

	strcpy(ppre->pst->Name, pnext->pst->Name);
	ppre->pst->Kor = pnext->pst->Kor;
	ppre->pst->Eng = pnext->pst->Eng;
	ppre->pst->Math = pnext->pst->Math;
	ppre->pst->Society = pnext->pst->Society;
	ppre->pst->Science = pnext->pst->Science;
	ppre->pst->Total = pnext->pst->Total;

	strcpy(pnext->pst->Name, pTMP->pst->Name);
	pnext->pst->Kor = pTMP->pst->Kor;
	pnext->pst->Eng = pTMP->pst->Eng;
	pnext->pst->Math = pTMP->pst->Math;
	pnext->pst->Society = pTMP->pst->Society;
	pnext->pst->Science = pTMP->pst->Science;
	pnext->pst->Total = pTMP->pst->Total;

	delete pTMP;
}

void Mgr::InterFace()
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
			ER_CHECK_NOT_OPEN_DATA();
			ModySTudentData(SearchStudent_byname());
			break;
		}
		case 3:SORT;
		{
			ER_CHECK_NOT_OPEN_DATA();
			SortStudentUPorDOWN(1);//1�ø� 0����
			break;
		}
		case 4:SEARCH;
		{
			ER_CHECK_NOT_OPEN_DATA();
			SearchStudent_byname();
			break;
		}
		case 5:DELETE;
		{
			ER_CHECK_NOT_OPEN_DATA();
			pll->DeleteStudentData(pll->gethead());
			break;
		}
		case 6:SAVE;
		{
			ER_CHECK_NOT_OPEN_DATA();
			pfile->SaveStudentData();
			break;
		}
		case 7:LOAD;		//_getch ���
		{
			ER_CHECK_NOT_OPEN_DATA();
			pfile->LoadStudentData();
			break;
		}
		case 8:INFO;		//_getch ���
		{
			ER_CHECK_NOT_OPEN_DATA();
			ShowStudentInfo();
			break;
		}
		case 9:RANDOM;
		{
			ER_CHECK_NOT_OPEN_DATA();
			RandomStudent();
			break;
		}
		case 0:EXIT;
			break;
		}
	}
}
