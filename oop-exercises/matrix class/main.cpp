#include <iostream>
#include "Matrix.h"

/* macro for spacing separation */
#define spacingMsg std::cout << std::endl

int main() {

	float foo[3][3] = { {1, 2, 3}, {4, 5, 6,}, {7, 8, 9} };

	Matrix a = Matrix();
	Matrix b = Matrix((float*)foo);
	Matrix c = Matrix(b);
	Matrix d = Matrix();

	a = b;
	d.setMatrix((float*)foo);

	b.scalarMultiply(2);

	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << d;

	spacingMsg;
	std::cout << "Press ENTER to proceed -> ";
	std::cin.get();
	return 0;
}