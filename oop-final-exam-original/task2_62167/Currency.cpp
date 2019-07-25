#include "Currency.h"

const double RATE_DEFAULT = 1.0;

Currency::Currency()
	:	m_Rate(RATE_DEFAULT),
		m_Name("Unknown")
{
}

Currency::Currency(const Currency & otherCurrencyObj)
	:	m_Rate(otherCurrencyObj.m_Rate),
		m_Name(otherCurrencyObj.m_Name)
{
}

Currency::Currency(double rate, const std::string & name)
	:	m_Rate((rate > 0) ? rate: RATE_DEFAULT),
		m_Name(name)
{
}

Currency::Currency(double rate, const char * name)
	:	m_Rate((rate > 0) ? rate : RATE_DEFAULT),
		m_Name((name != nullptr) ? name: "Unknown")
{
}

Currency::~Currency()
{
}


Currency & Currency::operator=(const Currency & otherCurrencyObj)
{
	if (this != &(otherCurrencyObj))
	{
		m_Rate = otherCurrencyObj.m_Rate;
		m_Name = otherCurrencyObj.m_Name;

	}

	return *(this);		// TODO: insert return statement here
}


void Currency::ChangeRate(double rate)
{
	if (rate > 0) 
	{
		m_Rate = rate;
	}
}


void Currency::ChangeName(const std::string & name)
{
	m_Name = name;

}

void Currency::ChangeName(const char * name)
{
	if (name != nullptr) {
		m_Name = name;
	}
}

const double Currency::GetRate() const
{
	return m_Rate;
}

std::string Currency::GetName() const
{
	return std::string(m_Name);
}


void Currency::Details() const
{
	std::cout << m_Name << ", " << m_Rate << '\n';
}