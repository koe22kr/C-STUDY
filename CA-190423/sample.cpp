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
	cout << "첫번째  입력: ";
	cin >> a;					// >> 연산자 호출
	cout << "두번째  입력: ";
	cin >> b;					// >> 연산자 호출

	cout << a + b << endl;
	cout << "-a =" << -a << endl;
	cout << "~a = " << ~a << endl;
	Tpoint* d = new Tpoint(10,20);
	cout << *d;

		return;

}