#pragma once
#include <iostream>
#include <vector>
#include "Employee.h"

namespace Records {
	const int kFirstEmployeeNumber = 1000;


	class Database
	{
	public:
		Database();
		Employee& addEmployee(const std::string& firstname,
							  const std::string& lastname);
		Employee& getEmployee(const int employeenumber);                 // ���⵵ const�� �Լ� ���ȭ �ϴ°� ���� ������?
		Employee& getEmployee(const std::string& firstname,				// ���⵵ ���ϻ���
							  const std::string& lastname);
		
		void displayAll() const;
		void displayCurrent() const;
		void displayFormer() const;

	private:
		std::vector<Employee> mEmployees;
		int mNextEmployeeNumber;

	
	};


}