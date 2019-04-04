#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;
namespace Records {
	
	Database::Database() : mNextEmployeeNumber(kFirstEmployeeNumber)
	{
	}
	//생성자 초기값 선언 끝

	Employee& Database::addEmployee(const string& firstname, const string& lastname) 
	{
		Employee theEmployee;           // theEmployee 생성
		theEmployee.setFirstName(firstname);
		theEmployee.setLastName(lastname);
		theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
		theEmployee.hire();
		mEmployees.push_back(theEmployee);
		return mEmployees[mEmployees.size() - 1];


	}

	Employee& Database::getEmployee(int employeeNumber)
	{
		for (auto& employee : mEmployees) {
			if (employee.getEmployeeNumber() == employeeNumber) {
				return employee;
			}
		}
		throw runtime_error("No employee found.");
	}
	//이름둘 입력받는 메소드는 자작
	Employee& Database::getEmployee(const std::string& firstname, const std::string& lastname) {
		for (auto& employee : mEmployees) {
			if (employee.getFirstName() == firstname && employee.getLastName() == lastname)
				return employee;
		}
		throw runtime_error("No Name Matchesssssssssss");
	}

	void Database::displayAll() const
	{
		for (const auto& employee : mEmployees) {
			employee.display();
		}

	}

	void Database::displayCurrent() const
	{
		for (const auto& employee : mEmployees) {
			if (employee.getIsHired())
				employee.display();

		}
	}
	//자작2
	void Database::displayFormer() const
	{
		for (const auto& employee : mEmployees) {
			if (employee.getIsHired() == false)       //
				employee.display();
		}
	}
	
}
