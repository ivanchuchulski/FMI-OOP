#pragma once

#include "Expression.h"


class Sum
	: public Expression
{
private:
	double m_Sum;
	//the pointers are used to call the Print() in the respective Expressions the Sum has been constructed with, 
	//the pointers must not be used to delete the experssions, no ownership of the class
	const Expression* m_lhsExpr;
	const Expression* m_rhsExpr;


public:
	//constructors
	Sum();
	Sum(const Sum& otherSumObj);
	Sum(const Expression& lhsExpr, const Expression& rhsExpr);

	//destructor
	~Sum();

	//copy assignment
	Sum& operator=(const Sum& otherSumObj);


	const double Value() const override;
	void Print() const override;


};





