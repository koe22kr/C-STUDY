#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#ifdef on

class Book
{
private:
	char* title;
	char* isbn;
	int price;


public:
	Book(const char* intitle, const char* inisbn,int inprice);
	~Book();
	void ShowBookInfo();
};

Book::Book(const char* intitle,const char* inisbn, int inprice) : price(inprice)
{
	title = new char[strlen(intitle) + 1];
	strcpy(title, intitle);
	isbn = new char[strlen(inisbn) + 1];
	strcpy(isbn, inisbn);
}

Book::~Book()
{
	delete title;
	delete isbn;
}
void Book::ShowBookInfo()
{
	cout << "재목: " << title << endl 
	<< "isbn : " << isbn << endl 
	<< "가격 :" << price << endl;

}

class EBook :public Book
{
private:
	char* DRMKey;

public:
	EBook(const char* intitle, const char* inisbn, int inprice, const char* indrmkey);
	~EBook();
	void ShowEBookInfo();


};

EBook::EBook(const char* intitle, const char* inisbn, int inprice, const char* indrmkey) : Book(intitle,inisbn,inprice)
{
	DRMKey = new char[strlen(indrmkey) + 1];
	strcpy(DRMKey, indrmkey);
}

EBook ::~EBook()
{
}
void EBook::ShowEBookInfo()
{
	ShowBookInfo();
	cout << "DRMKey : " << DRMKey << endl;
}


int main(void)
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();//
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();//
	return 0;
	   
}


#endif // DEBUG