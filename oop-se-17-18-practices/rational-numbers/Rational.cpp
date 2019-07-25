/*
*  Rational.cpp
*/
#include "Rational.h"

#include <iostream>
#include <math.h>

using namespace std;

int powerFunc(int base, int power) {
	int result = 1;

	if (power == 0) {
		//result = 1;
		return result;
	}

	for (int i = 0; i < power; i++) {
		result *= base;
	}
	return result;
}

// Конструктор по подразбиране
Rational::Rational() {
	numer = 0;
	denom = 1;
}


// Конструктор с 2 параметъра
Rational::Rational(int n, int d) {
	if (n == 0 || d == 0) {
		numer = 0;
		denom = 1;
	}
	else {
		int g = gcd(abs(n), abs(d));
		if (n > 0 && d > 0 || n < 0 && d < 0) {
			numer = abs(n) / g;
			denom = abs(d) / g;
		}
		else {
			numer = -abs(n) / g;
			denom = abs(d) / g;
		}
	}
}

Rational::Rational(const Rational & otherObj) {
	this->numer = otherObj.numer;
	this->denom = otherObj.denom;
}


// селектор за числител
int Rational::getNumerator() const {
	return numer;
}

// селектор за знаменател
int Rational::getDenominator() const {
	return denom;
}

// функция за извеждане
void Rational::print() const {
	cout << getNumerator() << '/' << getDenominator() << endl;
}

// мутатор (функция за промяна) чрез въвеждане
void Rational::read() {
	// Пример: 2/5
	cin >> numer;
	cin.ignore();
	cin >> denom;
}


// Най-голям общ делител
int Rational::gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}


// Събиране на 2 рационални числа
Rational add(const Rational& p, const Rational& q) {
	return Rational(p.getNumerator() * q.getDenominator()
		+ p.getDenominator() * q.getNumerator(),
		p.getDenominator() * q.getDenominator());
}

// Изваждане на 2 рационални числа
Rational subtract(const Rational& p, const Rational& q) {
	return Rational(p.getNumerator() * q.getDenominator()
		- p.getDenominator() * q.getNumerator(),
		p.getDenominator() * q.getDenominator());
}

// Умножение на 2 рационални числа
Rational multiply(const Rational& p, const Rational& q) {
	return Rational(p.getNumerator() * q.getNumerator(),
		p.getDenominator() * q.getDenominator());
}

// Деление на 2 рационални числа
Rational divide(const Rational& p, const Rational& q) {
	return Rational(p.getNumerator() * q.getDenominator(),
		p.getDenominator() * q.getNumerator());
}

Rational & Rational::operator^(const Rational & otherObj)
{

	this->numer = powerFunc(otherObj.numer, 2);
	this->denom = powerFunc(otherObj.denom, 2);
	// TODO: insert return statement here
	return *this;

}

Rational Rational::operator%(const Rational & otherObj) {

	this->numer += powerFunc(otherObj.numer, 2);
	this->denom += powerFunc(otherObj.denom, 2);
	// TODO: insert return statement here
	//calls the copy constructor, bec its not a reference
	return *this;
}