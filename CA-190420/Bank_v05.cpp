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
	cout << "�Աݼ���" << endl;
}
int Account::Withdraw(int outmoney)
{
	if (outmoney > MONEY)
	{
		cout << "�ܾ��� �����մϴ�." << endl;
		return 0;
	}
	MONEY -= outmoney;
	cout << "��ݼ���" << endl;
	return 1;
}

void Account::ShowAccountInfo() const
{
	cout << "���¹�ȣ: " << ID << endl;
	cout << "�̸� : " << cusName << endl;
	cout << "�ܾ� : " << MONEY << endl<<endl;
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
	cout << "1.�������" << endl;
	cout << "2.�Ա�" << endl;
	cout << "3.���" << endl;
	cout << "4.�������� ��ü ���" << endl;
	cout << "5.���α׷� ����" << endl;
}
void AccountHandler::MakeAccount()
{
	int newid;
	int newmoney;
	char newname[20];
	cout << "���¹�ȣ :";
	cin >> newid;
	cout << "�ʱ� �Աݾ� :";
	cin >> newmoney;
	cout << "�̸� :";
	cin >> newname;

	accArr[accNum++] = new Account(newid, newmoney, newname);
}
void AccountHandler::DepositMoney()
{
	int inmoney;
	int inid;
	cout << "�Ա��� ���¹�ȣ : ";
	cin >> inid;
	cout << "�Ա��� �ݾ� :";
	cin >> inmoney;
		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->GetAccount() == inid)
			{
				accArr[i]->Deposit(inmoney);
				return;
			}
		}		
		cout << "�ش� ���¸� ã�� ���Ͽ����ϴ�." << endl;
}

void AccountHandler::WithdrawMoney()
{
	int outmoney;
	int outid;
	cout << "����� ���¹�ȣ : ";
	cin >> outid;
	cout << "����� �ݾ� :";
	cin >> outmoney;
		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->GetAccount() == outid)
			{
				accArr[i]->Withdraw(outmoney);
				return;
			}
		}
		cout << "�ش� ���¸� ã�� ���Ͽ����ϴ�." << endl;
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
		cout << "���� : ";
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
			cout << "�߸��� ���ڸ� �Է�." << endl;
		}


	}
	return 0;
}