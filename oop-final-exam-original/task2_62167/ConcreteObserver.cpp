#include "ConcreteObserver.h"




ConcreteObserver::ConcreteObserver()
	:	Observer(),
		m_Name("Anonimous observer")
{}

ConcreteObserver::ConcreteObserver(const std::string name)
	:	Observer(),
		m_Name(name)
{}

ConcreteObserver::ConcreteObserver(const ConcreteObserver & other)
	:	Observer(other),
		m_Name(other.m_Name)
{
}

ConcreteObserver::~ConcreteObserver()
{}

ConcreteObserver & ConcreteObserver::operator=(const ConcreteObserver & other)
{
	if (this != &(other)) 
	{
		Observer::operator=(other);
		m_Name = other.m_Name;
	}

	return *(this);		// TODO: insert return statement here
}


void ConcreteObserver::UpdateRate(const Currency & someCurr) const
{
	std::cout << "UPDATE " << m_Name << " : ";
	someCurr.Details();
}


Observer* ConcreteObserver::CloneObserver() const
{
	return new ConcreteObserver(*(this));
}

std::string ConcreteObserver::GetName() const
{
	return std::string(m_Name);
}






