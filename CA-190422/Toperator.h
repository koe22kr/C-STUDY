#pragma once
class Toperator
{
public:
	int x;
	int y;
	void setpoint(int inx, int iny);
	void move(int mx, int my);
	void showpoint();
	Toperator() {};
	~Toperator() {};
	//+-*/ ++
	// ÀÎµ¦½Ì[]
	// -> ,
	// 
	Toperator  operator +(Toperator &x);
	Toperator  operator -(Toperator x);
	Toperator  operator *(Toperator x);
	Toperator  operator /(Toperator x);
	Toperator&  operator ++();
	Toperator&  operator ++(int);
	
	//Toperator operator++(); 
	
	int*  operator [](int i);
	//Toperator  operator -> 
	//


};

