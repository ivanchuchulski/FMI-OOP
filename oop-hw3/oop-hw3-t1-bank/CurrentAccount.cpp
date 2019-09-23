#include "CurrentAccount.h"


CurrentAccount::CurrentAccount()
	:	Account()
{}

CurrentAccount::CurrentAccount(const CurrentAccount& other)
	:	Account(other)
{}

CurrentAccount::CurrentAccount(int initialDeposit, const std::string & ownerID, const std::string & iban)
	:	Account(initialDeposit, ownerID, iban)
{}

CurrentAccount::~CurrentAccount()
{}

CurrentAccount & CurrentAccount::operator=(const CurrentAccount & other)
{
	if (this != &other) 
	{
		Account::operator=(static_cast<const Account&>(other));
	}

	return *this;
}

// pure virtual mehtods overrides
int CurrentAccount::GetAccountType() const
{
	return static_cast<int>(AccountType::CurrentAccount);
}

Account* CurrentAccount::CloneAccount() const
{
	return new CurrentAccount(*this);
}

void CurrentAccount::Deposit(int depositAmmount)
{
	IncreaseBalance(depositAmmount);
}

bool CurrentAccount::Withdraw(int withdrawAmmount)
{
	if (GetBalance() < withdrawAmmount) 
	{
		return false; 
	}

	DecreaseBalance(withdrawAmmount);
	return true;
}

void CurrentAccount::DisplayAccount() const
{
	std::cout << *this << '\n';
}

// friend methods
std::ostream& operator<<(std::ostream& outStream, const CurrentAccount& currentAccount)
{

	outStream << "account type : Current Account\n" 
				<< static_cast<const Account&>(currentAccount);

	return outStream;
}