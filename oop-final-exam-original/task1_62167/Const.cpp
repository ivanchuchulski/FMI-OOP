#include "Const.h"


Const::Const()
	:	Expression::Expression(),
		m_ConstValue(0.0)
{
}


Const::Const(const Const & otherConstObj)
	:	Expression::Expression(otherConstObj),
		m_ConstValue(otherConstObj.m_ConstValue)
{
}



Const::Const(double const_value)
	:	Expression::Expression(),
		m_ConstValue(const_value)
{
}

Const::~Const()
{}

Const & Const::operator=(const Const & otherConstObj)
{
	if (this != &(otherConstObj)) 
	{
		Expression::operator=(otherConstObj);
		m_ConstValue = otherConstObj.m_ConstValue;

	}

	return *(this);		// TODO: insert return statement here
}


const double Const::Value() const
{
	return m_ConstValue;
}

void Const::Print() const
{
	std::cout << "Constant value : " << m_ConstValue;
}
