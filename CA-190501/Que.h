#pragma once
#include "Tlinklist.h"

class dummy
{
public:
	int index = 0;
	int data = 0;
	dummy() {};
	dummy(int a,int b):index(a),data(b)
	{

	};
	~dummy() {};
};

class Que
{
	int count;
public:
	Que();
	~Que();

	TLinklist<dummy>* list;
public:
	dummy Front();
	dummy Back();
	void Push_back(dummy data);
	void Pop();
	void clear();
	void Size();

};

Que::Que()
{
	list = new TLinklist<dummy>;
}


Que::~Que()
{
}

dummy Que::Front()
{
	if (list->GetFirst() == list->GetTail())
	{
		cout << "Front==Tail" << endl;
//		return list->Getdata(list->GetTail());
	}
	return list->Getdata(list->GetFirst());
}

dummy Que::Back()
{
	if (list->GetLast() == list->GetHead())
	{
		cout << "Back==Head" << endl;
		//return list->Getdata(list->GetHead());
	}
	return list->Getdata(list->GetLast());
}	

void Que::Push_back(dummy data)
{
	Tnode<dummy>* temp = new Tnode<dummy>;
	temp = list->Add_Link_Back();

}