#pragma once 

#ifndef OBSERVER_H
#define OBSERVER_H


#include "Currency.h"		//also includes <string>

class Observer {

public:
	Observer();
	Observer(const Observer& other);

	virtual ~Observer();

	Observer& operator=(const Observer& other);

	virtual void UpdateRate(const Currency& someCurr) const = 0;

	virtual Observer* CloneObserver() const = 0;

	virtual std::string GetName() const = 0;

};



#endif // !OBSERVER_H


