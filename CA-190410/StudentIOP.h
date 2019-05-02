#pragma once
 

#include <iostream>
#include<conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>


enum Select
{
	ADD = 1, MODIFY, SORT, SEARCH, DELETE, SAVE, LOAD, INFO, EXIT = 0
	//1:추가 2:수정  3:정렬 4:검색  5:삭제  6:저장 7:불러오기 8:정보보기   9:종료
};
//enum Select {
//	KOR,ENG,MATH,SOSI,SCI
//};
struct StudyData
{

	char Name[10] = { 0 };
	int Kor;				//국영수사과
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

//void F_OpenR(const char* FILE_Name)			F_Load로 병합
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
	printf("생성할 파일의 이름을 입력하세요.");
	scanf("%s", UsingFileName);
	fp = fopen(UsingFileName, "w+t");				 //&fp값 생성

}
void F_Load()
{
	if (fp != NULL)fclose(fp);

	if (*UsingFileName == NULL)
	{
		printf("불러올 파일의 이름을 입력하세요.");
		scanf("%s", UsingFileName);
		fp = fopen(UsingFileName, "r+t"); //&fp값 생성
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


void F_Save()      //MemberNumber,Fp   //fclose(fp) free(pStData,padddata) 세이브시 파일닫음.
{
	int iDeletecount = 0;
	if (*UsingFileName == NULL)
	{
		printf("열린 파일이 없습니다.");
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
		printf("열린 파일이 없어서 새로 만듭니다니다.\n");
		F_Create();
	}


	padddata = (StudyData*)malloc(sizeof(StudyData));
	printf("[추가]\n");
	printf("이름을 입력해주세요.");
	scanf("%s", &padddata->Name);
	printf("국어 성적을 입력해주세요.");
	scanf("%d", &padddata->Kor);
	printf("영어 성적을 입력해주세요.");
	scanf("%d", &padddata->Eng);
	printf("수학 성적을 입력해주세요.");
	scanf("%d", &padddata->Math);
	printf("사회 성적을 입력해주세요.");
	scanf("%d", &padddata->Society);
	printf("과학 성적을 입력해주세요.");
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
int F_Search() //이름 중복은 예외로 한다. 구조체 계수반환;
{
	char* psearched;
	char keyward[20];
	printf("검색할 이름을 입력해주세요. : ");
	scanf("%s", keyward);
	_getch();
	for (int i = 0; i < MemberNumber; i++)
	{
		psearched = strstr(pStData[i].Name, keyward);
		if (psearched != NULL)
		{
			printf("%d번 이름:%s 국어:%d 영어:%d 수학:%d 사회:%d 과학:%d\n", i + 1, pStData[i].Name, pStData[i].Kor, pStData[i].Eng,
				pStData[i].Math, pStData[i].Society, pStData[i].Science);
			return i;
		}
	}
	printf("해당 이름을 찾지 못하였습니다.\n");
	return 0;
}
void F_Modify()
{


	printf("수정할 대상을 검색합니다.\n");
	int i = F_Search();
	printf("수정을 시작합니다.\n");
	printf("이름:");
	scanf("%s", pStData[i].Name);			//& 제거 ㄱㅊ?
	printf("국어점수 :");
	scanf("%d", &pStData[i].Kor);
	printf("영어점수 :");
	scanf("%d", &pStData[i].Eng);
	printf("수학점수 :");
	scanf("%d", &pStData[i].Math);
	printf("사회점수 :");
	scanf("%d", &pStData[i].Society);
	printf("과학점수 :");
	scanf("%d", &pStData[i].Science);
	printf("\n-수정완료.-\n");
}

void F_SortScoreKor()			////sort 교환을 변수 하나만 하는게 아니라 줄 통째로 교환 해야함.
{
	StudyData TMP;
	printf("점수를 내림차순으로 정렬");
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
	printf("점수를 내림차순으로 정렬");
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
	printf("점수를 내림차순으로 정렬");
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
	printf("점수를 내림차순으로 정렬");
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
	printf("점수를 내림차순으로 정렬");
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
	printf("이름을 내림차순으로 정렬");
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
	printf("이름을 올림차순으로 정렬");
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
	printf("삭제할 사람을 검색합니다.");
	i = F_Search();
	if (i == NULL)return;

	printf("%s의 정보를 삭제할까요? y/n", pStData[i].Name);
;	if (('n' || 'N') == getchar())
	{
		return;
	}
	memset(&pStData[i], 0, sizeof(StudyData));
	printf("삭제완료.. 이름 정렬을 실시합니다.");
	F_SortNameDown();
	fseek(fp, 0, SEEK_SET);
	fprintf(fp, "%d\n", --MemberNumber);
	F_Save();
}

void F_Sort()
{

	int select;//1:이름 2:국 3:영 4:수 5:사 6:과
	printf("정렬인자를 선택하세요.");
	printf("|1: 이름 | 2: 국어| 3: 영어| 4: 수학| 5: 사회| 6: 과학| 0:종료|");
	scanf("%d%*c", &select);
	switch (select)
	{
	case 1:
	{
		F_SortNameUp();
		break;
	}
	case 2: //국어
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
		printf("잘못된 숫자를 입력");
	}


}

void ShowInfo()
{
	printf("|  이름  |  국어  |  영어  |  수학  |  사회  |  과학  |\n");
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
		printf("========================	성	적	관	리	================== FILE_Name : %s\n", UsingFileName);
		printf("| 1:추가  | 2:수정  | 3:정렬  | 4:검색  | 5:삭제  | 6:저장  | 7:불러오기  | 8:학생정보  | 0:종료  |\n");
		printf("명령어 : ");
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
		case Select::SORT: // 삭제시 호출당할예정
		{
			F_Sort();
			break;
		}
		case Select::SEARCH:     //삭제시 호출당할 예정
		{
			F_Search();
			break;
		}
		case Select::DELETE:			//내부에서 정렬 호출
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
			printf("종료합니다.");
			break;
		}
		default:
		{
			//printf("올바른 명령어를 입력해주세요.");
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