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
	//객체 소멸 시 특별히 해야 할 정리 작업은 없음.
}
int AirlineTicket::calculatePricelnDollars() const    //정의 생략
{
	if (getHasEliteSuperRewardsStatus())               //정의 생략
	{  //보상티켓 = 공짜
		return 0; 
	}
	//티켓 가격은 마일에 0.1을 곱한 값으로 가정.
	return static_cast<int>(getNumberofMiles()*0.1); //정의 생략
}
const string& AirlineTicket::getPassengerName() const
{
	return mPassengerName;
}
void AirlineTicket::setPassengerName(const string& name)
{
	mPassengerName = name;
	}
//이하 get,set 메서드는 생략.
auto main()
{
	//스택 메모리에 airlineTicket 객체 생성
	AirlineTicket myTicket;   
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberofMiles(700);
	int cost = myTicket.calculaterPricelnDollars();
	cout << "This ticket will cost $" << cost << endl;
	//
	//스마트 포인터를 이용하여 힙에 AirlineTicket 객체 생성
	auto myTicket2 = make_unique<AirlineTicket>();
	myTicket2->setPassengerName("Laudimore M. Hallidue");
	myTicket2->setNumberofMiles(2000);
	myTicket2->setHasEliteSuperRewardsStatus(true);
	int cost2 = myTicket2->calculaterPricelnDollars();
	cout << "This ticket will cost $" << cost << endl;
	// myTicket2는 자동으로 삭제되기 때문에 delete 할 필요가 없다.

	//스마트 포인터 없이 힙에 AirlineTicket 객체를 생성하는 경우 (권하지 않는다.)
	AirlineTicket* myTicket3 = new AirlineTicket();


	delete myTicket3;    //myTicket3 동적 해제. 명시적으로 힙에 생성된 객체를 삭제!
	

}