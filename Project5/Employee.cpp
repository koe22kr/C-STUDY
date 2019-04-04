#include <iostream>
#include "Employee.h"
using namespace std;


namespace Records {
	Employee::Employee()                //클래스 생성자 <-  가  생성자 : 맴버, 맴버,맴버{ ~~~~~}  형식으로 초기화
		: mFirstName("")                     ////
		, mLastName("")						   //
		, mEmployeeNumber(-1)				   //
		, mSalary(kDefaultStartingSalary)	   //함수값 초기값 설정 형식에 맞게 파라미터만 입력
		, mHired(false)						   //
	{										//여기서 열고 닫아서 끝내는것 따로 할 연산 없으니 열고 바로닫음.

	}							//클래스 생성자는 데이터 맴버의 초깃값을 설정한다.

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

	
	void Employee::display() const												//함수 내부에서 대입 수정 안되게 함수 상수화? 내부에서 수치 변경 불가 (const 뒤에 달린 함수에선 대입연산 같은것 불가능)
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

	//void Employee::promote(int pros)    //만들었는데 맞는지 모르겟 내일 테스트 해보자.
	//{
	//	mSalary += 1000 * pros;
	//}
	//void Employee::demote(int dems)
	//{
	//	mSalary -= 1000 * dems;
	//}

	bool Employee::getIsHired() const
	{
		return mHired;
	}

}
int raiseAmount
