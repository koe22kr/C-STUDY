#include <cstdio>
#include <conio.h>
#include <stdlib.h>


void DrawHexAscii(char* file)
{

	unsigned char munja[10];
	int i, j, n = 0;
	FILE* fp;
	fopen_s(&fp,file, "w");
	if (fp == NULL)
	{
		puts("파 일 없 음");
		return;
	}

	while (!feof(fp))
	{
		printf("\n%05d : ", ftell(fp));
		for (i = 0; i < 10; i++)
		{
			munja[i] = fgetc(fp);
			printf("%02X", munja[i]);
			if (feof(fp)) break;
		}

		printf("   ");
		for (j = 0; j < i; j++)
		{
			if (munja[j] == '\t' || munja[j] == '\n' || munja[j] == '\r')
			{
				munja[j] = '.';

			}
			putchar(munja[j]);

		}
		n++;
		if (n % 20 == 0)
		{
			puts("\n<plz any key"), _getch();

		}
	}
}
void Drawinverse(char* file)
{
	FILE *fp;
	fopen_s(&fp, file, "rb");
	if (fp == NULL)
	{
		puts("no file");
		return;
	}
	fseek(fp, 0, SEEK_END);
	int iSize = ftell(fp);
	printf("%d,%s\n", iSize, "바이트 입니다");
	fseek(fp, 0, SEEK_SET);

	int n = 0;
	do {
		char * munja = 0;
		munja = (char*)calloc(256, sizeof(char));

		int i, j;

		for (i = 0; i < 256; i++)
		{
			if (!feof(fp))
			{
				munja[i] = fgetc(fp);
			}
			else
			{
				free(munja);
				return;
			}



			if (munja[i] == '\n' || ftell(fp) <= 0)
			{
				break;
			}
		}
		for (j = i; j > 0; j--)
		{
			putchar(munja[j]);
		}
		n++;
		free(munja);
		if (n % 20 == 0)
		{
			puts("\n PLZ input any key\n"),
				_getch;

		}
	} while (!feof(fp));
}



void main (int argc, char* argv[] )
{
	if (argc != 3)
	{
		printf("\n 사용법 : fileof.exe filepath 0(inverse) or 1(Hex) \n");
		return;
	}
	int iValue = atoi(argv[2]);
	if (iValue == 1)
	{
		DrawHexAscii(argv[1]);
	}
	else
	{
		Drawinverse(argv[1]);
	}
}