#include "Linklist.h"

void Linklist::sethead_tail()
{
g_pHead->pNext = nullptr;
g_pHead->pPrev = nullptr;
g_pTail->pNext = nullptr;
g_pTail->pPrev = nullptr;
}
Linklist* Linklist::gethead()
{
	return g_pHead;
}
Linklist* Linklist::gettail()
{
	return g_pTail;
}
Linklist* Linklist::NewStudentPtr_inLast()
{

	Linklist* pTMP;
	Linklist* newSt = new Linklist;
	pTMP = gettail()->pPrev;

	gettail()->pPrev = newSt;
	newSt->pNext = gettail();

	pTMP->pNext = newSt;
	newSt->pPrev = pTMP;


	return newSt;   //헤드 넥스트값
}

void Linklist::Free_allMemoryforHead(Linklist* HEAD)
{

	Linklist* DelHead;
	while (gethead()->pNext != gettail())//
	{
		DelHead = HEAD->pNext;
		DeleteStudentData(DelHead);

	}
	printf("모든 메모리 반환");
	HEAD->pNext = NULL;
}

void Linklist::DeleteStudentData(Linklist* delpoint)
{
	Linklist* TMPpre;
	Linklist* TMPnext;
	TMPpre = delpoint->pPrev;
	TMPnext = delpoint->pNext;

	TMPnext->pPrev = TMPpre;
	TMPpre->pNext = TMPnext;
	delete delpoint;

}
Linklist::~Linklist()
{
}
Linklist::Linklist()
{
	/*pPrev = nullptr;
	pNext = nullptr;*/

}



Linklist* Linklist::g_pHead = new Linklist;
Linklist* Linklist::g_pTail = new Linklist;
