#include <iostream>



struct MyStruct
{
	int x;
	int y;
};


int main(void)
{
//	int Alist[10] = { 1,2,3,4,5,6,7,8 };
	MyStruct* pAlist = (MyStruct*)malloc(sizeof(MyStruct) * 10);
	for (int i = 0; i < 10; ++i)
	{
		pAlist[i].x = i;
		pAlist[i].y = i * 2;
	}
		
	free(&(pAlist[1]));
	free(pAlist);
	


	return 0;

}