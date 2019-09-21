#include "SavingsAccount.h"


SavingsAccount::SavingsAccount()
	:	Account(),
		m_yearlyInterest(INTEREST_DEFAULT)
{}

SavingsAccount::SavingsAccount(const SavingsAccount& other)
	:	Account(other),
		m_yearlyInterest(other.m_yearlyInterest)
{}

SavingsAccount::SavingsAccount(int initialDeposit, const std::string& ownerID, const std::string& iban, float yearlyInterest)
	:	Account(initialDeposit, ownerID, iban),
		m_yearlyInterest((yearlyInterest >= 0.0f && yearlyInterest <= 100.0f) ? yearlyInterest : INTEREST_DEFAULT)
{}

SavingsAccount::~SavingsAccount()
{}

SavingsAccount& SavingsAccount::operator=(const SavingsAccount& other)
{
	if (this != &other) 
	{
		Account::operator=(other);
		m_yearlyInterest = other.m_yearlyInterest;
	}

	return *this;
}

void SavingsAccount::SetInterest(float interest)
{
	if (interest >= 0.0f && interest <= 100.0f) 
	{
		m_yearlyInterest = interest;
	}
}

const float SavingsAccount::GetInterestRate()
{
	return m_yearlyInterest;
}

// pure virtual mehtods overrides
Account* SavingsAccount::CloneAccount() const
{
	return new SavingsAccount(*this);
}

void SavingsAccount::Deposit(int depositAmmount)
{
	IncreaseAmmount(depositAmmount);
}

bool SavingsAccount::Withdraw(int withdrawAmmount)
{
	if (GetBalance() < withdrawAmmount) 
	{
		return false;
	}

	DecreaseAmmount(withdrawAmmount);
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
		<< "\n\tinterst rate : " << savingsAccount.m_yearlyInterest <<  '\n';

	return outStream;
}