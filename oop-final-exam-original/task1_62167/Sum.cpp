#include "Sum.h"


Sum::Sum()
	:	Expression::Expression(),
		m_Sum(0.0),
		m_lhsExpr(nullptr),
		m_rhsExpr(nullptr)
{}

Sum::Sum(const Sum & otherSumObj)
	:	Expression::Expression(otherSumObj),
		m_Sum(otherSumObj.m_Sum),
		m_lhsExpr(otherSumObj.m_lhsExpr),
		m_rhsExpr(otherSumObj.m_rhsExpr)
{}

Sum::Sum(const Expression& lhsExpr, const Expression & rhsExpr)
	:	Expression::Expression(),
		m_Sum(lhsExpr + rhsExpr),
		m_lhsExpr(&lhsExpr),
		m_rhsExpr(&rhsExpr)
{}


Sum::~Sum()
{}

Sum & Sum::operator=(const Sum & otherSumObj)
{
	if (this != &(otherSumObj))
	{
		Expression::operator=(otherSumObj);
		m_Sum = otherSumObj.m_Sum;
		m_lhsExpr = otherSumObj.m_lhsExpr;
		m_rhsExpr = otherSumObj.m_rhsExpr;
	}

	return *(this);		// TODO: insert return statement here
}


const double Sum::Value() const
{
	return m_Sum;
}

void Sum::Print() const
{
	if (m_lhsExpr != nullptr && m_rhsExpr != nullptr) {

		std::cout << "( "
			<< m_lhsExpr->Value()
			<< " ) + ( "
			<< m_rhsExpr->Value()
			<< " ) = " << m_Sum << '\n';

	}
	else {
		std::cout << "Could not print data about origin sums\n";
	}
}




