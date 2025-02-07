#pragma once
#include "TlinkList.h"

template<class T>
class TFileio
{
public:

void SaveStudentData(TlinkedList<T>* obj);
void LoadStudentData(TlinkedList<T>* obj);
};

template<class T>
void TFileio<T>::SaveStudentData(TlinkedList<T>* obj)
{
	cout << "SaveStudentData_START" << endl;

	Tnode<T>* temp = obj->m_Head->m_next;
	FILE* fp;
	fp = fopen("../../output/test.txt", "wt");
	fprintf(fp, "%d\n", obj->m_num);
	while (temp != obj->m_Tail)
	{
		fprintf(fp, "%s %d %d %d %d %d %d \n", temp->m_data.Name, temp->m_data.index, temp->m_data.Kor, temp->m_data.Eng,
			temp->m_data.Math, temp->m_data.Total, temp->m_data.Average);
		temp = temp->m_next;
	}
	fclose(fp);
	cout << "SaveStudentData_END" << endl;
}

template<class T>
void TFileio<T>::LoadStudentData(TlinkedList<T>* obj)
{
	cout << "LoadStudentData_START" << endl;
	if( obj->m_Head->m_next != obj->m_Tail)
	{
		obj->Del_Node_All_byhead_T(obj->m_Head);
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

		Tnode<T>* pLoadstudent = obj->Addlink();
		fscanf(fp, "%s %d %d %d %d %d %d ", &pLoadstudent->m_data.Name, &pLoadstudent->m_data.index,
										 &pLoadstudent->m_data.Kor, &pLoadstudent->m_data.Eng, &pLoadstudent->m_data.Math,
										 &pLoadstudent->m_data.Total, &pLoadstudent->m_data.Average);
	}
	fclose(fp);
	//printf("%d명의 데이터 로드. 아무키나 입력하면 돌아갑니다.\n",);
	cout << "LoadStudentData_END" << endl;
}