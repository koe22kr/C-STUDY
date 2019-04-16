#include<iostream>
//#define car1

//#define car2
//#define Omokkkk

#ifdef car1
namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP =10,
		BRK_STEP =10

	};


}

struct Car
{
	char gameID[CAR_CONST::ID_LEN];
	int FuelGauge;
	int curSpeed;

	void ShowCarState()
	{
		std::cout << "사용자 ID: " << gameID << std::endl;
		std::cout << "연료량 : " << FuelGauge <<"%"<< std::endl;
		std::cout << "속도  :" << curSpeed <<"km/h"<< std::endl;
		
	}
	void Accel()
	{
		if (FuelGauge <= 0)
		{
			return;
		}
		else
		{
			FuelGauge -= CAR_CONST::FUEL_STEP;
		}
		if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
		{
			curSpeed = CAR_CONST::MAX_SPD;
			return;
		}curSpeed += CAR_CONST::ACC_STEP;
	}
	void Break()
	{
		if (curSpeed < CAR_CONST::BRK_STEP)
		{
			curSpeed = 0;
			return;
		}
		curSpeed -= CAR_CONST::BRK_STEP;


	}
};


void main()
{
	Car APK = { "APK",100,0 };
	APK.Accel();
	APK.Accel();
	APK.ShowCarState();
	APK.Accel();
	APK.ShowCarState();
	
	Car Bread = { "Bread",100,0 };
	Bread.Accel();
	Bread.Break();
	Bread.ShowCarState();
	Bread.Accel();
	Bread.ShowCarState();

}
#endif
#ifdef car2

namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		ACC_STEP = 10,
		BRK_STEP = 10,
		FUEL_STEP = 2
	};
}
	struct Car
	{
		char User_Name[CAR_CONST::ID_LEN];
		int Fuel_Gauge = 100;
		int Cur_Speed = 0;
	
		void Accspd();
		void Brkspd();
		void Showstats();
			
	};

	void Car::Accspd()
	{
		if (Car::Fuel_Gauge <= CAR_CONST::FUEL_STEP)
		{
			return;
		}
		else
		{
			Car::Cur_Speed += CAR_CONST::ACC_STEP;
			Car::Fuel_Gauge -= CAR_CONST::FUEL_STEP;
		}
		if (Car::Cur_Speed > CAR_CONST::MAX_SPD)
		{
			Car::Cur_Speed = CAR_CONST::MAX_SPD;
			return;
		}
	}	
	void Car::Brkspd()
	{
		if (Car::Cur_Speed < CAR_CONST::BRK_STEP)
		{
			Car::Cur_Speed = 0;
		}
		Car::Cur_Speed -= CAR_CONST::BRK_STEP;
	}
	
	void Car::Showstats()
	{
		std::cout << "유저이름 :" << Car::User_Name << std::endl;
		std::cout << "현재속도 :" << Car::Cur_Speed <<"km/h"<< std::endl;
		std::cout << "기름잔양 :" << Car::Fuel_Gauge <<"%"<< std::endl;
	}






void main()
{
	Car aka = { "aka",100,0 };
	aka.Accspd();
	aka.Accspd();
	aka.Accspd();
	aka.Showstats();
	aka.Accspd();
	aka.Accspd();
	aka.Showstats();
	aka.Brkspd();
	aka.Showstats();

}


#endif
#ifdef Omokkk


#include "Omok.h"



