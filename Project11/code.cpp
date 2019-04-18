#define _CRT_SECURE_NO_WARNINGS
#include "Mgr.h"

//void Init_Head_Tail()
//{
//	memset(gethead(), 0, sizeof(ll_StudentL));
//	memset(gettail(), 0, sizeof(ll_StudentL));
//	gethead()->pNext = gettail();
//	gettail()->pPrev = gethead();
//}

int main(void)
{
//	int a = sizeof(ll_StudentL::Name);

	//NewStudent		Free_allMemory    ////free_allmemory=종료 기동

	//Init_Head_Tail();
	Linklist Tlist;

	


	Mgr TMgr;
	//TMgr.pll->sethead_tail();
	TMgr.InterFace();
	
	
	
	TMgr.pll->Free_allMemoryforHead(TMgr.pll->gethead());

	delete TMgr.pll->gethead();
	delete TMgr.pll->gettail();

	_getch();
	return 0;
}