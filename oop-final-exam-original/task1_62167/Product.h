#pragma once

#include "Expression.h"



class Product
	: public Expression
{
private:
	double m_Product;
	const Expression* m_lhsExpr;
	const Expression* m_rhsExpr;

public:
	//constructors
	Product();
	Product(const Product& otherProductObj);
	Product(const Expression& lhsExpr, const Expression& rhsExpr);

	//destructor
	~Product();

	//copy assignment
	Product& operator=(const Product& otherProductObj);


	const double Value() const override;
	void Print() const override;





};