#include "Tpoint.h"



Tpoint::~Tpoint()
{
}

Tpoint Tpoint::operator+(Tpoint tp)
{
	return Tpoint(x + tp.x, y + tp.y);
}

ostream &operator<<(ostream& os, const Tpoint &pt)
{
	cout << "[ " << pt.x << " , " << pt.y << " ]" << endl;
	return os;
}
istream &operator>>(istream& in, Tpoint& pt)
{
	cin >> pt.x >> pt.y;

	return in;
}


Tpoint Tpoint::operator~()
{
	return Tpoint(~x, ~y);
}

Tpoint Tpoint::operator-()const
{
	return Tpoint(-x, -y);
}
