#include <iostream>
#include "Database.h"
#define off

#ifdef on

using namespace Records;
int main()
{
	Database myDB;
	Employee& emp1 = myDB.addEmployee("Greg", "Wallis");
	emp1.fire();
	Employee& emp2 = myDB.addEmployee("Marc", "Gregoire");
	emp2.setSalary(100000);
	Employee& emp3 = myDB.addEmployee("go", "hong");
	emp3.promote();

	std::cout << "all employee:" << std::endl;
	myDB.displayAll();
	std::cout << "corrent employee:" << std::endl;
	myDB.displayCurrent();
	std::cout << "former employee:" << std::endl;
	myDB.displayFormer();
	return 0;


}
#endif