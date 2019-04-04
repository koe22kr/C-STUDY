#include<iostream>
#include<stdexcept>
#include<exception>
#include"Database.h"
using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);


void main()
{
	Database employeeDB;
	bool done = false;
	while (!done) 
	{
		int selection = displayMenu();
		switch (selection) {

		case 1:
			doHire(employeeDB);
				break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			employeeDB.displayAll();
			break;
		case 5:
			employeeDB.displayCurrent();
			break;
		case 6:
			employeeDB.displayFormer();
			break;
		case 0:
			done = true;
			break;
		
		default:
			std::cerr << "Unknown command." << std::endl;
			break;
		}
	}
	

}
int displayMenu()
{
	int selection;
	std::cout << std::endl;
	std::cout << "Employee Database" << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "1) Hire a new employee" << std::endl;
	std::cout << "2)Fire an employee" << std::endl;
	std::cout << "3)Promote a employee" << std::endl;
	std::cout << "4)List all employee" << std::endl;
	std::cout << "5)List all current employee" << std::endl;
	std::cout << "6)List all former employee" << std::endl;
	std::cout << "0)Quit" << std::endl;
	std::cout << std::endl;
	std::cout << "--->";
	std::cin >> selection;
	return selection;
}

void doHire(Database& DB)
{
	std::string firstName;
	std::string lastName;
	std::cout << "First name? :";
	std::cin >> firstName;
	std::cout << "Last name? :";
	std::cin >> lastName;
	try
	{
		DB.addEmployee(firstName, lastName);
	}
	catch (const std::exception& exception)
	{
		std::cerr << "Unable to add new employee:" << exception.what() << std::endl;
	}
}
void doFire(Database& DB)
{
	int employeeNumber;
	std::cout << "Employee number?";
	std::cin >> employeeNumber;
	try {
		Employee& emp = DB.getEmployee(employeeNumber);
		emp.fire();
		std::cout << "Employee " << employeeNumber << "terminated." << std::endl;
		}
	catch (const std::exception& exception)
	{
		std::cerr << "Unable to promote employee: " << exception.what() << std::endl;

	}

}

void doPromote(Database& DB)
{
	int employeeNumber;
	int raiseAmount;
	std::cout << "Employee number?";
	std::cin >> employeeNumber;
	std::cout << "How much of a raise?";
	std::cin >> raiseAmount;
	try
	{
		Employee& emp = DB.getEmployee(employeeNumber);
		emp.promote(raiseAmount);

	}
	catch (const std::exception& exception)
	{
		std::cerr << "Unable to promote employee:" << exception.what() << std::endl;
	}
}
