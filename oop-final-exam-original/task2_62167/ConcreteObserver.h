#pragma once

#ifndef CONCRETE_OBSERVER_H
#define CONCRETE_OBSERVER_H

#include <iostream>
#include "Currency.h"		//also includes <string>
#include "Observer.h"


class ConcreteObserver
	: public Observer
{
private:
	std::string m_Name;
public:

	ConcreteObserver();
	ConcreteObserver(const ConcreteObserver& other);
	ConcreteObserver(const std::string name);

	~ConcreteObserver();

	ConcreteObserver& operator=(const ConcreteObserver& other);
	
	void UpdateRate(const Currency& someCurr) const override;

	Observer* CloneObserver() const override;

	std::string GetName() const override;

};












#endif // !CONCRETE_OBSERVER_H
