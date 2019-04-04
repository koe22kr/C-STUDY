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
		Employee& getEmployee(const int employeenumber);                 // 여기도 const로 함수 상수화 하는게 좋지 않을까?
		Employee& getEmployee(const std::string& firstname,				// 여기도 이하생략
							  const std::string& lastname);
		
		void displayAll() const;
		void displayCurrent() const;
		void displayFormer() const;

	private:
		std::vector<Employee> mEmployees;
		int mNextEmployeeNumber;

	
	};


}