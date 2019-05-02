#pragma once
#include "TLinkedList.h"

template<class T>
class TFileio
{
public:

	void SaveStudentData(TLinkedList<T>* obj);
	void LoadStudentData(TLinkedList<T>* obj);
};

template<class T>
void TFileio<T>::SaveStudentData(TLinkedList<T>* obj)
{
	cout << "SaveStudentData_START" << endl;

	Tnode<T>* temp = obj->GetHead()->Getnext();
	FILE* fp;
	fp = fopen("../../output/test.txt", "wt");
	fprintf(fp, "%d\n", obj->m_num);
	
	while (temp != obj->GetTail())
	{
		for (int i = 0; i < temp->Get_T()->status_num; i++)
		{
			if (i + 1 == temp->Get_T()->status_num)
			{
				fprintf(fp, "%d" temp->Get_T()->Get_Data(i);
			}
			else
			{
				fprintf(fp, "%d " temp->Get_T()->Get_Data(i);
			}			
		}
	}
	fclose(fp);
	cout << "SaveStudentData_END" << endl;
}

template<class T>
void TFileio<T>::LoadStudentData(TLinkedList<T>* obj)
{
	cout << "LoadStudentData_START" << endl;
	if (obj->GetHead()->Getnext() != obj->m_Tail)
	{
		obj->Del_Node_All_byhead_T(obj->GetHead());
	}
	FILE* fp;
	fp = fopen("../../output/test.txt", "rt");					//편의상 파일이름은 입력받지 않는다.
	if (fp == NULL)
	{
		printf("fp의 주소가 NULL. 파일을 열지 못하였습니다.");
	}
	fscanf(fp, "%d%*c", &(obj->m_num));
	for (int i = 0; i < obj->m_num; i++)
	{

		Tnode<T>* pLoadstudent = obj->Add_Link_Back();
		fscanf(fp, "%s", &pLoadstudent->Get_T()->Get_Data[0]);			//fscanf 말고 입력형식 적지 않아도 되는함수라면 내부 for문 한번에 데이터 로드가능할듯.
		for (int j = 1; j < temp->Get_T()->status_num, j++)
		{
			fscanf(fp, "%d", &pLoadstudent->Get_T()->Get_Data[j]);
		}
		
	}
	fclose(fp);
	//printf("%d명의 데이터 로드. 아무키나 입력하면 돌아갑니다.\n",);
	cout << "LoadStudentData_END" << endl;
}