#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };



//entity

class Account
{
private:
	int ID;
	int MONEY;
	char* cusName;

public:
	

	Account(int inid, int inmoney, const char* inname);
	Account(const Account &ref);
	virtual ~Account();
	int GetAccount() const;
	void Deposit(int inmoney);
	void Withdraw(int outmoney);
	void ShowAccountInfo()const;

	int GetMoney();
	virtual void intrateMoney()=0;

};

Account::Account(int inid, int inmoney, const char* inname) : ID(inid), MONEY(inmoney)
{
	cusName = new char[strlen(inname) + 1];
	strcpy(cusName, inname);

}
Account::Account(const Account &ref) : ID(ref.ID), MONEY(ref.MONEY)
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
 void Account::Withdraw(int outmoney)
{

	if (outmoney > MONEY)
	{
		cout << "�ܾ��� �����մϴ�." << endl;
		return ;
	}
	MONEY -= outmoney;
	cout << "��ݼ���" << endl;
	
}

void Account::ShowAccountInfo() const
{
	cout << "���¹�ȣ: " << ID << endl;
	cout << "�̸� : " << cusName << endl;
	cout << "�ܾ� : " << MONEY << endl << endl;
}
int Account::GetMoney()
{
	return MONEY;
}



class NomalAccount : public Account
{
private:
	int intrate = 3;
public:
	NomalAccount(int inid, int inmoney, const char* inname);
	virtual 	~NomalAccount();

	virtual void intrateMoney();

};

NomalAccount::NomalAccount(int inid, int inmoney, const char* inname) : Account(inid,inmoney,inname)
{
}

NomalAccount::~NomalAccount()
{
}

void NomalAccount::intrateMoney()
{
	//int money = GetMoney() * intrate / 100;
	Deposit(GetMoney()*intrate / 100);	
}
class GoldAccount :public Account
{
private:
	int intrate = 9;
	int Membership_Rank = 0;
	int Membership_intrate[4] = { 0,7,4,2 };// 1,2,3 �� ����. 0��... �� �ѱ�� 1~3 �̿ܿ��� �����ϰ� ����� ����
	
	virtual void intrateMoney();


public:
	GoldAccount(int inid, int inmoney, const char* inname,int Membership);
	virtual ~GoldAccount();


};

GoldAccount::GoldAccount (int inid, int inmoney, const char* inname, int Membership) : Account(inid,inmoney,inname)
{
	Membership_Rank = Membership;
}

GoldAccount::~GoldAccount()
{
}

void GoldAccount::intrateMoney()
{
	//int money = GetMoney() * intrate / 100;
	Deposit(GetMoney()*(intrate + Membership_intrate[Membership_Rank]) / 100);
}

////////////////////////////////////////////////////////////

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
	int memrank = 0;
	int Accounttype = 0;
	cout << "[���� ���� ����]" << endl << "1.�Ϲݰ��� 2.������" << endl;
	cin >> Accounttype;
	switch (Accounttype)
	{
	case 1:
		cout << "�Ϲݰ��� ����" << endl;
		cout << "���¹�ȣ :";
		cin >> newid;
		cout << "�ʱ� �Աݾ� :";
		cin >> newmoney;
		cout << "�̸� :";
		cin >> newname;
		accArr[accNum++] = new NomalAccount(newid, newmoney, newname);
		break;
	case 2:
		
		cout << "������ ����" << endl;
		cout << "���¹�ȣ :";
		cin >> newid;
		cout << "�ʱ� �Աݾ� :";
		cin >> newmoney;
		cout << "�̸� :";
		cin >> newname;
		while (memrank != (1 || 2 || 3))
		{
			cout << "�ɹ��� ��ũ�� �Է����ּ���.(A=1,B=2,C=3) :";
			cin >> memrank;
		}		
		accArr[accNum++] = new GoldAccount(newid, newmoney, newname, memrank);
		break;
	default:
		cout << "�߸��� ���ڸ� �Է�." << endl;
		break;
	}
	
	

	
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
			accArr[i]->intrateMoney();
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