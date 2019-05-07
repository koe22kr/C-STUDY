#pragma once
#include "TNode.h"

#define MAX_DEPTH 3
class Tree
{
public:
	int m_Data;
	int Depth;

	Tnode<int>* p_Node;
	

	void Create_LittlePlant(Tnode<int>* p_Node);
	//void Print_Tree();
	//void Create_Tree(Tnode<int> p_Node);

	//delete는 생각할것이 많겟다.
	//Tnode<int> Search_Node();




	Tree()
	{	
		p_Node = new Tnode<int>;
		Depth = 0;
		m_Data = 0;
	};
	~Tree()
	{
		delete p_Node;
	};
};

void Tree::Create_LittlePlant(Tnode<int>* p_Node)
{
	if (p_Node->Depth < MAX_DEPTH)
	{
		p_Node->Setprev(new Tnode<int>);
		p_Node->Setnext(new Tnode<int>);

		p_Node->Getprev()->Depth = p_Node->Depth + 1;
		p_Node->Getnext()->Depth = p_Node->Depth + 1;

		p_Node->Getprev()->Setdata(++m_Data);
		p_Node->Getnext()->Setdata(++m_Data);
	
		Create_LittlePlant(p_Node->Getprev());
		Create_LittlePlant(p_Node->Getnext());

	}
}


