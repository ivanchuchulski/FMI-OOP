#pragma once

#include "Expression.h"
#include <iostream>


class Constant : public Expression
{
private:
	double m_ConstantValue;

public:
	Constant() = default;
	Constant(const Constant& other) = default;
	Constant(double value)
		:	m_ConstantValue(value)
	{}


	~Constant() = default;

	Constant& operator=(const Constant& other) = default;

	virtual double Value() const override
	{
		return m_ConstantValue;
	}

	virtual void Print() const override
	{
		std::cout << "Constant value : " << m_ConstantValue;
	}


	Expression* Clone() const override
	{
		return new Constant(*(this));
	}
};