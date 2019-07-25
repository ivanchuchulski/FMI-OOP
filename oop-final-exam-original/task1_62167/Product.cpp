#include "Product.h"


Product::Product()
	:	Expression::Expression(),
		m_Product(0.0),
		m_lhsExpr(nullptr),
		m_rhsExpr(nullptr)
{
}

Product::Product(const Product& otherProductObj)
	:	Expression::Expression(otherProductObj),
		m_Product(otherProductObj.m_Product),
		m_lhsExpr(otherProductObj.m_lhsExpr),
		m_rhsExpr(otherProductObj.m_rhsExpr)
{
}

Product::Product(const Expression & lhsExpr, const Expression & rhsExpr)
	:	Expression::Expression(),
		m_Product(lhsExpr * rhsExpr),
		m_lhsExpr(&lhsExpr),
		m_rhsExpr(&rhsExpr)
{
}

Product::~Product()
{
}

Product & Product::operator=(const Product & otherProductObj)
{
	if (this != &(otherProductObj))
	{
		Expression::operator=(otherProductObj);
		m_Product = otherProductObj.m_Product;
		m_lhsExpr = otherProductObj.m_lhsExpr;
		m_rhsExpr = otherProductObj.m_rhsExpr;


	}

	return *(this);		// TODO: insert return statement here
}



const double Product::Value() const
{
	return m_Product;
}

void Product::Print() const
{
	if (m_lhsExpr != nullptr && m_rhsExpr != nullptr) {

		std::cout << "( "
			<< m_lhsExpr->Value()
			<< " ) * ( "
			<< m_rhsExpr->Value()
			<< " ) = " << m_Product << '\n';

	}
	else {
		std::cout << "Could not print data about origin products\n";
	}
}