// 주의 : 콘솔창(cmd실행창) 속성에서 레거시 콘솔 사용을 체크하고 다시 실행해야함.
///////////////////////////////////////////////////////////////////
// 1 ~ 37 ( 가로 ) 2칸 단위
// 1 ~ 19 ( 세로 ) 1칸 단위
///////////////////////////////////////////////////////////////////
void KeyCheck()
{
	int iPlayTurn = 1;
	while (iPlayTurn)
	{
		switch (_getch())
		{
		case RIGHT:
		{
			g_iCursorX += 2;
			if (g_iCursorX > 38)
			{
				g_iCursorX -= 2;
			}
			GotoXY(g_iCursorX, g_iCursorY);
			break;
		}
		case LEFT:
		{
			g_iCursorX -= 2;
			if (g_iCursorX < 0)
			{
				g_iCursorX += 2;
			}
			GotoXY(g_iCursorX, g_iCursorY);
			break;
		}
		case UP:
		{
			g_iCursorY--;
			if (g_iCursorY <= 0)
			{
				g_iCursorY++;
			}
			GotoXY(g_iCursorX, g_iCursorY);
			break;
		}
		case DOWN:
		{
			g_iCursorY++;
			if (g_iCursorY > 19)
			{
				g_iCursorY--;
			}
			GotoXY(g_iCursorX, g_iCursorY);
			break;
		}
		case ENTER:
		{  // 화면에 출력될때 배열과 위치를 맞추기위해서는  g_iCursorX => g_iCursorX/2 g_iCursorY=> g_iCursorY-1 를 사용함
			if (g_OmokBoard[g_iCursorX / 2][g_iCursorY - 1] != 0)
				break;

			if (!g_bPlayer)
			{
				g_OmokBoard[g_iCursorX / 2][g_iCursorY - 1] = 2;
			}
			else
			{
				g_OmokBoard[g_iCursorX / 2][g_iCursorY - 1] = 1;
			}
			DO(1);
			iPlayTurn = 0;
		}
		}
		GotoXY(2, 21);
		printf("1p=○      2p=● \n현재좌표g_OmokBoard(%d %d)", g_iCursorX / 2, g_iCursorY - 1);
		GotoXY(g_iCursorX, g_iCursorY);
	}
}
///////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////
void GotoXY(int x, int y)
{
	COORD Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
///////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////
void Drawboard()
{
	system("cls");
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					if (g_OmokBoard[j][i] == 1) 			printf("○");
					else if (g_OmokBoard[j][i] == 2)		printf("●");
					else if (g_OmokBoard[j][i] == 0)		printf("┌");
				}
				else if (j == 18)
				{
					if (g_OmokBoard[j][i] == 1)			printf("○");
					else if (g_OmokBoard[j][i] == 2)		printf("●");
					else if (g_OmokBoard[j][i] == 0)		printf("┐");
				}
				else
				{
					if (g_OmokBoard[j][i] == 1)			printf("○");
					else if (g_OmokBoard[j][i] == 2)		printf("●");
					else if (g_OmokBoard[j][i] == 0)		printf("┬");
				}
			}
			else if (i == 18)
			{
				if (j == 0)
				{
					if (g_OmokBoard[j][i] == 1)			printf("○");
					else if (g_OmokBoard[j][i] == 2)		printf("●");
					else if (g_OmokBoard[j][i] == 0)		printf("└");
				}
				else if (j == 18)
				{
					if (g_OmokBoard[j][i] == 1)			printf("○");
					else if (g_OmokBoard[j][i] == 2)		printf("●");
					else if (g_OmokBoard[j][i] == 0)		printf("┘");
				}
				else
				{
					if (g_OmokBoard[j][i] == 1)			printf("○");
					else if (g_OmokBoard[j][i] == 2)		printf("●");
					else if (g_OmokBoard[j][i] == 0)		printf("┴");
				}
			}
			else
			{
				if (j == 0)
				{
					if (g_OmokBoard[j][i] == 1)			printf("○");
					else if (g_OmokBoard[j][i] == 2)		printf("●");
					else if (g_OmokBoard[j][i] == 0)		printf("├");
				}
				else if (j == 18)
				{
					if (g_OmokBoard[j][i] == 1)			printf("○");
					else if (g_OmokBoard[j][i] == 2)		printf("●");
					else if (g_OmokBoard[j][i] == 0)		printf("┤");
				}
				else
				{
					if (g_OmokBoard[j][i] == 1)			printf("○");
					else if (g_OmokBoard[j][i] == 2)		printf("●");
					else if (g_OmokBoard[j][i] == 0)		printf("┼");
				}
			}
		}
		printf("\n");
	}
	GotoXY(2, 20);
	printf("방향키와 엔터키를 이용하여 돌을 놓습니다.");
	GotoXY(2, 21);  //디버깅을 위해 수정
	printf("1p=○      2p=● \n현재좌표g_OmokBoard(%d %d)", g_iCursorX / 2, g_iCursorY - 1);
	GotoXY(g_iCursorX, g_iCursorY);
}
/////////////////////////////////////////////////////////////////////
//// return Value  0 게임종료
////               1 게임진행중
/////////////////////////////////////////////////////////////////////
//void Judgment(){
//	g_iGameLoop = 1;
//	g_bPlayer = !g_bPlayer;
//
//	if (g_iGameLoop == 0)
//	{
//		// 게임 종료
//	}
//	if( g_bRestartGame == true ) // 다른 게임 시작
//	{
//		g_iGameStage = GAME_INIT;		
//	}
//}
void InitOmokBoard()
{
	// 오목판 초기화 ( 행 / 열 )
	for (int iRowBoard = 0; iRowBoard < 19; iRowBoard++)
	{
		for (int iColBoard = 0; iColBoard < 19; iColBoard++)
		{
			g_OmokBoard[iRowBoard][iColBoard] = 0;
		}
	}
	Drawboard();
}
///////////////////////////////////////////////////////////////////
// return Value  0 게임종료
//               1 게임진행중
/////////////////////////////////////////////////////////////////// /// 이부분만 수정
void Judgment()			//
{	
	int iStone = g_bPlayer ? 1 : 2;
	int count  = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (g_OmokBoard[i][j] == iStone)
			{
				int score[4]{ 0 };
				for (int k = 1; k < 5; ++k)
				{
					
					if (g_OmokBoard[i][j + k] == iStone)score[0] += 1;
					if (g_OmokBoard[i+k][j+k]  ==iStone)score[1] += 1;
					if (g_OmokBoard[i+k][j]    ==iStone)score[2] += 1;
					if (g_OmokBoard[i+k][j-k]  ==iStone)score[3] += 1;
				
					if (score[0] == 4 || score[1] == 4 || score[2] == 4 || score[3] == 4)
					{
	
						if (1 == iStone)
							g_iGameLoop = WHITEWIN;
						else if (2 == iStone)
							g_iGameLoop = BLACKWIN;

						return;
					}
				}
			}
		}
		
	}
	
	g_bPlayer = !g_bPlayer;
}// g_bPlayer 0=> 2 흑  1=>1 백
///////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////

