#pragma once

#include "Expression.h"
#include <iostream>
#include <string>

class Variable : public Expression
{
private:
	double m_VarValue;
	std::string m_Name;

public:
	Variable() = default;
	Variable(const Variable& other) = default;
	Variable(double value, const std::string& name)
		:	m_VarValue(value),
			m_Name(name)
	{}

	~Variable() = default;

	Variable& operator=(const Variable& other) = default;


	virtual double Value() const override
	{
		return m_VarValue;
	}

	virtual void Print() const override 
	{
		std::cout << "Variable name : " << m_Name;
	}

	virtual Expression * Clone() const override
	{
		return new Variable(*(this));
	}

};