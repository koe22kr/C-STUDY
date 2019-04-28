#pragma once
#include "Tstudent.h"

template <class T>
class Tnode
{
public:
	Tnode();
	~Tnode();

	T* m_data;

	Tnode<T>* m_next;
	Tnode<T>* m_prev;
	
	void setnode();
};
template<class T>
void Tnode<T>::setnode()
{

}

template <class T>
Tnode<T>::Tnode()
{
	m_data = new T;

	

}

template <class T>
Tnode<T>::~Tnode()
{
	delete m_data;

}