void main()
{
	g_iGameStage = GAME_INIT;
	// 게임루프
	while (g_iGameLoop != WHITEWIN && g_iGameLoop != BLACKWIN)                      //종료가 내부의 젓지에서 WIN 뜨면.. 이거 끝나는 위치 물어보자..
	{
		switch (g_iGameStage)
		{
		case GAME_INIT: {
			GAME =
				InitOmokBoard;// 오목판 초기화 ( 행 / 열 )				
			g_iGameStage = KEY_CHECK;// 오목판을 그린다.
			g_bRestartGame = false;
			g_bPlayer = true;
		}break;
		case KEY_CHECK: {
			GAME =
				KeyCheck;
			g_iGameStage = GAME_DRAW;
		}break;
		case GAME_DRAW: {
			GAME =
				Drawboard;
			g_iGameStage = GAME_CHECK;
		}break;
		case GAME_CHECK: {
			GAME =
				Judgment;
			g_iGameStage = KEY_CHECK;
		}break;
		}
		GAME();// 함수포인터 실행			
	}

	system("cls");
	GotoXY(2, 20);
	if (g_iGameLoop == WHITEWIN)
	{
		printf("백이 승리!!.");
	}
	if (g_iGameLoop == BLACKWIN)
	{
		printf("흑이 승리!!.");
	}
	_getch();   //마지막 버퍼 제거? 이거만 물어보자
}
#endif
