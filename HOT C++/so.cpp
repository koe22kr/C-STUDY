#include <iostream>
using namespace std;

class Tem
{
private:
	int n;
public:
	Tem(int n) :n(n) {
		cout << "����" << endl;
	}
	~Tem()
	{
		cout << "�׾��" << endl;
	}
	void info()
	{
		cout << "num" << n << endl;

	}



};


int main()
{
	Tem(100);
		cout << "1st" << endl;

	Tem a=	Tem(200);
		cout << "2st" << endl;


		const Tem &ref = Tem(300);
		cout << "3St" << endl;
		return 0;

}
