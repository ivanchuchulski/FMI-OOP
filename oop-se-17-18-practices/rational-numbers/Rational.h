#pragma once
/*
* Rational.h
*/


#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
	int numer, denom;
	int gcd(int, int);

public:
	// ������������
	Rational();
	Rational(int, int);
	Rational(const Rational& otherObj);

	// ������� �� ������
	int getNumerator() const;
	int getDenominator() const;
	void print() const;

	// �������
	void read();

	//overloaded opeators for the class
	Rational& operator^(const Rational& otherObj);
	Rational operator% (const Rational& otherObj);
};

Rational add(const Rational&, const Rational&);
Rational subtract(const Rational&, const Rational&);
Rational multiply(const Rational&, const Rational&);
Rational divide(const Rational&, const Rational&);



#endif /* RATIONAL_H */
