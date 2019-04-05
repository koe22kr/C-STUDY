#include <stdio.h>
#include <memory>
#include <string>



int Cctoi(char c)     //'숫자' =>  int 수치
{
	if (c > 47 && c < 58)   //48=>0    57=>9
	{          
		c = c - 48;
	}
	return c;
}

int Cstrlen(char* str)
{
	int i = 0;
	int count = 0;

	for (i = 0; str[i] != '\0'; ++i);
	count = i;
	return count;

}



int Cstrtoi(char* str)
{
	int total=0;
	int size = 0;
	int i, j, k;
	size = Cstrlen(str);
	for (i = 0; i < size; ++i)
	{
		if (str[i] > 47 && str[i] < 58)   //48=>0    57=>9
		{   
			j = (int)str[i]-48;
			int xint = 1;
			for (k = i; (size-k-1) > 0 ; ++k) 
			{

				xint *= 10;
			}
			total += j * xint;     //  for(k = i; size - k > 0; --k)            //(10 ^ (size - (i+1)));   13 2자리 

		}
		
		//presult= (int*)str;    // str의 포인터를 int포인터로 캐스팅 했는데 안되는지 확인하기.
		
	}
	return total;
}

void Cstrcpy(char* string, char* sourse)
{
	int i = 0;
	int sourseSize = Cstrlen(sourse);
	if (Cstrlen(string) >= sourseSize) //포인터로 무작위 크기의 입력 받을때용.
	{
		for (i = 0; i < sourseSize - 1; ++i)
		{
			string[i] = sourse[i];
		}string[i] = 0;
	}
//	else
//		puts("복사할 대상이 더 커서 실패.");
}

int Cstrstr(char* string, char* sourse)
{  
	int j, k;
	int counter = 0;

	int strsize = Cstrlen(string);
	int soursesize = Cstrlen(sourse);
	
		for (j = 0; j < strsize; ++j)
		{
			if (string[j] == sourse[0])
			{
				for (k = 1; k < (soursesize); ++k)
				{
					if (string[j + k] == sourse[k])
					{
						if (soursesize == k + 1)
						{
							counter = j + k;
						}
					}
					else
						break;
					
				}
			}
			
			
		}		
		return counter;

	
}	


void main()			//atoi    strstr   strcat 
{
	int i = 0, j = 0, k = 0;
	int size = 0;
	char astr[10] = { 0 };
	int result = 0;
	//숫자문자열 -> 정수변수
	printf("문자열\"숫자\"->int변수로 변경하기");
	printf("8자 이하의 숫자열을 입력해주세요.");
	scanf_s("%s", astr,sizeof(astr));
	result=Cstrtoi(astr);
	printf("int형 : %d으로 변경완료.",result );
	printf("------------------------------");
	
	char strlist[20] = { 0 };
	char strsourse[20] = { 0 };
	printf("복사할 문자열을 입력 : ");
	scanf_s("%s", strsourse, sizeof(strsourse));
	Cstrcpy(strlist, strsourse);	
	
	printf("------------------------------");
	int index = 0;
	printf("문자열 입력");
	scanf_s("%s", strlist, sizeof(strlist));
	printf("검색할 문자열 입력");
	scanf_s("%s", strsourse, sizeof(strsourse));
	
	index = Cstrstr(strlist, strsourse);
	printf("%d 번째 문자 에서 발견.", index + 1);

	
	
	
	
	
	for (i = 0; i < 124; ++i)
	{
		if ((i + 1) % 10 == 0)putchar('\n');
		printf("%03d  %c |", i, i);
		

	}



}