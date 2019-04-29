#include "Mgr_T.h"

using namespace std;


//		T     =  Student  
//		Tptr  =	 Student*


void main()
{
	Mgr<Student>* Newmgr = new Mgr<Student>;
	Newmgr->Interface();
	delete Newmgr;

}