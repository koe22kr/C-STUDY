#include <iostream>
#include "Tnode.h"


#pragma once



template <class T>
class Tlinklist
{
public:
	Tlinklist();
	~Tlinklist();

	
	int index;
	
	Tnode<T>* m_Tail;
	Tnode<T>* m_Head;

	
	Tnode<T>* AddLink();

	void Del_data(int del_index);
	
	void SetHead();
	void DelHead();
	Tnode<T>* search_byindex(int inindex);
};

template<class T>
Tnode<T>* Tlinklist<T>::search_byindex(int inindex)
{
	Tnode<T>* temp = m_Head->m_next;
	for (int i = 0; i < index; i++)
	{temp->m_data
		if (temp->m_data.index == inindex)
		{
			return temp;
		}
		temp = temp->m_next;
	}
	return NULL;
}
template<class T>
void Tlinklist<T>::Del_data(int del_index)
{
	Tnode<T>* temp = search_byindex(del_index);
	temp->m_next->m_prev = temp->m_prev;
	temp->m_prev->m_next = temp->m_next;
	delete temp;
	index--;
}

template<class T>
Tlinklist<T>::Tlinklist()
{
	SetHead();
	//index = 0;

}

template<class T>
Tlinklist<T>::~Tlinklist()
{
	
}

template<class T>
void Tlinklist<T>::SetHead()
{
	m_Tail = new Tnode<T>;
	m_Head = new Tnode<T>;

	m_Head->m_prev = nullptr;
	m_Tail->m_next = nullptr;
	m_Head->m_next = m_Tail;
	m_Tail->m_prev = m_Head;
}

template<class T>
void Tlinklist<T>::DelHead()
{
	if (m_Tail != nullptr)
		delete m_Tail;
	if(m_Head != nullptr)
		delete m_Head;
}

template <class T>
Tnode<T>*  Tlinklist<T>::AddLink()
{
	Tnode<T>* Newnode = new Tnode<T>;
	Tnode<T>* temp;
	temp = m_Tail->m_prev;

	temp->m_next = Newnode;
	Newnode->m_prev = temp;

	m_Tail->m_prev = Newnode;
	Newnode->m_next = m_Tail;
	index++;
	
	//////////////////////////////// 임시 값입력
	Newnode->m_data.index = index;
	Newnode->m_data.Score = 10 + index;
	//////////////
	return Newnode;
}//T* m_next;

