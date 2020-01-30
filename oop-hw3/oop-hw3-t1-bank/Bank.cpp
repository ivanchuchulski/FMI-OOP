#include "Bank.h"

#include <algorithm>


//
Bank::Bank()
	:	m_bankName("the anonymous bank"),	
		m_bankAddress("hidden address"),
		m_customers(),
		m_accounts()
{}

Bank::Bank(const Bank& other)
	:	m_bankName(other.m_bankName),
		m_bankAddress(other.m_bankAddress),
		m_customers(other.m_customers),
		m_accounts()
{
	CopyAccounts(other.m_accounts);
}

Bank::Bank(const std::string& bankName, const std::string& bankAddress)
	:	m_bankName(bankName),
		m_bankAddress(bankAddress),
		m_customers(),
		m_accounts()
{}

Bank::~Bank()
{
	ClearAccounts();
}

Bank& Bank::operator=(const Bank& other)
{
	if (this != &other) 
	{
		ClearBank();
		CopyOtherBank(other);
	}

	return *this;
}


// private helper methods
void Bank::ClearAccounts()
{
	// deleting the data pointed by the pointers, using a pointer reference to be able to do the assignment to nullptr correctly
	for (Account*& account : m_accounts)
	{
		delete account;
		account = nullptr;
	}

	// clearing the pointers that the vector holds
	m_accounts.clear();
}

void Bank::CopyAccounts(const std::vector<Account*>& otherAccounts)
{
	for (const Account* account : otherAccounts)
	{
		m_accounts.emplace_back(account->CloneAccount());
	}
}

void Bank::ClearBank()
{
	m_bankName.clear();
	m_bankAddress.clear();
	m_customers.clear();
	ClearAccounts();
}

void Bank::CopyOtherBank(const Bank& otherBank)
{
	m_bankName = otherBank.m_bankName;
	m_bankAddress = otherBank.m_bankAddress;
	m_customers = otherBank.m_customers;
	CopyAccounts(otherBank.m_accounts);
}

std::vector<Customer>::const_iterator Bank::FindByCustomerID(const std::string& customerID) const
{
	for (std::vector<Customer>::const_iterator cust = m_customers.begin(); cust != m_customers.end(); ++cust)
	{
		if (cust->GetID() == customerID)
		{
			return cust;
		}
	}

	return m_customers.end();
}

std::vector<Account*>::const_iterator Bank::FindAccountByIBAN(const std::string& accountIBAN) const
{
	for (auto accountIt = m_accounts.begin(); accountIt != m_accounts.end(); ++accountIt)
	{
		if ((*accountIt)->GetAccountIBAN() == accountIBAN)
		{
			return accountIt;
		}
	}

	// if nothing found
	return m_accounts.end();
}

bool Bank::AccountAlreadyOpened(const std::vector<Account*>::const_iterator accountIt) const
{
	return accountIt != m_accounts.end();
}

bool Bank::CustomerAlreadyRegistered(const std::vector<Customer>::const_iterator customerIt) const
{
	return customerIt != m_customers.end();
}

bool Bank::NoRegisteredCustomers() const
{
	return m_customers.empty();
}

bool Bank::NoAccountsOpened() const
{
	return m_accounts.empty();
}

//setters
void Bank::ChangeBankName(const std::string& name) 
{
	m_bankName = name;
}

void Bank::ChangeBankAddress(const std::string& address) 
{
	m_bankAddress = address;
}


// getters
const std::string Bank::GetName() const
{
	return std::string(m_bankName);
}

const std::string Bank::GetAddress() const
{
	return std::string(m_bankAddress);
}


// customer modifiers
void Bank::AddCustomer(const std::string& customerName, const std::string& customerAddress)
{
	m_customers.emplace_back(Customer(customerName, customerAddress));

	std::cout << "success : customer " << customerName << " added\n";
}

void Bank::DeleteCustomer(const std::string& customerIDToRemove)
{
	if (NoRegisteredCustomers()) 
	{
		std::cout << "customer removal failed : no customers to delete\n";
		return;
	}

	auto customerToRemoveIt = FindByCustomerID(customerIDToRemove);

	if (!CustomerAlreadyRegistered(customerToRemoveIt)) 
	{
		std::cout << "customer removal failed : customer id not found\n";
		return;
	}

	// first removing all the accounts for that customer
	for (size_t i = 0; i < m_accounts.size(); i++)
	{
		if (m_accounts[i]->GetOwnerID() == customerIDToRemove) 
		{
			delete m_accounts[i];
			m_accounts.erase(m_accounts.begin() + i);
		}
	}

	// then delete the customer
	m_customers.erase(customerToRemoveIt);

	std::cout << "customer removal success!\n";
}


// account modifiers
void Bank::AddAccount(const std::string& customerID, const AccountType accountType)
{
	if (NoRegisteredCustomers())
	{
		std::cout << "account addition failed : the bank has no customers\n";
		return;
	}

	auto customerIndexIt = FindByCustomerID(customerID);

	if (!CustomerAlreadyRegistered(customerIndexIt))
	{
		std::cout << "account addition failed : the customer doesn't exist\n";
		return;
	}

	Account* temp = nullptr;

	switch (accountType)
	{
		case AccountType::CurrentAccount :
			temp = new CurrentAccount(customerID);
			break;

		case AccountType::SavingsAccount :
			temp = new SavingsAccount(customerID);
			break;

		case AccountType::PrivileAccount :
			temp = new PrivilegeAccount(customerID);
			break;

		default :
			std::cout << "account addition failed : invalid account type\n";
			return;
	}

	
	//m_accounts.emplace_back(temp->CloneAccount());
	//delete temp;
	
	// or just that
	m_accounts.emplace_back(temp);

	std::cout << "account addition success\n";
}

