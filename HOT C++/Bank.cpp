#include <iostream>
#include <cstring>
#include <string>
using namespace std;





//const size_t name_len = 20;
//
//void ShowMenu();
//void MakeAccount();
//void DepositMoney();
//void WithdrawMoney();
//void ShowAllAccInfo();
//
//enum { MAKE = 1,DEPOSIT,WITHDRAW,INQUIRE,EXIT };
//       //����� �Ա�    ���      ��ȸ   ��

//typedef struct
//{
//	
//	int bankid;
//	int money;
//	char name[name_len];
//	
//}Account;
class thif
{
private:
	int level;
	int works;
	int money;
public:
	thif();
	~thif();
	thif& working()
	{
		money += level * 10;
		return *this;
	}


};

thif::thif()
{
}

thif::~thif()
{
}


class Account
{
private:
	int money;
	int id;
	char* name;
	friend class thif;
public:
	Account(char inid, char* inname, int inmoney)
		:id(inid), money(inmoney)
	{
		name = new char[strlen(inname) + 1];
		strcpy(name, inname);
	}
	Account(const Account &ref)
		:id(ref.id), money(ref.money)
	{
		name = new char[strlen(ref.name) + 1];
		strcpy(name, ref.name);
	}
	~Account()
	{
		delete name;
	}
	int getid()
	{
		return id;
	}
	int getmoney()
	{
		return money;
	}
	char* getname()
	{
		return name;
	}
	void deposite(int inmoney)
	{
		money += inmoney;
		cout << "�ԱݿϷ�" << endl;
	}
	void withdraw(int outmoney)
	{
		if (outmoney > money)
		{
			cout << "�ܾ׺���" << endl;
		}
		money -= outmoney;
		cout << "��ݿϷ�" << endl;
	}
	void showaccinfo()
	{
		cout << "id : " << id << endl;
		cout << "�̸� : " << name << endl;
		cout << "�ܾ� : " << money << endl;
		
	}

};

	
	





void main()
{
	int choice;
	while (1)
	{
		ShowMenu();
		std::cout << "��ɾ� :";
		std::cin >> choice;
		

		switch (choice)
		{

		case 1:
			MakeAccount();
			break;
		case 2:
			DepositMoney();
			break;
		case 3:
			WithdrawMoney();
			break;
		case 4:
			ShowAllAccInfo();
			break;
		case 5:
			return ;
		default:
			std::cout << "�Է� ���� - 1~5�� ���� �Է��� �ּ���." << std::endl;

		}


	}
	std::cout << "����" << std::endl;


}

void ShowMenu()
{
	std::cout << "|1 : ���»���	| 2 : �Ա�	| 3 : ���	| 4 : �ܾ���ȸ	| 5 : EXIT	|" << std::endl;
	
}

void MakeAccount() 
{
	int id, money;
	char name[name_len];
	std::cout << "���¹�ȣ :";
	std::cin >> id;
	
	
	std::cout << "�̸� : ";
	std::cin >> name;
	
	
	std::cout << "�Աݾ� : ";
	std::cin >> money;
	std::cout << std::endl;

	accountarr[accountnumber] = { id,money,};
	strcpy_s(accountarr[accountnumber].name,name_len,name);
	accountnumber++;
		
}
void DepositMoney()
{
	int id, money;
	std::cout << "[�� ��]" << std::endl;
	std::cout << "���¹�ȣ : ";
	std::cin >> id;
	std::cout << "�Աݾ� : ";
	std::cin >> money;
	for (int i = 0; i <= accountnumber; ++i)
	{
		if (accountnumber == i)
		{
			std::cout << "�ش� ���¹�ȣ�� ã�� ���Ͽ����ϴ�." << std::endl;
		}
		else if (accountarr[i].bankid == id)
		{
			accountarr[i].money += money;
			std::cout << "�ԱݿϷ�" << std::endl;
			break;
		}



	}
}
void WithdrawMoney()
{
	int id, money;
	std::cout << "[�� ��]" << std::endl;
	std::cout << "���¹�ȣ : ";
	std::cin >> id;
	std::cout << "��ݾ� : ";
	std::cin >> money;
	for (int i = 0; i <= accountnumber; ++i) 
	{
		if (i==accountnumber) 
		{
			std::cout << "�ش� ���¹�ȣ�� ã�� ���Ͽ����ϴ�." << std::endl;
		}
		else if (accountarr[i].bankid == id)
		{
			if (accountarr[i].money >= money)
			{
				accountarr[i].money -= money;  
				std::cout << "��� �Ǿ����ϴ�." << std::endl;
				break;
			}
			else
			{
				std::cout << "�ܾ׺���" << std::endl;
				break;
			}
		}
		
	}
}
void ShowAllAccInfo()
{
	for (int i = 0; i < accountnumber; ++i)
	{	
		std::cout << "[��ȸ]" << std::endl;
		std::cout << "���¹�ȣ : " << accountarr[i].bankid << std::endl;
		std::cout << "�̸�     : " << accountarr[i].name << std::endl;
		std::cout << "�ܾ�	   : " << accountarr[i].money << std::endl;
	}
}
