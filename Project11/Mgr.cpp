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
//	int Kor;				//국영수사과
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
//	return newSt;   //헤드 넥스트값
//}


void Mgr::ER_CHECK_NOT_OPEN_DATA()//추가,로드 말고 다 이걸 불러오기. 학생데이터 없어도 기능하는것 빼고 다 달기.
{
	if (pll->gethead()->pNext == pll->gettail())
	{
		printf("ER:학생정보가 없습니다.(head의next가 tail입니다.");
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
	printf("랜덤 제작 횟수를 입력 :");
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

	printf("새로운 학생 데이터를 입력합니다.");
	printf("이름 :");
	scanf("%s", &newStudent->pst->Name);
	printf("국어 :");
	scanf("%d", &newStudent->pst->Kor);
	printf("영어 :");
	scanf("%d", &newStudent->pst->Eng);
	printf("수학 :");
	scanf("%d", &newStudent->pst->Math);
	printf("사회 :");
	scanf("%d", &newStudent->pst->Society);
	printf("과학 :");
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
//	printf("모든 메모리 반환");
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
	printf("|  이름  |  국어  |  영어  |  수학  |  사회  |  과학  |  총점  |\n");
	while (pTMP != pll->gettail())
	{
		printf("    %s  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  \n", pTMP->pst->Name, pTMP->pst->Kor, pTMP->pst->Eng,
			pTMP->pst->Math, pTMP->pst->Society, pTMP->pst->Science, pTMP->pst->Total);
		pTMP = pTMP->pNext;
	}
	printf("아무키나 입력하면 돌아갑니다.\n");
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
//	fp = fopen("../../output/test.txt", "rt");					//편의상 파일이름은 입력받지 않는다.
//	if (fp == NULL)
//	{
//		printf("fp의 주소가 NULL. 파일을 열지 못하였습니다.");
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
//	//printf("%d명의 데이터 로드. 아무키나 입력하면 돌아갑니다.\n",);
//	puts("");
//	_getch();
//}

Linklist* Mgr::SearchStudent_byname()
{
	ER_CHECK_NOT_OPEN_DATA();

	Linklist* pTMP = pll->gethead()->pNext;
	char Name_for_search[30] = { 0 };
	printf("검색할 이름을 입력해주세요.");
	scanf("%s%*c", Name_for_search);

	if (pTMP == pll->gettail())
	{
		printf("데이터가 존재하지 않습니다.");
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
	printf("|  이름  |  국어  |  영어  |  수학  |  사회  |  과학  |  총점  |\n");
	printf("|    %s  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  \n", pTMP->pst->Name, pTMP->pst->Kor, pTMP->pst->Eng,
		pTMP->pst->Math, pTMP->pst->Society, pTMP->pst->Science, pTMP->pst->Total);
	return pTMP;
}
//ll_StudentL* SearchStudentUP_Total()
//{
//
//	ll_StudentL* pTMP = gethead();
//	if (gethead()->pNext == NULL) printf("학생이 존재하지 않습니다.");
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
	printf("이름 :");
	scanf("%s", &find->pst->Name);
	printf("국어 :");
	scanf("%d", &find->pst->Kor);
	printf("영어 :");
	scanf("%d", &find->pst->Eng);
	printf("수학 :");
	scanf("%d", &find->pst->Math);
	printf("사회 :");
	scanf("%d", &find->pst->Society);
	printf("과학 :");
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
			ER_CHECK_NOT_OPEN_DATA();
			ModySTudentData(SearchStudent_byname());
			break;
		}
		case 3:SORT;
		{
			ER_CHECK_NOT_OPEN_DATA();
			SortStudentUPorDOWN(1);//1올림 0내림
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
		case 7:LOAD;		//_getch 사용
		{
			ER_CHECK_NOT_OPEN_DATA();
			pfile->LoadStudentData();
			break;
		}
		case 8:INFO;		//_getch 사용
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
