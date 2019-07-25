#include "SavingsAccount.h"


/*default ctor*/
SavingsAccount::SavingsAccount()
	:	Account(),
		m_InterestRate(INTEREST_DEFAULT)
{}


/*copy ctor*/
SavingsAccount::SavingsAccount(const SavingsAccount& someSavingsAcc)
	:	Account(someSavingsAcc),
		m_InterestRate(someSavingsAcc.m_InterestRate)
{}

/*ctor with parameters*/
SavingsAccount::SavingsAccount(int current_amount, const std::string& owner_id, const std::string& iban, float interest)
	:	Account(current_amount, owner_id, iban),
		m_InterestRate((interest >= 0.0f && interest <= 100.0f) ? interest : INTEREST_DEFAULT)
{}

/*destructor*/
SavingsAccount::~SavingsAccount()
{}

/*copy=*/
SavingsAccount & SavingsAccount::operator=(const SavingsAccount & someSavingsAcc)
{
	if (this != &(someSavingsAcc)) {
		//copy the new data
		Account::operator=(someSavingsAcc);
		m_InterestRate = someSavingsAcc.m_InterestRate;
	}

	return *(this);		// TODO: insert return statement here
}

void SavingsAccount::SetInterest(float interest)
{
	if (interest >= 0.0f && interest <= 100.0f) {
		m_InterestRate = interest;
	}

}

const float SavingsAccount::GetInterestRate()
{
	return m_InterestRate;
}

/*		virtual methods overrides		*/
void SavingsAccount::Deposit(int add_ammount)
{
	IncreaseAmmount(add_ammount);
}


bool SavingsAccount::Withdraw(int request_ammount)
{
	if (GetBalance() < request_ammount) {
		return false;
	}
	else {
		DecreaseAmmount(request_ammount);
		return true;
	}
}

void SavingsAccount::DisplayAccount() const
{
	/*
	const Account& refToBase = *(this);
	std::cout << "account type : Savings Account\n" 
				<< refToBase
				<<  "\tinterest rate : " << m_InterestRate << '\n';
	*/

	std::cout << *(this) << '\n';

}


std::ostream & operator<<(std::ostream & outStream, const SavingsAccount & someSavingsAcc)
{

	outStream << "account type : Savings Account\n" 
		<< "\tcurrent ammount : " << someSavingsAcc.GetBalance()
		<< "\n\townerID : " << someSavingsAcc.GetOwnerID()
		<< "\n\tIBAN : " << someSavingsAcc.GetIban() 
		<< "\n\tinterst rate : " << someSavingsAcc.m_InterestRate <<  '\n';

	return outStream;		// TODO: insert return statement here
}

Account * SavingsAccount::CloneWithNew() const
{
	return new SavingsAccount(*(this));
}