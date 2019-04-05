#include <stdio.h>
#include <memory>



void main()
{
	int j = 0;
	int i = 0;
	int alist[3][3] = { 0 };
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			printf("%p", alist[i][j]);
		}
		
	}









}