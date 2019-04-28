#include <iostream>
#include "Tnode.h"


#pragma once



template <class T>
class Tlinklist
{
public:
	Tlinklist();
	~Tlinklist();

	int m_num;
	Tnode<T>* m_Tail;
	Tnode<T>* m_Head;

	Tnode<T>* Addlink();
	void Del_Node(Tnode<T>* node);
	void Del_Node_All_byhead(Tnode<T>* head);
	void Del_Node_byindex();


	void SetHead();
	void DelHead();
	Tnode<T>* search_byindex();
	
	Tnode<T>* gethead() { return m_Head; };
	Tnode<T>* gettail() { return m_Tail; };
};

template<class T>
Tlinklist<T>::Tlinklist()
{
	SetHead();
	//m_num = 0;

}

template<class T>
Tlinklist<T>::~Tlinklist()
{

}


template <class T>
Tnode<T>*  Tlinklist<T>::Addlink()
{
	Tnode<T>* Newnode = new Tnode<T>;
	Tnode<T>* temp;
	temp = m_Tail->m_prev;

	temp->m_next = Newnode;
	Newnode->m_prev = temp;

	m_Tail->m_prev = Newnode;
	Newnode->m_next = m_Tail;
	

	////////////////////////////////// 임시 값입력
	//Newnode->m_data.index = m_num;
	//Newnode->m_data.Score = 10 + m_num;
	////////////////
	return Newnode;
}//T* m_next;
template<class T>
void Tlinklist<T>::Del_Node(Tnode<T>* node)
{
	Tnode<T>* temp = node;
	temp->m_next->m_prev = temp->m_prev;
	temp->m_prev->m_next = temp->m_next;
	delete temp;
	m_num--;
}


template<class T>
void Tlinklist<T>::Del_Node_All_byhead(Tnode<T>* head)
{
	while (head->m_next != Tlinklist<T>::m_Tail)
	{
		Tnode<T>* temp = head->m_next;
		Del_Node(temp);
	}
}

template<class T>
void Tlinklist<T>::Del_Node_byindex()
{
	Tnode<T>* temp = search_byindex();
	temp->m_next->m_prev = temp->m_prev;
	temp->m_prev->m_next = temp->m_next;
	delete temp;
	m_num--;
}

template<class T>
void Tlinklist<T>::SetHead()
{
	m_Tail = new Tnode<T>;
	m_Head = new Tnode<T>;

	
	m_Head->m_next = m_Tail;
	m_Tail->m_prev = m_Head;
	m_Head->m_data->index = 0;
}

template<class T>
void Tlinklist<T>::DelHead()
{
	if (m_Tail != nullptr)
		delete m_Tail;
	if (m_Head != nullptr)
		delete m_Head;
}

template<class T>
Tnode<T>* Tlinklist<T>::search_byindex()
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
			if (temp->m_data->index == index)
			{
				return temp;
			}
		temp = temp->m_next;
	}
	return NULL;
}
