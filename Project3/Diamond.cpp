#include <iostream>
#include<cstdio>
#include <string>
#include <stdlib.h>
//#define iffor
//#define forforforfor
//#define forfor
#ifdef iffor

int main()
{



	int n = 0;
	int i = 0, j = 0;

	printf("다이아몬드의 최대길이(홀수)를 입력해주세요.");
	scanf_s("%d", &n);
	//
	while (n % 2 == 0)
	{
		printf("짝수가 입력되었습니다. 다시 입력해 주세요 : ");
		scanf_s("%d", &n);

	}
	//
	for (i = 0; i < n; ++i)
	{
		if (i < n / 2)
		{
			for (j = i; j < n / 2; ++j)
			{
				printf("-");
			}
			for (j = -1; j < 2 * i; ++j)
			{
				printf("*");
			}

		}
		else
		{
			for (j = i; j > n / 2; --j)
			{
				printf("-");

			}
			for (j = -1; j > (i - n) * 2; --j)
			{
				printf("*");
			}

		}
		putchar('\n');

	}

	return 0;
}

#endif
#ifdef forforforfor
int main()
{



	int n = 0;
	int i = 0, j = 0;

	printf("다이아몬드의 최대길이(홀수)를 입력해주세요.");
	scanf_s("%d", &n);
	//
	while (n % 2 == 0)
	{
		printf("짝수가 입력되었습니다. 다시 입력해 주세요 : ");
		scanf_s("%d", &n);

	}
	//
	for (i = 0; i < n / 2; ++i)
	{
		{
			for (j = i; j < n / 2; ++j)
			{
				printf("-");
			}
			for (j = -1; j < 2 * i; ++j)
			{
				printf("*");
			}

		}putchar('\n');

	}
	for(i=i; i<n;++i)
		{
			for (j = i; j > n / 2; --j)
			{
				printf("-");

			}
			for (j = -1; j > (i - n) * 2; --j)
			{
				printf("*");
			}putchar('\n');

		}
		

	

	return 0;
}



#endif
#ifdef forfor

int main()
{



	int n = 0;
	int i = 0, j = 0;
	int vector = 1;
	int re = 0;
	int starnumber = 1;
	int spacenumber = 0;
	char star[20] = { "*******************" };
	char space[20] = { "                   " };
	char* pspace = space;
	char* pstar = star;
	printf("다이아몬드의 최대길이(홀수)를 입력해주세요.");
	scanf_s("%d", &n);
	char cpystring[20] = { 0 };
	//
	while (n % 2 == 0)
	{
		printf("짝수가 입력되었습니다. 다시 입력해 주세요 : ");
		scanf_s("%d", &n);

	}
	int nn = n / 2;
	spacenumber = n / 2;
	//   i<n-1?-:*;
	for (i = 0; i <= nn; ++i)
	{
		for (j = (n+1)/2; j > 0; --j)
		{
			strcpy_s(cpystring,spacenumber, space);
			printf("%s", cpystring);
			strcpy_s(cpystring,starnumber, space);
			printf("%s\n", cpystring);
			starnumber += 2*vector;
			spacenumber -= vector;

			
						
		}

		//printf("%s\n", &pstar[(19-starnumber)]);
		//starnumber += vector;


		vector = -vector;
		nn = 2 * nn;
		--n;
		//putchar('\n');
	}
	
	return 0;
}
#endif  
