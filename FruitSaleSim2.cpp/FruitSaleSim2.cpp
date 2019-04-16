#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int NUM_OF_APPLE;
	int MONEY;
public:
	FruitSeller(int number_apple=20, int price_apple=1000, int money=5000)
	{
		
		NUM_OF_APPLE = number_apple;
		APPLE_PRICE = price_apple;
		MONEY = money;
	}

	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		NUM_OF_APPLE -= num;
		MONEY += num * APPLE_PRICE;
		return num;
	}
	int get_Apple_Price() const
	{
		return APPLE_PRICE;
	}
	void ShowSalesResult() const
	{
		cout << "남은사과 : " << NUM_OF_APPLE << "개" << endl;
		cout << "잔액 : " << MONEY << "원" << endl;
	}
};

class FruitBuyer
{
private:
	int MONEY;
	int NUM_OF_APPLE;
public:
	FruitBuyer(int money=5000, int number_apple=0)
	{
		MONEY = money;
		NUM_OF_APPLE = number_apple;
	}
	int BuyApples(FruitSeller &seller,int money)
	{
		int num = seller.SaleApples(money);
		MONEY -= num*(seller.get_Apple_Price());
		NUM_OF_APPLE += num;
		return num;
	}
	void ShowBuyerResult() const
	{
		cout << "가진사과 " << NUM_OF_APPLE << "개" << endl;
		cout << "잔액 : " << MONEY;
	}


};


int main()
{
	FruitSeller Seller;
	FruitBuyer Buyer;
	   	 

	Buyer.BuyApples(Seller, 3333);
	Seller.ShowSalesResult();
	Buyer.ShowBuyerResult();

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           	return 0;
}