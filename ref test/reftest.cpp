#include <iostream>



int main()
{
	int a;
	int &ref = a;
	a = 10;
	int b = ref;
	//int c = &ref; �̰� �ȵ� &ref = int* ����
	int* pa = &ref;
	a = 15;

	//int &rec= 



	return 0;
}