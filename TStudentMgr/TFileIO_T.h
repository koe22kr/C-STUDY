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
	fp = fopen("../../output/test.txt", "rt");					//���ǻ� �����̸��� �Է¹��� �ʴ´�.
	if (fp == NULL)
	{
		printf("fp�� �ּҰ� NULL. ������ ���� ���Ͽ����ϴ�.");
	}
	fscanf(fp, "%d%*c", &(obj->m_num));
	for (int i = 0; i < obj->m_num; i++)
	{

		Tnode<T>* pLoadstudent = obj->Add_Link_Back();
		fscanf(fp, "%s", &pLoadstudent->Get_T()->Get_Data[0]);			//fscanf ���� �Է����� ���� �ʾƵ� �Ǵ��Լ���� ���� for�� �ѹ��� ������ �ε尡���ҵ�.
		for (int j = 1; j < temp->Get_T()->status_num, j++)
		{
			fscanf(fp, "%d", &pLoadstudent->Get_T()->Get_Data[j]);
		}
		
	}
	fclose(fp);
	//printf("%d���� ������ �ε�. �ƹ�Ű�� �Է��ϸ� ���ư��ϴ�.\n",);
	cout << "LoadStudentData_END" << endl;
}