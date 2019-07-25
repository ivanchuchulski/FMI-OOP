#include "Account.h"


/*default ctor*/
Account::Account()
	:	m_CurrentAmount(0),
		m_OwnerID(OWNER_ID_DEFAULT),
		m_IBAN("N/A")
{}

/*copy ctor*/
Account::Account(const Account& someAccount)
	:	m_CurrentAmount(someAccount.m_CurrentAmount),
		m_OwnerID(someAccount.m_OwnerID),
		m_IBAN(someAccount.m_IBAN)

{}

/*ctor with parameters*/
Account::Account(int curent_amount, const std::string & owner_id, const std::string & iban)
	:	m_CurrentAmount((curent_amount >= 0) ? curent_amount : 0),
		m_OwnerID(owner_id),
		m_IBAN(iban)

{}

/*destructor*/
Account::~Account()
{}

/*copy=*/
Account& Account::operator=(const Account& someAccount)
{
	if (this != &(someAccount)) {
		//copy new data
		m_CurrentAmount = someAccount.m_CurrentAmount;
		m_OwnerID = someAccount.m_OwnerID;
		m_IBAN = someAccount.m_IBAN;
	}

	return *(this)		;// TODO: insert return statement here
}

/*add money to the current ammount*/
void Account::IncreaseAmmount(int increase)
{
	m_CurrentAmount += increase;
}
/*	the Withdraw method secures that the decrease does not exceed the current money*/
void Account::DecreaseAmmount(int decrease)
{
	m_CurrentAmount -= decrease;
}

void Account::ChangeOwnerID(const std::string & owner_id)
{
	m_OwnerID = owner_id;
}

void Account::ChangeIban(const std::string & iban)
{
	m_IBAN = iban;
}


const int Account::GetBalance() const
{
	return m_CurrentAmount;
}

const std::string Account::GetOwnerID() const
{
	return std::string(m_OwnerID);
}

const std::string Account::GetIban() const
{
	return std::string(m_IBAN);
}

/*
std::ostream & operator<<(std::ostream & outStream, const Account & someAcc)
{

	outStream << "\tcurrent ammount : " << someAcc.m_CurrentAmount
				<< "\n\townerID : " << someAcc.m_OwnerID
				<< "\n\tIBAN : " << someAcc.m_IBAN << '\n';

	return outStream;		// TODO: insert return statement here
}
*/