#include "Expression.h"



Expression::Expression()
//	:	m_Expr(0.0)
{
}


Expression::Expression(const Expression& otherExpr)
//	:	m_Expr(otherExpr.m_Expr)
{
}

//dtor
Expression::~Expression()
{
}

Expression & Expression::operator=(const Expression & otherExpr)
{
	if (this != &(otherExpr)) {

	}

	return *(this);	// TODO: insert return statement here
}


double Expression::operator+(const Expression & otherExpr) const
{
	return this->Value() + otherExpr.Value();
}


double Expression::operator*(const Expression & otherExpr) const
{
	return this->Value() * otherExpr.Value();
}
