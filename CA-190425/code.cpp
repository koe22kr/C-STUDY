#include <iostream>

#include "Tlinklist.h"

using namespace std;






void main()
{
	
	Tlinklist<Tstudent> linklist;

	for (int i = 0; i < 10; i++)
	{
		
		
		linklist.AddLink();
	}

	int del;
	cin >> del;
	
	linklist.Del_data(del);

	linklist.DelHead();

}