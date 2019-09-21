#include "Account.h"


Account::Account(int initialDeposit, const std::string& ownerID, const std::string& iban)
	:	m_balance(initialDeposit > 0 ? initialDeposit : 0),
		m_ownerID(ownerID),
		m_IBAN(iban)
{}

// modifiers
/*add money to the current ammount*/
void Account::IncreaseAmmount(int increase)
{
	m_balance += increase;
}

// the Withdraw method secures that the decrease does not exceed the current money*/
void Account::DecreaseAmmount(int decrease)
{
	m_balance -= decrease;
}

void Account::ChangeOwnerID(const std::string & owner_id)
{
	m_ownerID = owner_id;
}

void Account::ChangeIban(const std::string & iban)
{
	m_IBAN = iban;
}


const int Account::GetBalance() const
{
	return m_balance;
}

const std::string Account::GetOwnerID() const
{
	return std::string(m_ownerID);
}

const std::string Account::GetIban() const
{
	return std::string(m_IBAN);
}

std::ostream& operator<<(std::ostream& outStream, const Account& account)
{

	outStream << "balance : " << account.m_balance << "\n\townerID : " << account.m_ownerID << "\n\tIBAN : " << account.m_IBAN;

	return outStream;
}