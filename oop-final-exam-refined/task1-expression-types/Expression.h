#pragma once


class Expression
{

public:
	Expression() = default;
	Expression(const Expression& other) = default;

	virtual ~Expression() = default;

	Expression& operator=(const Expression& other) = default;

	virtual double Value() const = 0;
	virtual void Print() const = 0;

	double operator+(const Expression& rhs) const
	{
		return Value() + rhs.Value();
	}

	double operator*(const Expression& rhs) const
	{
		return Value() * rhs.Value();
	}

	virtual Expression* Clone() const = 0;

};
