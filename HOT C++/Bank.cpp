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
//       //만들기 입금    출금      조회   끝

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
		cout << "입금완료" << endl;
	}
	void withdraw(int outmoney)
	{
		if (outmoney > money)
		{
			cout << "잔액부족" << endl;
		}
		money -= outmoney;
		cout << "출금완료" << endl;
	}
	void showaccinfo()
	{
		cout << "id : " << id << endl;
		cout << "이름 : " << name << endl;
		cout << "잔액 : " << money << endl;
		
	}

};

	
	





void main()
{
	int choice;
	while (1)
	{
		ShowMenu();
		std::cout << "명령어 :";
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
			std::cout << "입력 에러 - 1~5의 수를 입력해 주세요." << std::endl;

		}


	}
	std::cout << "종료" << std::endl;


}

void ShowMenu()
{
	std::cout << "|1 : 계좌생성	| 2 : 입금	| 3 : 출금	| 4 : 잔액조회	| 5 : EXIT	|" << std::endl;
	
}

void MakeAccount() 
{
	int id, money;
	char name[name_len];
	std::cout << "계좌번호 :";
	std::cin >> id;
	
	
	std::cout << "이름 : ";
	std::cin >> name;
	
	
	std::cout << "입금액 : ";
	std::cin >> money;
	std::cout << std::endl;

	accountarr[accountnumber] = { id,money,};
	strcpy_s(accountarr[accountnumber].name,name_len,name);
	accountnumber++;
		
}
void DepositMoney()
{
	int id, money;
	std::cout << "[입 금]" << std::endl;
	std::cout << "계좌번호 : ";
	std::cin >> id;
	std::cout << "입금액 : ";
	std::cin >> money;
	for (int i = 0; i <= accountnumber; ++i)
	{
		if (accountnumber == i)
		{
			std::cout << "해당 계좌번호를 찾지 못하였습니다." << std::endl;
		}
		else if (accountarr[i].bankid == id)
		{
			accountarr[i].money += money;
			std::cout << "입금완료" << std::endl;
			break;
		}



	}
}
void WithdrawMoney()
{
	int id, money;
	std::cout << "[출 금]" << std::endl;
	std::cout << "계좌번호 : ";
	std::cin >> id;
	std::cout << "출금액 : ";
	std::cin >> money;
	for (int i = 0; i <= accountnumber; ++i) 
	{
		if (i==accountnumber) 
		{
			std::cout << "해당 계좌번호를 찾지 못하였습니다." << std::endl;
		}
		else if (accountarr[i].bankid == id)
		{
			if (accountarr[i].money >= money)
			{
				accountarr[i].money -= money;  
				std::cout << "출금 되었습니다." << std::endl;
				break;
			}
			else
			{
				std::cout << "잔액부족" << std::endl;
				break;
			}
		}
		
	}
}
void ShowAllAccInfo()
{
	for (int i = 0; i < accountnumber; ++i)
	{	
		std::cout << "[조회]" << std::endl;
		std::cout << "계좌번호 : " << accountarr[i].bankid << std::endl;
		std::cout << "이름     : " << accountarr[i].name << std::endl;
		std::cout << "잔액	   : " << accountarr[i].money << std::endl;
	}
}
