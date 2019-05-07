#pragma once
#include "Std.h"

template <class T>
class Tnode
{
	
	T m_data;
	Tnode<T>* m_prev;
	Tnode<T>* m_next;

public:
	Tnode();
	Tnode(T data);
	~Tnode();

	//Tree용
	int Depth;
	//init
	Tnode<T>* Initnode();
	//data
	void Setdata(T setting_data);
	T Getdata();

	void Setdata_index(int in_index);   //모든 데이터는 인덱스를 가지고 있다고 가정하고 사용.
	int& Getdata_index();
	//prev
	void Setprev(Tnode<T>* setting_node);
	Tnode<T>* Getprev();
	//next
	void Setnext(Tnode<T>* setting_node);
	Tnode<T>* Getnext();

};

template <class T>
Tnode<T>::Tnode()
{
	cout << "Tnode(T)~" << endl;
	m_next = nullptr;
	m_prev = nullptr;
	Depth = 0;
}

template <class T>
Tnode<T>::Tnode(T data) : m_data(data)
{
	cout << "Tnode(T)~" << endl;
	m_next = nullptr;
	m_prev = nullptr;
}

template <class T>
Tnode<T>::~Tnode()
{
	cout << "~Tnode" << endl;
}

template<class T>
Tnode<T>* Tnode<T>::Initnode()
{
	m_prev = nullptr;
	m_next = nullptr;
}
template<class T>
//
void Tnode<T>::Setdata(T setting_data)
{
	m_data = setting_data;
}

template<class T>
T Tnode<T>::Getdata()
{
	return m_data;
}

template<class T>
void Tnode<T>::Setdata_index(int in_index)
{
	m_data.index = in_index;
}

template<class T>
int& Tnode<T>::Getdata_index()
{
	return m_data.index;
}
//
template<class T>
void Tnode<T>::Setprev(Tnode<T>* setting_node)
{
	m_prev = setting_node;
}

template<class T>
Tnode<T>* Tnode<T>::Getprev()
{
	return m_prev;
}

template<class T>
void Tnode<T>::Setnext(Tnode<T>* setting_node)
{
	m_next = setting_node;
}

template<class T>
Tnode<T>* Tnode<T>::Getnext()
{
	return m_next;
}





