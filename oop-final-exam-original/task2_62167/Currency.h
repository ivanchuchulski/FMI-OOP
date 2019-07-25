#pragma once 

#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>

class Currency
{
private:
	double m_Rate;
	std::string m_Name;

public:
	//constructors
	Currency();
	Currency(const Currency& otherCurrencyObj);
	Currency(double rate, const std::string& name);
	Currency(double rate, const char* name);

	//destructor
	~Currency();

	//copy assignment
	Currency& operator=(const Currency& otherCurrencyObj);

	void ChangeRate(double rate);
	void ChangeName(const std::string& name);
	void ChangeName(const char* name);

	const double GetRate() const;
	std::string GetName() const;

	void Details() const;

};








#endif // !CURRENCY_H


