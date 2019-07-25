#include "Var.h"

const char DEFAULT_NAME[4] = "N/a";
const size_t DEFAULT_LENGTH = 3;

char * Var::MakeCString(const char * source)
{
	char * toMake = nullptr;

	if (source != nullptr) {
		size_t sLen = strlen(source);
		toMake = new char[sLen + 1];
		strcpy_s(toMake, sLen + 1, source);

		return toMake;
	}

	else {
		toMake = new char[DEFAULT_LENGTH + 1];
		strcpy_s(toMake, DEFAULT_LENGTH + 1, source);

		return toMake;
	}
}



Var::Var()
	:	Expression::Expression(),
		m_VarName(nullptr),
		m_Value(0.0)
{
	m_VarName = MakeCString();
}

Var::Var(const Var & otherVarObj)
	:	Expression::Expression(otherVarObj),
		m_VarName(MakeCString(otherVarObj.m_VarName)),
		m_Value(otherVarObj.m_Value)
{
}


Var::Var(const char* name, double value)
	:	Expression::Expression(),
		m_VarName(MakeCString(name)),
		m_Value(value)
{
}


Var::~Var()
{
	//clearing dynamic memory
	if (m_VarName != nullptr) {
		delete[] m_VarName;
	}

}


Var & Var::operator=(const Var & otherVar)
{
	if (this != &(otherVar))
	{
		//clear current dynamic memory
		if (m_VarName != nullptr) {
			delete[] m_VarName;
		}

		//copy new data
		Expression::operator=(otherVar);

		m_VarName = MakeCString(otherVar.m_VarName);
		m_Value = otherVar.m_Value;
	}

	return *(this);		// TODO: insert return statement here
}


const double Var::Value() const
{
	return m_Value;
}


void Var::Print() const
{
	std::cout << "Variable name : " << m_VarName;
				//<< ", value : " << m_Value;
}


void Var::SetValue(double value)
{
	m_Value = value;
}