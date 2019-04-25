#pragma once
#include "student.h"

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
	
	m_next = nullptr;
	m_prev = nullptr;

}

template <class T>
Tnode<T>::~Tnode()
{
}
