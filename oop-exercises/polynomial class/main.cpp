#include <iostream>
#include "Polynomial.h"

int main() {

	// 1*x^0 -3*x^1 + 5*x^2 + 9*x^3
	float someCoefs1[4] = { 1.0f, -3.0f, 5.0f, 9.0f };

	float someCoefs2[3] = { 1.0f, 1.0f, 1.0f };
	float someCoefs3[4] = { 2.0f, 2.0f, 2.0f, 2.0f };



	Polynomial myPoly2 = Polynomial(2, someCoefs2);
	Polynomial myPoly3 = Polynomial(3, someCoefs3);

	Polynomial poly4 = Polynomial();

	poly4 = myPoly2 + myPoly3;

	myPoly2.GetValue(2);


	std::cin.get();
	return 0;
}