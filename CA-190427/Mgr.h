#pragma once

#include "TFileio.h"

template<class T>
class Mgr
{
public:
	Mgr();
	~Mgr();
	
	Tlinklist<T>* obj_link;
	TFileio<T>* obj_fileio;

	void ShowStudentInfo();
	void AddRandomStudent(int n);
	void RandomStudent();
	Tnode<T>* SearchStudent_byname();
	void ModySTudentData(Tnode<T>* Target);
	void SortStudentUPorDOWN(bool up_1_down_0);
	bool SortIncorDec(bool up_1_down_0, Tnode<T>* Target, Tnode<T>* temp_j);
	void SwapStudentData_without_pre_next(Tnode<T>* pprev, Tnode<T>* pnext);
	void InterFace();

	void Del_option();

	void initmgr();
};
template<class T>
void Mgr<T>::initmgr()
{
	obj_link = new Tlinklist<T>;
	obj_fileio = new TFileio<T>;
}

//Tnode<T>* find = SearchStudent_byname(); 수정시 선 호출
template<class T>
Mgr<T>::Mgr()
{
	initmgr();
}
template<class T>
Mgr<T>::~Mgr()
{
	delete obj_link;
	delete obj_fileio;
}

template<class T>
void Mgr<T>::ShowStudentInfo()
{	
	cout << "ShowStudentInfo_START" << endl;
	
	Tnode<T>* temp;
	temp = obj_link->m_Head->m_next;
		printf("|  이름  |  번호  |  국어  |  영어  |  수학  |  총점  |  평균  |\n");
	while (temp != obj_link->m_Tail)
	{
		printf("    %s  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |\n", 
			temp->m_data->Name,temp->m_data->index, temp->m_data->Kor, temp->m_data->Eng,
			temp->m_data->Math,temp->m_data->Total, temp->m_data->Average);
		temp = temp->m_next;
	}
	cout << "ShowStudentInfo_END" << endl;
}

template<class T>
void Mgr<T>::ModySTudentData(Tnode<T>* Target)
{
	cout << "ModySTudentData_START" << endl;
	
	if (Target == obj_link->m_Tail)return;
	if (Target->m_data->index != NULL)
	{
		printf("  %s  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |\n",
			Target->m_data->Name, Target->m_data->Kor, Target->m_data->Eng,
			Target->m_data->Math, Target->m_data->Total, Target->m_data->Average);
		obj_link->m_num++;
	}
	printf("이름 :");
	scanf("%s", &Target->m_data->Name);
	printf("국어 :");
	scanf("%d", &Target->m_data->Kor);
	printf("영어 :");
	scanf("%d", &Target->m_data->Eng);
	printf("수학 :");
	scanf("%d", &Target->m_data->Math);
	Target->m_data->Total = Target->m_data->Kor + Target->m_data->Eng + Target->m_data->Math;
	Target->m_data->Average = Target->m_data->Total / 3;
	Target->m_data->index = Target->m_prev->m_data->index + 1;
	//cout<<setw(4)    == %4d
	cout << "ModySTudentData_END" << endl;
}

template<class T>
void Mgr<T>::AddRandomStudent(int n)
{
	if (obj_link->m_Head->m_next != obj_link->m_Tail)
	{
		obj_link->Del_Node_All_byhead(obj_link->m_Head);
	}
	
	cout << "AddRandomStudent_START" << endl;
	for (int i = 0; i < n; i++)
	{
		Tnode<T>* newStatus = obj_link->Addlink();
		char c[4] = { 0 };
		c[0] = rand() % 26 + 65;
		c[1] = rand() % 26 + 65;
		c[2] = rand() % 26 + 65;
		strcpy(newStatus->m_data->Name, c);
		newStatus->m_data->Kor = rand() % 101;
		newStatus->m_data->Eng = rand() % 101;
		newStatus->m_data->Math = rand() % 101;
		newStatus->m_data->Total = (newStatus->m_data->Kor + newStatus->m_data->Eng + newStatus->m_data->Math);
		newStatus->m_data->Average = (newStatus->m_data->Total) / 3;
		newStatus->m_data->index = newStatus->m_prev->m_data->index+1;
		obj_link->m_num++;
	}
	cout << "AddRandomStudent_END" << endl;

}
template<class T>
void Mgr<T>::RandomStudent()
{
	cout << "RandomStudent_START" << endl;
	int n = 0;
	printf("랜덤 제작 횟수를 입력 :");
	scanf("%d", &n);
	if (n == 0)
	{
		return;
	}
	AddRandomStudent(n);
	cout << "RandomStudent_END" << endl;
}

