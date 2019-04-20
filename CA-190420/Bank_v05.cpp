#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

const int NAME_LEN = 20;

enum{MAKE=1,DEPOSIT,WITHDRAW,INQUIRE,EXIT};



//entity

class Account
{
private:
	int ID;
	int MONEY;
	char* cusName;

public:
	

	Account(int inid,int inmoney,const char* inname);
	Account(const Account &ref);
	~Account();
	int GetAccount() const;
	void Deposit(int inmoney);
	int Withdraw(int outmoney);
	void ShowAccountInfo()const;

};

Account::Account(int inid, int inmoney, const char* inname) : ID(inid),MONEY(inmoney)
{
	cusName = new char[strlen(inname) + 1];
	strcpy(cusName, inname);
	
}
Account::Account(const Account &ref) : ID(ref.ID),MONEY(ref.MONEY)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}
Account::~Account()
{
	delete cusName;
}
int Account::GetAccount() const
{
	return ID;
}

void Account::Deposit(int inmoney)
{
	
	MONEY += inmoney;
	cout << "입금성공" << endl;
}
int Account::Withdraw(int outmoney)
{
	if (outmoney > MONEY)
	{
		cout << "잔액이 부족합니다." << endl;
		return 0;
	}
	MONEY -= outmoney;
	cout << "출금성공" << endl;
	return 1;
}

void Account::ShowAccountInfo() const
{
	cout << "계좌번호: " << ID << endl;
	cout << "이름 : " << cusName << endl;
	cout << "잔액 : " << MONEY << endl<<endl;
}


class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;

public:
	AccountHandler();
	~AccountHandler();

	void ShowMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo()const;


};

AccountHandler::AccountHandler()
{
	accNum = 0;
}
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
}

void AccountHandler::ShowMenu() const
{
	cout << "------Menu------" << endl;
	cout << "1.계과개설" << endl;
	cout << "2.입금" << endl;
	cout << "3.출금" << endl;
	cout << "4.계좌정보 전체 출력" << endl;
	cout << "5.프로그램 종료" << endl;
}
void AccountHandler::MakeAccount()
{
	int newid;
	int newmoney;
	char newname[20];
	cout << "계좌번호 :";
	cin >> newid;
	cout << "초기 입금액 :";
	cin >> newmoney;
	cout << "이름 :";
	cin >> newname;

	accArr[accNum++] = new Account(newid, newmoney, newname);
}
void AccountHandler::DepositMoney()
{
	int inmoney;
	int inid;
	cout << "입금할 계좌번호 : ";
	cin >> inid;
	cout << "입금할 금액 :";
	cin >> inmoney;
		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->GetAccount() == inid)
			{
				accArr[i]->Deposit(inmoney);
				return;
			}
		}		
		cout << "해당 계좌를 찾지 못하였습니다." << endl;
}

void AccountHandler::WithdrawMoney()
{
	int outmoney;
	int outid;
	cout << "출금할 계좌번호 : ";
	cin >> outid;
	cout << "출금할 금액 :";
	cin >> outmoney;
		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->GetAccount() == outid)
			{
				accArr[i]->Withdraw(outmoney);
				return;
			}
		}
		cout << "해당 계좌를 찾지 못하였습니다." << endl;
}

void AccountHandler::ShowAllAccInfo() const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccountInfo();
	}
}

int main()
{
	AccountHandler Mgr;
	int choice;
	while (true)
	{
		Mgr.ShowMenu();
		cout << "선택 : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			Mgr.MakeAccount();
			break;
		case DEPOSIT:
			Mgr.DepositMoney();
			break;
		case WITHDRAW:
			Mgr.WithdrawMoney();
			break;
		case INQUIRE:
			Mgr.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "잘못된 숫자를 입력." << endl;
		}


	}
	return 0;
}