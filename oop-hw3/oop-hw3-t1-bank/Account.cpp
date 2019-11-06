#include "Account.h"

unsigned int Account::M_IBAN_COUNTER = 0;


//
Account::Account(const std::string& ownerID)
	:	m_balance(0.0),
		m_ownerID(ownerID),
		m_accountIBAN(GenerateNumberedString("#IBAN#"))
{
}

Account::Account(const std::string& ownerID, double initialDeposit)
	:	m_balance(initialDeposit > 0 ? initialDeposit : 0.0),
		m_ownerID(ownerID),
		m_accountIBAN(GenerateNumberedString("#IBAN#"))
{}


// private method to generate numbered strings for the IBAN
std::string Account::GenerateNumberedString(const std::string& prefix) const
{
	std::string result = prefix;
	result.append(std::to_string(M_IBAN_COUNTER++));

	return result;
}


// modifiers
void Account::IncreaseBalance(double increase)
{
	m_balance += increase;
}

void Account::DecreaseBalance(double decrease)
{
	m_balance -= decrease;
}


// getters
const double Account::GetBalance() const
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


// setters
void Account::SetOwnerID(const std::string& ownerID)
{
	m_ownerID = ownerID;
}

void Account::SetIBAN(const std::string& iban)
{
	m_accountIBAN = iban;
}


// virtual methods
void Account::InputAccount(const std::string& ownerID)
{
	m_ownerID = ownerID;

	std::cout << "enter balance : ";
	std::cin >> m_balance;
	std::cin.ignore();

	std::cout << "enter account IBAN";
	std::getline(std::cin, m_accountIBAN, '\n');
}

// friend methods
std::ostream& operator<<(std::ostream& outStream, const Account& account)
{
	outStream << "balance : " << account.m_balance 
				<< "\n\t" << "ownerID : " << account.m_ownerID 
				<< "\n\t" << "IBAN : " << account.m_accountIBAN;

	return outStream;
}

std::istream& operator>>(std::istream& inStream, Account& account)
{
	inStream >> account.m_balance;
	inStream.ignore();

	std::getline(inStream, account.m_accountIBAN, '\n');
	std::getline(inStream, account.m_accountIBAN, '\n');

	return inStream;
}