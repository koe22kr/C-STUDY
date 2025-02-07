#include <iostream>
#include ""
using namespace std;


namespace Records {
	Employee::Employee()
		:mFirstName("")
		, mLastName("")
		, mEmployeeNumber(-1)
		, mSalary(kDefaultStartingSalary)
		, mHired(false)
	{

	}

	void Employee::promote(int raiseAmount)
	{
		setSalary(getSalary() + raiseAmount);
	}
	void Employee::demote(int demeritAmount)
	{
		setSalary(getSalary() - demeritAmount);
	}

	void Employee::hire()
	{
		mHired = true;
	}

	void Employee::fire()
	{
		mHired = false;
	}


	void Employee::display() const
	{
		cout << "Employee:" << getLastName() << "," << getFirstName() << endl;
		cout << "-----------------------" << endl;
		cout << (mHired ? "Current Employee" : "Former Employee") << endl;
		cout << "Employee Number: " << getEmployeeNumber() << endl;
		cout << "Salary:$" << getSalary() << endl;
		cout << endl;

	}

	//게터 세터
	void Employee::setFirstName(const string& firstName)
	{
		mFirstName = firstName;
	}
	const string& Employee::getFirstName() const
	{
		return mFirstName;
	}
	
	void Employee::setLastName(const string& lastName)
	{
		mLastName = lastName;
	}
	const string& Employee::getLastName() const
	{
		return mLastName;
	}
	//const std::string& getLastName()
	//생략된것들 만들어보기.
	void Employee::setEmployeeNumber(const int EmployeeNumber)
	{
		mEmployeeNumber = EmployeeNumber;
	}
	int Employee::getEmployeeNumber() const
	{
		return mEmployeeNumber;
	}

	void Employee::setSalary(int newSalary)
	{
		mSalary = newSalary;
	}
	int Employee::getSalary() const
	{
		return mSalary;
	}

	bool Employee::getIsHired() const
	{
		return mHired;
	}
	
}
