#include <iostream>
#include<string>


//하노이 타워

	int n, i;
	
	

void swap(int n, char A, char B, char C)
{
	

	if (n == 1)                                                                                    //n=3 일시 경우의수 [위x 아래y ] xx x xy 0 yx y yy   총 7개[2^3-1]
	{																							   //
					printf("[%d] %c => %c ABC =%c%c%c\n", n, A, C,		A,B,C);                    //그렇게 보고 하면 생각하기 편함.
																								   //					xx		1
	}																							   //				x			2
	else if (n > 1)																				   //					xy		3
	{																							   //			0				4
		swap(n - 1, A,C,B);     																   //					yx		5
		printf("[%d] %c => %c ABC= %c%c%c\n",n, A, C,					A,B,C );				   //				y			6
		swap(n - 1, B,A,C);																		   //					yy		7 <-
		
	}
	//else if (n % 2 == 1);

}



void main()
{
	char A='A', B='B', C='C';

	swap(5, A, B, C);
}






int Factorial(int iValue)
{
	if (iValue == 1)
	{
		return 1;
	}
	int iRet = Factorial(iValue - 1);
	return iValue * iRet;
	

}