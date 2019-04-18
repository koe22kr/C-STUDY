#pragma once

#include "Student.h"

class Linklist
{private:
	 
public:
	static Linklist* g_pHead;
	static Linklist* g_pTail;// = new Linklist;


	Linklist* pNext;// = NULL;
	Linklist* pPrev;// = NULL;
	
	Linklist* pTMP;
	
		
	Student* pst;
		
	Linklist();
	~Linklist();

	void sethead_tail();
	Linklist* gethead();
	Linklist* gettail();
	Linklist* NewStudentPtr_inLast();
	void DeleteStudentData(Linklist* delpoint);
	void Free_allMemoryforHead(Linklist* HEAD);





};




