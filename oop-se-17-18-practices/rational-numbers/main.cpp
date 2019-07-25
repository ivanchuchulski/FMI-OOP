/*
* main.cpp
*/

#include <iostream>

#include "Rational.h"


#define spacingMesg std::cout << std::endl

int main() {
	Rational r = Rational(3, 4);
	Rational q;
	Rational m(1, 1);
	Rational n(2, 3);

	m.print();
	n.print();
	
	//the overloaded operator '^' _> m gets the squared values of n
	m ^ n;
	Rational k = Rational(m ^ n);
	n % m;
	Rational i = (n % m);

	m.print();
	n.print();
	k.print();


	//Rational p = add(r, q);
	//r.print();
	//q.print();
	//p.print();




	std::cin.get();
	return 0;
}


;