void Bank::DeleteAccount(const std::string& accountIBAN)
{
	if (NoRegisteredCustomers())
	{
		std::cout << "account removal failed : the bank has no customers\n";
		return;
	}

	if (NoAccountsOpened())
	{
		std::cout << "account removal failed : the bank has no accounts\n";
		return;
	}

	auto ibanIndex = FindAccountByIBAN(accountIBAN);

	if (!AccountAlreadyOpened(ibanIndex))
	{
		std::cout << "account removal failed : no account with IBAN " << accountIBAN << " exists\n";
		return;
	}

	// delete the account : first free memory and then delete the pointer in the vector
	auto removeArrayIndex = ibanIndex - m_accounts.begin();

	delete m_accounts[removeArrayIndex];
	
	m_accounts.erase(ibanIndex);

	std::cout << "account removal success\n";
}

// bank money operations
void Bank::Transfer(const std::string& fromIBAN, const std::string& toIBAN, double ammount)
{
	if (NoRegisteredCustomers())
	{
		std::cout << "the bank has no customers\n";
		return;
	}

	if (NoAccountsOpened())
	{
		std::cout << "bank has no accounts\n";
		return;
	}

	// check if the passed strings are the same
	if (fromIBAN== toIBAN)
	{
		std::cout << "error : source and destination IBANs are the same\n";
		return;
	}

	auto sourceIt = FindAccountByIBAN(fromIBAN);
	auto destIt = FindAccountByIBAN(toIBAN);

	// check if both accounts exist
	if (!AccountAlreadyOpened(sourceIt))
	{
		std::cout << "error : account to transfer from doesn't exist\n";
		return;
	}

	if (!AccountAlreadyOpened(destIt))
	{
		std::cout << "error : account to transfer to doesn't exist\n";
		return;
	}

	auto sourceArrayIndex = sourceIt- m_accounts.begin();
	auto destArrayIndex = destIt - m_accounts.begin();

	 //try to withdraw from source account
	bool withdrawSuccessful = m_accounts[sourceArrayIndex]->Withdraw(ammount);

	if (!withdrawSuccessful) 
	{
		std::cout << "Can not withraw that ammount from the account!\n";
		return;
	}

	// transfer to destination account
	m_accounts[destArrayIndex]->Deposit(ammount);

	std::cout << "Transfer successful!\n";
}

void Bank::DepositToAccount(const std::string& accountIBAN, double depositAmmount)
{
	auto foundIndex = FindAccountByIBAN(accountIBAN);

	if (!AccountAlreadyOpened(foundIndex)) 
	{
		std::cout << "depoit failed : account doesn't exist\n";
		return;
	}

	auto accountArrayIndex = foundIndex - m_accounts.begin();

	m_accounts[accountArrayIndex]->Deposit(depositAmmount);

	std::cout << "account deposit success\n";
}

bool Bank::WithdrawFromAccount(const std::string& accountIBAN, double withdrawAmmount)
{
	auto foundIndex = FindAccountByIBAN(accountIBAN);

	if (!AccountAlreadyOpened(foundIndex)) 
	{
		std::cout << "withdraw failed : account doesn't exist\n";
		return false;
	}

	auto accountArrayIndex = foundIndex - m_accounts.begin();

	bool withdrawSuccessful = m_accounts[accountArrayIndex]->Withdraw(withdrawAmmount);

	if (!withdrawSuccessful) 
	{
		std::cout << "withraw failed : withraw ammount is to high\n";
		return false;
	}

	std::cout << "withdraw success\n";
	return true;
}

// bank information 
void Bank::ListCustomers() const
{
	if (NoRegisteredCustomers())
	{
		std::cout << "bank has no customers to display\n";
		return;
	}

	std::cout << "printing bank customers : \n";
	for (const Customer& customer : m_customers)
	{
		customer.DisplayCustomerInfo();
	}
}

void Bank::ListAccounts() const
{
	if (NoRegisteredCustomers())
	{
		std::cout << "bank has no customers and thus no accounts opened\n";
		return;
	}

	if (NoAccountsOpened()) 
	{
		std::cout << "bank has no accounts opened\n";
		return;
	}

	std::cout << "printing bank accounts : \n";

	for (const Account* account : m_accounts)
	{
		account->DisplayAccount();
	}
}

void Bank::ListCustomerAccount(const std::string& customerID) const
{
	if (NoRegisteredCustomers())
	{
		std::cout << "the bank has no customers\n";
		return;
	}

	auto idIndex = FindByCustomerID(customerID);

	if (!CustomerAlreadyRegistered(idIndex)) 
	{
		std::cout << "customer id not found\n";
		return;
	}

	if (NoAccountsOpened())
	{
		std::cout << "bank has no accounts\n";
		return;
	}

	for (const Account* account : m_accounts)
	{
		if (account->GetOwnerID() == customerID) 
		{
			account->DisplayAccount();
		}
	}
}

void Bank::PrintSupportedAccountTypes() const
{
	std::cout << static_cast<int>(AccountType::CurrentAccount) << " <-> CurrentAccount "
				<< static_cast<int>(AccountType::SavingsAccount) << " <-> Savings Account "
				<< static_cast<int>(AccountType::PrivileAccount) << " <-> Privileged Account\n";
}

void Bank::DisplayBank() const
{
	std::cout << *this << '\n';
}


// friend methods
std::ostream& operator<<(std::ostream& outStream, const Bank& someBank)
{
	outStream << "\nBank " << someBank.GetName() << " info : \n"
		<< "\taddress : " << someBank.GetAddress();
	
	outStream << '\n';
	someBank.ListCustomers();

	outStream << '\n';
	someBank.ListAccounts();

	outStream << std::endl;

	return outStream;
}