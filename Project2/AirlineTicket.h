#pragma once
#include <string>
class AirlineTicket
{
public:
	AirlineTicket();
	AirlineTicket();
	int calculaterPricelnDollars() const;
	const std::string& getPassengerName() const;
	void setPassengerName(const std::string& name);
	int getNumberofMiles() const;
	void setNumberofMiles(int miles);
	bool getHasEliteSuperRewardsStatus() const;
	void setHasEliteSuperRewardsStatus(bool status);
private:
	std::string mPassengerName;
	int mNumberofMiles;
	bool mHasEliteSuperRewardsStatus;
	};