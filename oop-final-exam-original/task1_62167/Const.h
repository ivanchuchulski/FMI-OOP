#pragma once


#include "Expression.h"


class Const 
	: public Expression
{

private:
	double m_ConstValue;

public:
	//constructors
	Const();
	Const(const Const& otherConstObj);
	Const(double const_value);

	//destuctor
	~Const();

	//copy assignment
	Const& operator=(const Const& otherConstObj);

	const double Value() const override;
	void Print() const override;


};











