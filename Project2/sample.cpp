#include <string>
#include <iostream>

#include "AirlineTicket.h"
using namespace std;
AirlineTicket::AirlineTicket()
{
	mHasEliteSuperRewardsStatus = false;
	mPassengerName = "Unknown Passenger";
	mNumberofMiles = 0;
}
AirlineTicket::~AirlineTicket()
{
	//��ü �Ҹ� �� Ư���� �ؾ� �� ���� �۾��� ����.
}
int AirlineTicket::calculatePricelnDollars() const    //���� ����
{
	if (getHasEliteSuperRewardsStatus())               //���� ����
	{  //����Ƽ�� = ��¥
		return 0; 
	}
	//Ƽ�� ������ ���Ͽ� 0.1�� ���� ������ ����.
	return static_cast<int>(getNumberofMiles()*0.1); //���� ����
}
const string& AirlineTicket::getPassengerName() const
{
	return mPassengerName;
}
void AirlineTicket::setPassengerName(const string& name)
{
	mPassengerName = name;
	}
//���� get,set �޼���� ����.
auto main()
{
	//���� �޸𸮿� airlineTicket ��ü ����
	AirlineTicket myTicket;   
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberofMiles(700);
	int cost = myTicket.calculaterPricelnDollars();
	cout << "This ticket will cost $" << cost << endl;
	//
	//����Ʈ �����͸� �̿��Ͽ� ���� AirlineTicket ��ü ����
	auto myTicket2 = make_unique<AirlineTicket>();
	myTicket2->setPassengerName("Laudimore M. Hallidue");
	myTicket2->setNumberofMiles(2000);
	myTicket2->setHasEliteSuperRewardsStatus(true);
	int cost2 = myTicket2->calculaterPricelnDollars();
	cout << "This ticket will cost $" << cost << endl;
	// myTicket2�� �ڵ����� �����Ǳ� ������ delete �� �ʿ䰡 ����.

	//����Ʈ ������ ���� ���� AirlineTicket ��ü�� �����ϴ� ��� (������ �ʴ´�.)
	AirlineTicket* myTicket3 = new AirlineTicket();


	delete myTicket3;    //myTicket3 ���� ����. ��������� ���� ������ ��ü�� ����!
	

}