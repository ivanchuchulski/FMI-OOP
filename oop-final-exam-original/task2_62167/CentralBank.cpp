#include "CentralBank.h"



int CentralBank::FindCurrencyByName(const std::string & curr_name) const
{
	for (size_t i = 0; i < m_CurrencyList.size(); i++) {
		if (curr_name == m_CurrencyList[i].GetName()) {
			return i;
		}
	}

	return -1;
}

void CentralBank::CopyObservers(const std::vector<Observer*>& source)
{
	ClearObservers();

	m_Observers.reserve(source.size());

	for (size_t i = 0; i < source.size(); i++) 
	{
		this->m_Observers.push_back(source[i]->CloneObserver());
	}

}

void CentralBank::ClearObservers()
{
	if (!m_Observers.empty())
	{
		//clering the data behind the pointers
		for (size_t i = 0; i < m_Observers.size(); i++) {
			delete m_Observers[i];
		}

		m_Observers.clear();
	}
}


CentralBank::CentralBank()
	:	m_BankName("No bank name"),
		m_CurrencyList(),
		m_Observers()
{
}



CentralBank::CentralBank(const CentralBank& otherBank)
	:	m_BankName(otherBank.m_BankName),
		m_CurrencyList(otherBank.m_CurrencyList),
		m_Observers()
{
	CopyObservers(otherBank.m_Observers);
}

CentralBank::CentralBank(const std::string & name)
	:	m_BankName(name),
		m_CurrencyList(),
		m_Observers()
{
}

CentralBank & CentralBank::operator=(const CentralBank & otherBank)
{
	if (this != &(otherBank))
	{
		m_BankName = otherBank.m_BankName;
		m_CurrencyList = otherBank.m_CurrencyList;
		CopyObservers(otherBank.m_Observers);

	}

	return *(this);		// TODO: insert return statement here
}


CentralBank::~CentralBank()
{
	ClearObservers();
}


void CentralBank::AddCurrency(const Currency & someCurrencyObj)
{
	int foundInd = FindCurrencyByName(someCurrencyObj.GetName());

	if (foundInd != -1)
	{
		m_CurrencyList.push_back(Currency(someCurrencyObj));
	}

	else {
		std::cout << "This currency already exists!\n";
	}

}

void CentralBank::DeleteCurrencyByName(const std::string & curr_name)
{

	int foundInd = FindCurrencyByName(curr_name);

	if (foundInd != -1)
	{
		m_CurrencyList.erase(m_CurrencyList.begin() + foundInd);
	}

	else {
		std::cout << "Currency not found!\n";
	}
}

void CentralBank::SetRate(const std::string& curr_name, double rate)
{
	int foundInd = FindObserer(curr_name);

	if (foundInd != -1)
	{
		m_CurrencyList[foundInd].ChangeRate(rate);

		Notify(m_CurrencyList[foundInd]);
	}

	else {
		std::cout << "Currency not found!\n";
	}

}


int CentralBank::FindObserer(const std::string & obs_name) const
{
	for (size_t i = 0; i < m_Observers.size(); i++) {
		if (obs_name == m_Observers[i]->GetName()) {
			return i;
		}
	}

	return -1;
}




void CentralBank::RegisterObserver(const Observer* someObs)
{
	this->m_Observers.push_back(someObs->CloneObserver());
}

void CentralBank::UnregisterObserver(const std::string & obs_name)
{
	int foundInd = FindObserer(obs_name);

	if (foundInd != -1)
	{
		delete m_Observers[foundInd];
		m_Observers.erase(m_Observers.begin() + foundInd);
	}

	else {
		std::cout << "Observer not found!\n";
	}

}


void CentralBank::Notify(const Currency & changedCurr) const
{
	for (size_t i = 0; i < m_Observers.size(); i++)
	{
		m_Observers[i]->UpdateRate(changedCurr);

	}
}




















