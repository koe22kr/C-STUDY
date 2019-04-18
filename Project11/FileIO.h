
#pragma once
#include"Linklist.h"

class FileIO
{
public:
	FileIO();
	~FileIO();
	
	Student* pst;    
	Linklist* pll;
	void SaveStudentData();
	void LoadStudentData();
	
	

};

