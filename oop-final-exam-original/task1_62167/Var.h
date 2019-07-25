#pragma once

#include <cstring>
#include "Expression.h"


class Var 
	: public Expression
{

private:
	char * m_VarName;
	double m_Value;

protected:
	char* MakeCString(const char* source = nullptr);

public:
	//constructors
	Var();
	Var(const Var& otherVar);
	Var(const char* name, double value);

	//destructor
	~Var();

	//copy assignment
	Var& operator=(const Var& otherVar);


	const double Value() const override;
	void Print() const override;

	void SetValue(double value);


};






