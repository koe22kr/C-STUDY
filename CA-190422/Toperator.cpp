#include <iostream>
#include "Toperator.h"
using namespace std;

//
//void setpoint(int inx, int iny);
//void move(int mx, int my);
//void showpoint();


void Toperator::setpoint(int inx, int iny)
{
	x = inx;
	y = iny;

}

void Toperator::move(int mx, int my)
{
	x += mx;
	y += my;
}

void Toperator::showpoint()
{
	cout << "[" << x << " , " << y << "]" << endl;

}

Toperator Toperator::operator+(Toperator &x)
{
	Toperator result;
	result.x= this->x + x.x;
	result.y = this->y + x.y;
	return result;
}


Toperator  Toperator::operator -(Toperator x)
{
	Toperator result;
	result.x = this->x - x.x;
	result.y = this->y - x.y;
	return result;
}

Toperator  Toperator::operator *(Toperator x)
{
	Toperator result;
	result.x = this->x * x.x;
	result.y = this->y * x.y;
	return result;

}

Toperator  Toperator::operator /(Toperator x)
{
	Toperator result;
	result.x = this->x / x.x;
	result.y = this->y / x.y;
	return result;

}
//Toperator Toperator::operator++()    //��ȯ������ ����� �� ������ this �� �ӽú��� return�� ���� �ؼ� ������ �� �� �ִ�. ������or���� �޾ƾ� ����.
//{									   //
//	this->x += 1;					   //
//	this->y += 1;					   //
//	return *this;					   ////////////////////////////////////////////////////
//}									   ////////////////////////////////////////////////////
Toperator&  Toperator::operator ++()
{//++a
	this->x++;
	this->y++;
	return *this;
}

Toperator&  Toperator::operator ++(int)
{//a++
	Toperator temp;
	temp.x = this->x++;
	temp.y = this->y++;
	return temp;
}


int*  Toperator::operator [](int i)
{
	//Toperator->x   == Toperator[0];
	//Toperator->y   == Toperator[1];
	int* list[2];
	list[0] = &this->x;
	list[1] = &this->y;
	return list[i];
}




void main()
{
	Toperator test;
	test.setpoint(10, 20);
	test.move(5, 5);
	test.showpoint();

	Toperator test2;
	test2.setpoint(10, 10);
	
	test = test + test2;
	test.showpoint();
	test = test - test2;
	test.showpoint();
	test = test * test2;
	test.showpoint();
	test = test / test2;
	test.showpoint();
	//test++;
	test.showpoint();
	++(++test);
	test.showpoint();

	
	return;


}