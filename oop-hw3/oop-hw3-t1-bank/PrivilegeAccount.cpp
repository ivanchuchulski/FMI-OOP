#include "PrivilegeAccount.h"


/*default ctor*/
PrivilegeAccount::PrivilegeAccount()
	:	Account(),
		m_Overdraft(0)
{}

/*copy ctor*/
PrivilegeAccount::PrivilegeAccount(const PrivilegeAccount& somePrivilAcc)
	:	Account(somePrivilAcc),
		m_Overdraft(somePrivilAcc.m_Overdraft)
{}

/*ctor with parameters*/
PrivilegeAccount::PrivilegeAccount(int current_amount, const std::string& owner_id, const std::string& iban, int overdraft)
	:	Account(current_amount, owner_id, iban),
		m_Overdraft((overdraft >= 0)? overdraft : 0)
{}

/*destructor*/
PrivilegeAccount::~PrivilegeAccount()
{}


/*copy=*/
PrivilegeAccount & PrivilegeAccount::operator=(const PrivilegeAccount& somePrivilAcc)
{
	if (this != &(somePrivilAcc)) {
		//copy the new data
		Account::operator=(somePrivilAcc);
		m_Overdraft = somePrivilAcc.m_Overdraft;
	}

	return *(this);		// TODO: insert return statement here
}


void PrivilegeAccount::SetOverdraft(int overdraft)
{
	m_Overdraft = (overdraft >= 0) ? overdraft : 0;
}

const int PrivilegeAccount::GetOverdraft() const
{
	return m_Overdraft;
}

void PrivilegeAccount::Deposit(int add_ammount)
{
	IncreaseAmmount(add_ammount);
}

bool PrivilegeAccount::Withdraw(int request_ammount)
{
	if (GetBalance() + m_Overdraft < request_ammount) {
		return false;
	}
	else {
		DecreaseAmmount(request_ammount);
		return true;
	}
}


void PrivilegeAccount::DisplayAccount() const
{
	std::cout << *(this) << '\n';
}


std::ostream & operator<<(std::ostream & outStream, const PrivilegeAccount & somePrivilAcc)
{
	outStream << "account type : Privileged Account\n"
		<< "\tcurrent ammount : " << somePrivilAcc.GetBalance()
		<< "\n\townerID : " << somePrivilAcc.GetOwnerID()
		<< "\n\tIBAN : " << somePrivilAcc.GetIban()
		<< "\n\toverdraft : " << somePrivilAcc.m_Overdraft << '\n';


	return outStream;		// TODO: insert return statement here
}

Account * PrivilegeAccount::CloneWithNew() const
{
	return new PrivilegeAccount(*(this));
}