#pragma once
#include "TStudent.h"

template <class T>
class Tnode
{
public:
	Tnode();
	~Tnode();

	T m_data;

	Tnode<T>* m_next;
	Tnode<T>* m_prev;
};

template <class T>
Tnode<T>::Tnode()
{
	m_next = 0;
	m_prev = 0;
}

template <class T>
Tnode<T>::~Tnode()
{
	cout << "~Tnode" << endl;
}
