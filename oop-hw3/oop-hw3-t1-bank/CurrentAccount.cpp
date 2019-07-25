#include "CurrentAccount.h"


/*default ctor*/
CurrentAccount::CurrentAccount()
	:	Account()
{}

/*copy ctor*/
CurrentAccount::CurrentAccount(const CurrentAccount & someCurrent)
	:	Account(someCurrent)
{}

/*ctor with parameters*/
CurrentAccount::CurrentAccount(int curent_amount, const std::string & owner_id, const std::string & iban)
	:	Account(curent_amount, owner_id, iban)
{}

/*destuctor*/
CurrentAccount::~CurrentAccount()
{}

/*copy=*/
CurrentAccount & CurrentAccount::operator=(const CurrentAccount & someCurrent)
{
	if (this != &(someCurrent)) 
	{
		Account::operator=(someCurrent);
	}

	return *this;		// TODO: insert return statement here
}


/*		virtual methods overrides		*/

/*deposit method, adds monet to the current ammount*/
void CurrentAccount::Deposit(int add_ammount)
{
	IncreaseAmmount(add_ammount);
}


bool CurrentAccount::Withdraw(int request_ammount)
{
	if (GetBalance() < request_ammount) {
		return false; 
	}
	else {
		DecreaseAmmount(request_ammount);
		return true;
	}
}


void CurrentAccount::DisplayAccount() const
{
//	const Account& refToBase = *(this);
//	std::cout << "account type : Current Account\n" << refToBase << '\n';

	std::cout << *(this) << '\n';

}

std::ostream & operator<<(std::ostream & outStream, const CurrentAccount & someCurrentAcc)
{
	outStream << "account type : Current Account\n" 
		<< "\tcurrent ammount : " << someCurrentAcc.GetBalance()
		<< "\n\townerID : " << someCurrentAcc.GetOwnerID()
		<< "\n\tIBAN : " << someCurrentAcc.GetIban() << '\n';

	return outStream;		// TODO: insert return statement here
}

Account* CurrentAccount::CloneWithNew() const
{
	return new CurrentAccount(*(this));
}