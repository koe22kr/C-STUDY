//#include<cstdlib>
//#include <math.h>
//#include <iostream>
//#include <memory>
//
//typedef struct __POINT
//{
//	int xpos;
//	int ypos;
//}Point;
//
//
//
//Point& pntAdder(const Point &p1, const Point &p2)
//{
//	Point* ppoint = new Point;
//	int x = 0;
//	int y = 0;
//	ppoint->xpos = p1.xpos + p2.xpos;
//	ppoint->ypos = p1.ypos + p2.ypos;
//	return *ppoint;
//}
//
//void main()
//{
//	Point* px1 = new Point;
//	Point* px2 = new Point;
//
//	px1->xpos = 10;
//	px1->ypos = 20;
//	px2->xpos = 30;
//	px2->ypos = 40;
//	Point* ppoint = new Point;
//	*ppoint = pntAdder(*px1, *px2);
//
//	std::cout << ppoint->xpos << std::endl << ppoint->ypos << std::endl;
//
//	delete(px1);
//	delete(px2);
//	delete(ppoint);
//	
//}
//
//
//
//
//
//


#include <time.h>
#include <stdlib.h>
#include <cstdio>


void main()
{

	int a = 0, b = 0, c = 0;
	
	srand(time(NULL));
	
		 a = (rand()%100);
		 b = (rand()%100);
		 c = (rand()%100);
}