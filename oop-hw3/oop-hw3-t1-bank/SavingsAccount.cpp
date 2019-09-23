#include "SavingsAccount.h"


// static members initialization
const float SavingsAccount::M_YEARLY_INTEREST_DEFAULT = 1.1f;

//
SavingsAccount::SavingsAccount()
	:	Account(),
		m_yearlyInterestProcent(M_YEARLY_INTEREST_DEFAULT)
{}

SavingsAccount::SavingsAccount(const SavingsAccount& other)
	:	Account(other),
		m_yearlyInterestProcent(other.m_yearlyInterestProcent)
{}

SavingsAccount::SavingsAccount(int initialDeposit, const std::string& ownerID, const std::string& iban, float yearlyInterestProcent)
	:	Account(initialDeposit, ownerID, iban),
		m_yearlyInterestProcent((yearlyInterestProcent >= 0.0f && yearlyInterestProcent <= 100.0f) ? yearlyInterestProcent : M_YEARLY_INTEREST_DEFAULT)
{}

SavingsAccount::~SavingsAccount()
{}

SavingsAccount& SavingsAccount::operator=(const SavingsAccount& other)
{
	if (this != &other) 
	{
		Account::operator=(static_cast<const Account&>(other));
		m_yearlyInterestProcent = other.m_yearlyInterestProcent;
	}

	return *this;
}


// getters
const float SavingsAccount::GetInterestProcent()
{
	return m_yearlyInterestProcent;
}


// setters
void SavingsAccount::IncreaseInterest(float interestIncrease)
{
	if (interestIncrease < 0)
		return;

	float increasedInterest = m_yearlyInterestProcent + interestIncrease;

	if (increasedInterest > 100)
		return;

	m_yearlyInterestProcent = increasedInterest;
}

void SavingsAccount::DecreaseInterest(float interestDecrease)
{
	if (interestDecrease > 0)
		return;

	float decreasedInterest = m_yearlyInterestProcent - interestDecrease;
	
	if (decreasedInterest < 0)
		return;

	m_yearlyInterestProcent = decreasedInterest;
}


// pure virtual mehtods overrides
int SavingsAccount::GetAccountType() const
{
	return static_cast<int>(AccountType::SavingsAccount);
}

Account* SavingsAccount::CloneAccount() const
{
	return new SavingsAccount(*this);
}

void SavingsAccount::Deposit(int depositAmmount)
{
	IncreaseBalance(depositAmmount);
}

bool SavingsAccount::Withdraw(int withdrawAmmount)
{
	if (GetBalance() < withdrawAmmount) 
	{
		return false;
	}

	DecreaseBalance(withdrawAmmount);
	return true;
}

void SavingsAccount::DisplayAccount() const
{
	std::cout << *this << '\n';
}

// friend methods
std::ostream& operator<<(std::ostream& outStream, const SavingsAccount& savingsAccount)
{
	outStream << "account type : Savings Account\n" 
		<< static_cast<const Account&>(savingsAccount)
		<< "\n\t" << "interst rate : " << savingsAccount.m_yearlyInterestProcent <<  '\n';

	return outStream;
}