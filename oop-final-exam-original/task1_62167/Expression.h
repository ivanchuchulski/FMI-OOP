#pragma once

#include <iostream>

class Expression {

public:
	//constructors
	Expression();
	Expression(const Expression& otherExpr);

	//destuctor
	virtual ~Expression();

	//copy assignment
	Expression& operator=(const Expression& otherExpr);

	virtual const double Value() const = 0;

	virtual void Print() const = 0;

	double operator+(const Expression& otherExpr) const;
	double operator*(const Expression& otherExpr) const;

};