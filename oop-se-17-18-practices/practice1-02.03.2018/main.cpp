#include <iostream>
#include "Point_class.h"

int main() {

	Point p1(1, 7);
	Point p2(0, 1);
	Point p3 = Point();

	//p1 obj
	p1.print();
	//p2 obj
	p2.print();

	//moving p2
	p2.move(1.5, 1.5);
	p2.print();

	std::cout << (p1 > p2) << std::endl;

	//p4 is the sum of p1 and p2 objects
	Point p4 = (p1 + p2);
	p4.print();


	system("pause");
	return 0;
}