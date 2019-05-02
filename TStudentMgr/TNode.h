#pragma once
#include "Std.h"

template <class T>
class Tnode 
{
private:
	T m_data;
	Tnode<T>* m_prev;
	Tnode<T>* m_next;

public:
	
	Tnode();
	Tnode(T data);
	~Tnode();
	//init
	Tnode<T>* Initnode();
	//data
	T* Get_T();
	T* Get_T(Tnode<T>* target_node);
	void Set_T(T setting_data);
	char* Get_T_Name();

	void Setdata_index(int in_index); 
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

template<class T>
T* Tnode<T>::Get_T()
{
	return m_data;
}

template<class T>
T* Tnode<T>::Get_T(Tnode<T>* target_node)
{
	return target_node->Getdata();
}

template<class T>
void Tnode<T>::Set_T(T setting_data)
{
	m_data = setting_data;

}

template<class T>
char* Tnode<T>::Get_T_Name()
{
	return m_data.GetName();
}


