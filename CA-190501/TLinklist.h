#include <iostream>
#include "Tnode.h"


#pragma once



template <class T>
class TLinklist
{
public:
	TLinklist();
	~TLinklist();

	int m_num;
	Tnode<T>* m_Tail;
	Tnode<T>* m_Head;

	Tnode<T>* Add_Link_Back();
	
public:
	void Del_Node_T(Tnode<T>* node);
	void Del_Node_Tptr(Tnode<T>* node,Tnode<T>* Tnode);
	
	void Del_Node_All_byhead_T(Tnode<T>* head);
	void Del_Node_All_byhead_Tptr(Tnode<T>* head);
	void Del_Node_byindex();


	void SetHeads();
	void DelHeads();
	Tnode<T>* Search_byindex();
	
	Tnode<T>* GetHead() { return m_Head; };
	Tnode<T>* GetTail() { return m_Tail; };
	Tnode<T>* GetFirst() { return m_Head->Getnext(); };
	Tnode<T>* GetLast() { return m_Tail->Getprev(); };
	
	T Getdata(Tnode<T>* target_node);
};

template<class T>
TLinklist<T>::TLinklist()
{
	cout << "Tlinklist~" << endl;
	SetHeads();
	//m_num = 0;

}

template<class T>
TLinklist<T>::~TLinklist()
{
	cout << "~Tlinklist" << endl;
	DelHeads();
}


template <class T>
Tnode<T>*  TLinklist<T>::Add_Link_Back()
{
	Tnode<T>* Newnode = new Tnode<T>();
	Tnode<T>* temp;
	
	temp = m_Tail->Getprev();
	//temp = m_Tail->m_prev;

	temp->Setnext(Newnode);
//	temp->m_next = Newnode;

	Newnode->Setprev(temp);
	//Newnode->m_prev = temp;

	m_Tail->Setprev(Newnode);
	//m_Tail->m_prev = Newnode;

	Newnode->Setnext(m_Tail);
	//Newnode->m_next = m_Tail;
	

	////////////////////////////////// 임시 값입력
	//Newnode->m_data.index = m_num;
	//Newnode->m_data.Score = 10 + m_num;
	////////////////
	return Newnode;
}//T* m_next;
template<class T>
void TLinklist<T>::Del_Node_T(Tnode<T>* node)
{
	Tnode<T>* temp = node;
	temp->m_next->m_prev = temp->m_prev;
	temp->m_prev->m_next = temp->m_next;

	delete temp;
	m_num--;
}
template<class T>
void TLinklist<T>::Del_Node_Tptr(Tnode<T>* node, Tnode<T>* node_for_data)
{
	Tnode<T>* temp = node;
	temp->m_next->m_prev = temp->m_prev;
	temp->m_prev->m_next = temp->m_next;
	delete node_for_data->m_data;
	delete temp;
	m_num--;
}

template<class T>
void TLinklist<T>::Del_Node_All_byhead_T(Tnode<T>* head)
{
	while (head->m_next != m_Tail)
	{
		Tnode<T>* temp = head->m_next;
		Del_Node_T(temp);
	}
}
template<class T>
void TLinklist<T>::Del_Node_All_byhead_Tptr(Tnode<T>* head)
{
	while (head->m_next != m_Tail)
	{
		Tnode<T>* temp = head->m_next;
		Del_Node_Tptr(temp, head);
	}
}

template<class T>
void TLinklist<T>::Del_Node_byindex()
{
	Tnode<T>* temp = Search_byindex();
	temp->m_next->m_prev = temp->m_prev;
	temp->m_prev->m_next = temp->m_next;
	delete temp;
	m_num--;
}

template<class T>
void TLinklist<T>::SetHeads()
{
	m_Tail = new Tnode<T>;
	m_Head = new Tnode<T>;

	m_Head->Setnext(m_Tail);
	//m_Head->m_next = m_Tail;
	m_Tail->Setprev(m_Head);
	//m_Tail->m_prev = m_Head;
	m_Head->Getdata_index() = 0;
	//m_Head->m_data.index = 0;
}

template<class T>
void TLinklist<T>::DelHeads()
{
	if (m_Tail != nullptr)
		delete m_Tail;
	if (m_Head != nullptr)
		delete m_Head;
}

template<class T>
Tnode<T>* TLinklist<T>::Search_byindex()
{
	int index = 0;
	while (index <= 0 || m_num < index)   //index==0 이거나 m_num보다 클때 루프
	{
		cout << " 번호 입력 : ";
		cin >> index;
	}
	Tnode<T>* temp = m_Head->m_next;
	for (int i = 0; i < m_num; i++)
	{
		temp->m_data;
			if (temp->m_data.index == index)
			{
				return temp;
			}
		temp = temp->m_next;
	}
	return NULL;
}


template<class T>
T TLinklist<T>::Getdata(Tnode<T>* target_node)
{
	return target_node->Getdata();
}