template<class T>
Tnode<T>* Mgr<T>::SearchStudent_byname()
{
	cout << "SearchStudent_byname_START" << endl;
	Tnode<T>* temp = obj_link->m_Head->m_next;
	char Name_for_search[30] = { 0 };
	printf("검색할 이름을 입력해주세요.");
	cin >> Name_for_search;

	if (temp == obj_link->m_Tail)
	{
		printf("데이터가 존재하지 않습니다.");
		return obj_link->m_Tail;
	}
	while (temp != obj_link->m_Tail)
	{
		if (strstr(temp->m_data->Name, Name_for_search) != NULL)
		{
			printf("|  이름  |  국어  |  영어  |  수학  |  총점  |  평균  |\n");
			printf("|    %s  |  %4d  |  %4d  |  %4d  |  %4d  |  %4d  |\n",
				temp->m_data->Name, 
				temp->m_data->Kor, temp->m_data->Eng, temp->m_data->Math, 
				temp->m_data->Total, temp->m_data->Average);
			cout << "SearchStudent_byname_END_SUCCESS" << endl;
			return temp;
		}

		temp = temp->m_next;

	}
	cout << "SearchStudent_byname_END_FAIL" << endl;
	return temp;
}

template<class T>
void Mgr<T>::SortStudentUPorDOWN(bool up_1_down_0)
{
	Tnode<T>* Target = nullptr;
	for (Tnode<T>* temp_i = obj_link->m_Head->m_next; 
		temp_i != obj_link->m_Tail;
		temp_i = temp_i->m_next)
	{
		Target = temp_i;

		for (Tnode<T>* temp_j = temp_i->m_next;
			temp_j != obj_link->m_Tail;
			temp_j = temp_j->m_next)
		{
			if (SortIncorDec(up_1_down_0, Target, temp_j))
				Target = temp_j;
		}
		SwapStudentData_without_pre_next(Target, temp_i);
	}
	ShowStudentInfo();
}
template<class T>
bool Mgr<T>::SortIncorDec(bool up_1_down_0, Tnode<T>* Target, Tnode<T>* temp_j)
{
	if (up_1_down_0 == 1)
	{
		if (Target->m_data->Total > temp_j->m_data->Total)
		{
			return 1;
		}

	}
	else if (up_1_down_0 == 0)
	{
		if (Target->m_data->Total < temp_j->m_data->Total)
		{
			return 1;
		}
	}
	return 0;
}
template<class T>
void Mgr<T>::SwapStudentData_without_pre_next(Tnode<T>* pprev, Tnode<T>* pnext)
{

	Tnode<T>* temp = new Tnode<T>;
	strcpy(temp->m_data->Name, pprev->m_data->Name);
	
	temp->m_data->Kor = pprev->m_data->Kor;
	temp->m_data->Eng = pprev->m_data->Eng;
	temp->m_data->Math = pprev->m_data->Math;
	temp->m_data->Total = pprev->m_data->Total;
	temp->m_data->Average = pprev->m_data->Average;


	strcpy(pprev->m_data->Name, pnext->m_data->Name);
	pprev->m_data->Kor = pnext->m_data->Kor;
	pprev->m_data->Eng = pnext->m_data->Eng;
	pprev->m_data->Math = pnext->m_data->Math;
	pprev->m_data->Total = pnext->m_data->Total;
	pprev->m_data->Average = pnext->m_data->Average;


	strcpy(pnext->m_data->Name, temp->m_data->Name);
	pnext->m_data->Kor = temp->m_data->Kor;
	pnext->m_data->Eng = temp->m_data->Eng;
	pnext->m_data->Math = temp->m_data->Math;
	pnext->m_data->Total = temp->m_data->Total;
	pnext->m_data->Average = temp->m_data->Average;
	

	delete temp;
}

template<class T>
void Mgr<T>::InterFace()
{
	int select = 1;
	while (select)
	{
//		system("cls");
		printf("========================	성	적	관	리	======================================\n ");
		printf("| 1:추가  | 2:수정  | 3:정렬  | 4:검색  | 5:삭제  | 6:저장  | 7:불러오기  | 8:학생정보| 9:랜덤  | 0:종료  |\n");
		printf("명령어 : ");
		scanf("%d%*c", &select);




		switch (select)  //
		{
		case 1:ADD;             //NewStudentPtr_inback + 입력 으로 구성하기.
		{
			ModySTudentData(obj_link->Addlink());
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
			Del_option();
			
			break;
		}
		case 6:SAVE;
		{
			obj_fileio->SaveStudentData(obj_link);
			break;
		}
		case 7:LOAD;		//_getch 사용
		{
			obj_fileio->LoadStudentData(obj_link);
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
template<class T>
void Mgr<T>::Del_option()
{
	int choice = 0;
	while (choice != 1 && choice != 2)
	{
		cout << "전체삭제:1 | 개별삭제:2" << endl;
		cin >> choice;
	}
	
	if (choice == 1)
	{
		obj_link->Del_Node_All_byhead(obj_link->m_Head);
	}
	else if (choice == 2)
	{
		
		obj_link->Del_Node(obj_link->search_byindex());
	}	
}