#include <iostream>
#pragma once


using namespace std;

	class Tpoint
	{
	public:
		Tpoint() {};
		Tpoint(int ix, int iy) :x(ix),y(iy)
		{
		}
		~Tpoint();
		int x;
		int y;
		Tpoint operator+(Tpoint tp);
		friend ostream &operator<<(ostream& os, const Tpoint& pt);
		friend istream &operator>>(istream& in, Tpoint& pt);
		Tpoint operator~();
		Tpoint operator-()const;
	};
