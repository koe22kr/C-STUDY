#include <iostream>
#include "Employee.h"
using namespace std;


namespace Records {
	Employee::Employee()                //Ŭ���� ������ <-  ��  ������ : �ɹ�, �ɹ�,�ɹ�{ ~~~~~}  �������� �ʱ�ȭ
		: mFirstName("")                     ////
		, mLastName("")						   //
		, mEmployeeNumber(-1)				   //
		, mSalary(kDefaultStartingSalary)	   //�Լ��� �ʱⰪ ���� ���Ŀ� �°� �Ķ���͸� �Է�
		, mHired(false)						   //
	{										//���⼭ ���� �ݾƼ� �����°� ���� �� ���� ������ ���� �ٷδ���.

	}							//Ŭ���� �����ڴ� ������ �ɹ��� �ʱ갪�� �����Ѵ�.

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

	
	void Employee::display() const												//�Լ� ���ο��� ���� ���� �ȵǰ� �Լ� ���ȭ? ���ο��� ��ġ ���� �Ұ� (const �ڿ� �޸� �Լ����� ���Կ��� ������ �Ұ���)
	{
		cout << "Employee:" << getLastName() << "," << getFirstName() << endl;
		cout << "-----------------------" << endl;
		cout << (mHired ? "Current Employee" : "Former Employee") << endl;
		cout << "Employee Number: " << getEmployeeNumber() << endl;
		cout << "Salary:$" << getSalary() << endl;
		cout << endl;

	}

	//���� ����
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
	//�����Ȱ͵� ������.
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

	//void Employee::promote(int pros)    //������µ� �´��� �𸣰� ���� �׽�Ʈ �غ���.
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
