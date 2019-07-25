#pragma once

#ifndef CENTRAL_BANK_H
#define CENTRAL_BANK_H

#include <vector>
#include "Currency.h"		//also includes <string>
#include "Observer.h"

class CentralBank {
private:
	std::string m_BankName;
	std::vector<Currency> m_CurrencyList;
	std::vector<Observer*> m_Observers;

protected:
	int FindCurrencyByName(const std::string& curr_name) const;
	void CopyObservers(const std::vector<Observer*>& source);
	void ClearObservers();

	int FindObserer(const std::string& obs_name) const;

public:
	//constructors
	CentralBank();
	CentralBank(const std::string& name);

	//destructor
	~CentralBank();

	CentralBank(const CentralBank& otherBank);
	CentralBank& operator=(const CentralBank& otherBank);

	void AddCurrency(const Currency& someCurrencyObj);
	void DeleteCurrencyByName(const std::string& curr_name);
	void SetRate(const std::string& curr_name, double rate);

	void RegisterObserver(const Observer* someObs);
	void UnregisterObserver(const std::string& obs_name);
	void Notify(const Currency& changedCurr) const;

};






#endif // !CENTRAL_BANK_H


