#include "PrivilegeAccount.h"

// static member initialization
const int PrivilegeAccount::M_OVERDRAFT_DEFAULT = 100;

//
PrivilegeAccount::PrivilegeAccount()
	:	Account(),
		m_overdraftOverBalance(0)
{}

PrivilegeAccount::PrivilegeAccount(const PrivilegeAccount& other)
	:	Account(other),
		m_overdraftOverBalance(other.m_overdraftOverBalance)
{}

PrivilegeAccount::PrivilegeAccount(int initialDeposit, const std::string& ownerID, const std::string& iban, int overdraft)
	:	Account(initialDeposit, ownerID, iban),
		m_overdraftOverBalance((overdraft >= 0) ? overdraft : 0)
{}

PrivilegeAccount::~PrivilegeAccount()
{}

PrivilegeAccount & PrivilegeAccount::operator=(const PrivilegeAccount& other)
{
	if (this != &other) 
	{
		Account::operator=(static_cast<const Account&>(other));
		m_overdraftOverBalance = other.m_overdraftOverBalance;
	}

	return *this;
}


// getters
const int PrivilegeAccount::GetOverdraft() const
{
	return m_overdraftOverBalance;
}


// setters
void PrivilegeAccount::IncreaseOverdraft(int overdraftIncrease)
{
	if (overdraftIncrease < 0)
		return;

	m_overdraftOverBalance += overdraftIncrease;
}

void PrivilegeAccount::DecreaseOverdraft(int overdraftDecrease)
{
	if (overdraftDecrease > 0)
		return;

	m_overdraftOverBalance -= overdraftDecrease;
}


// pure virtual mehtods overrides
int PrivilegeAccount::GetAccountType() const
{
	return static_cast<int>(AccountType::PrivileAccount);
}

Account* PrivilegeAccount::CloneAccount() const
{
	return new PrivilegeAccount(*this);
}

void PrivilegeAccount::Deposit(int depositAmmount)
{
	IncreaseBalance(depositAmmount);
}

bool PrivilegeAccount::Withdraw(int withdrawAmmount)
{
	if (GetBalance() + m_overdraftOverBalance < withdrawAmmount) 
	{
		return false;
	}

	DecreaseBalance(withdrawAmmount);
	return true;
}

void PrivilegeAccount::DisplayAccount() const
{
	std::cout << *this << '\n';
}


// friend methods
std::ostream& operator<<(std::ostream& outStream, const PrivilegeAccount& privilegedAccount)
{
	outStream << "account type : Privileged Account\n"
		<< static_cast<const Account&>(privilegedAccount)
		<< "\n\t" << "overdraft : " << privilegedAccount.m_overdraftOverBalance << '\n';

	return outStream;
}