#include <iostream>
using namespace std;
#ifdef on

class Rectangle
{
private:

	int x;
	int y;

public:
	Rectangle(int inx, int iny);
	~Rectangle();
	void ShowAreaInfo();
};

Rectangle::Rectangle(int inx, int iny) : x(inx), y(iny)
{
}

Rectangle::~Rectangle()
{
}
void Rectangle::ShowAreaInfo()
{
	cout << "¸éÀû: " << x * y << endl;
}


class Square : public Rectangle
{
private:



public:
	Square(int inx);
	//Square(int inx, int iny);
	~Square();


};
//Square::Square(int inx, int iny) :Rectangle::Rectangle(inx,iny)
//{
//	
//}
Square::Square(int inx) : Rectangle::Rectangle(inx,inx)
{
	
}

Square::~Square()
{
}


int main(void)
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}


#endif // DEBUG