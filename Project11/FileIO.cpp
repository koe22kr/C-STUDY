#define _CRT_SECURE_NO_WARNINGS
#include "FileIO.h"



FileIO::FileIO()
{
}


FileIO::~FileIO()
{
}


void FileIO::SaveStudentData()
{
	

	pll->pTMP = pll->gethead()->pNext;
	FILE*fp;
	fp = fopen("../../output/test.txt", "wt");
	fprintf(fp, "%d\n",pll->pst->MemNum );
	while (pll->pTMP != pll->gettail())
	{
		fprintf(fp, "%s %d %d %d %d %d %d\n", pll->pst->Name, pll->pst->Kor, pll->pst->Eng,
			pll->pst->Math, pll->pst->Society, pll->pst->Science,
			pll->pst->Kor + pll->pst->Eng + pll->pst->Math + pll->pst->Society + pll->pst->Science);
		pll->pTMP = pll->pTMP->pNext;
	}
	fclose(fp);
}


void FileIO::LoadStudentData()
{
	if (pll->gethead()->pNext != pll->gettail())
	{
		pll->Free_allMemoryforHead(pll->gethead());
	}
	FILE* fp;
	fp = fopen("../../output/test.txt", "rt");					//���ǻ� �����̸��� �Է¹��� �ʴ´�.
	if (fp == NULL)
	{
		printf("fp�� �ּҰ� NULL. ������ ���� ���Ͽ����ϴ�.");
	}
	fscanf(fp, "%d%*c", &pst->MemNum);
	for (int i = 0; i < pst->MemNum; i++)
	{

		Linklist* pLoadstudent = pll->NewStudentPtr_inLast();
		fscanf(fp, "%s %d %d %d %d %d %d", &pLoadstudent->pst->Name, &pLoadstudent->pst->Kor, &pLoadstudent->pst->Eng,
			&pLoadstudent->pst->Math, &pLoadstudent->pst->Society, &pLoadstudent->pst->Science, &pLoadstudent->pst->Total);


		
		//pLoadstudent->pNext = NULL;

	}
	fclose(fp);
	//printf("%d���� ������ �ε�. �ƹ�Ű�� �Է��ϸ� ���ư��ϴ�.\n",);
	puts("");
	_getch();
}