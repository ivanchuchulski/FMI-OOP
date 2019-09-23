#include "Account.h"


Account::Account(int initialDeposit, const std::string& ownerID, const std::string& iban)
	:	m_balance(initialDeposit > 0 ? initialDeposit : 0),
		m_ownerID(ownerID),
		m_accountIBAN(iban)
{}

// modifiers
void Account::IncreaseBalance(int increase)
{
	m_balance += increase;
}

void Account::DecreaseBalance(int decrease)
{
	m_balance -= decrease;
}

void Account::ChangeOwnerID(const std::string & owner_id)
{
	m_ownerID = owner_id;
}

void Account::ChangeIban(const std::string & iban)
{
	m_accountIBAN = iban;
}


// getters
const int Account::GetBalance() const
{
	return m_balance;
}

const std::string Account::GetOwnerID() const
{
	return std::string(m_ownerID);
}

const std::string Account::GetAccountIBAN() const
{
	return std::string(m_accountIBAN);
}

std::ostream& operator<<(std::ostream& outStream, const Account& account)
{
	outStream << "balance : " << account.m_balance 
				<< "\n\t" << "ownerID : " << account.m_ownerID 
				<< "\n\t" << "IBAN : " << account.m_accountIBAN;

	return outStream;
}