#include "Tpoint.h"
	
class point
{
public:
	point();
	~point();

	

private:

};

point::point()
{
}

point::~point()
{
}
//friend ostream &operator<<(ostream& os, const TPoint& pt);
//friend istream &operator>>(istream& in, TPoint& pt);
//TPoint operator~();
//TPoint TPoint::operator-()const;


void main()
{
	Tpoint a, b, c;
	cout << "ù��°  �Է�: ";
	cin >> a;					// >> ������ ȣ��
	cout << "�ι�°  �Է�: ";
	cin >> b;					// >> ������ ȣ��

	cout << a + b << endl;
	cout << "-a =" << -a << endl;
	cout << "~a = " << ~a << endl;
	Tpoint* d = new Tpoint(10,20);
	cout << *d;

		return;

}