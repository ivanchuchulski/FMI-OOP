#include "Bank.h"


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
	CopyVectorOfPointers<Account>(m_accounts, other.m_accounts, &Account::CloneAccount);	
}

Bank::Bank(const std::string& bankName, const std::string& bankAddress)
	:	m_bankName(bankName),
		m_bankAddress(bankAddress),
		m_customers(),
		m_accounts()
{}

Bank::~Bank()
{
	ClearVectorOfPointers<Account>(m_accounts);
}

Bank& Bank::operator=(const Bank& other)
{
	if (this != &other) 
	{
		ClearVectorOfPointers(m_accounts);

		m_bankName = other.m_bankName;
		m_bankAddress = other.m_bankAddress;
		m_customers = other.m_customers;
		CopyVectorOfPointers<Account>(m_accounts, other.m_accounts, &Account::CloneAccount);
	}

	return *this;
}


// private helper methods
bool Bank::HasCustomers() const
{
	return !m_customers.empty();
}

template<typename Type>
void Bank::ClearVectorOfPointers(std::vector<Type*>& vec)
{
	//deleting the data pointed by the pointers
	for (size_t i = 0; i < vec.size(); i++)
	{
		delete vec[i];
	}

	//clearing the pointers that the vector holds
	vec.clear();
}

template<typename Type>
void Bank::CopyVectorOfPointers(std::vector<Type*>& destination, const std::vector<Type*>& source, Type* (Type::* CloningMethod)() const)
{
	//for (size_t index = 0; index < source.size(); index++)
	//{
	//	destination.emplace_back((source[index]->*CloningMethod)());
	//}

	for (auto sourceAccount : source)
	{
		destination.emplace_back(sourceAccount->*CloningMethod()));
	}
}

int Bank::FindByCustomerID(const std::string& customerID) const
{
	for (size_t i = 0; i < m_customers.size(); i++)
	{
		if (m_customers[i].GetID() == customerID)
		{
			return i;
		}
	}

	return -1;
}

int Bank::FindAccountByIBAN(const std::string& accountIBAN) const
{
	for (size_t i = 0; i < m_accounts.size(); i++)
	{
		if (m_accounts[i]->GetIban() == accountIBAN) 
		{
			return i;
		}
	}

	return -1;
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
void Bank::AddCustomer(const std::string& customerID, const std::string& customerName, const std::string& customerAddress)
{
	int foundIndex = FindByCustomerID(customerID);

	if (foundIndex != -1)
	{
		std::cout << "customer addition failed : customer " << customerName << " already exists\n";
	}

	m_customers.emplace_back(Customer(customerID, customerName, customerAddress));

	std::cout << "success : customer " << customerName << " added\n";
}

void Bank::DeleteCustomer(const std::string& customerID)
{
	if (!HasCustomers()) 
	{
		std::cout << "removal failed : no customers to delete\n";
		return;
	}

	int foundIndex = FindByCustomerID(customerID);

	if (foundIndex == -1) 
	{
		std::cout << "removal failed : customer id not found\n";
		return;
	}

	//first removing all the accounts for that customer
	for (size_t i = 0; i < m_accounts.size(); i++)
	{
		if (m_accounts[i]->GetOwnerID() == customerID) 
		{
			delete m_accounts[i];
			m_accounts.erase(m_accounts.begin() + i);
		}
	}

	//then delete the customer
	m_customers.erase(m_customers.begin() + foundIndex);
	std::cout << "customer removal success!\n";
}


// account modifiers
void Bank::AddAccount(acc::AccountTypes accountType, int amount, const std::string& customerID, const std::string& ownedIBAN)
{
	if (!HasCustomers())
	{
		std::cout << "account addition failed : the bank has no customers\n";
		return;
	}

	int customerIndex = FindByCustomerID(customerID);
	if (customerIndex == -1)
	{
		std::cout << "account addition failed : the customer doesn't exist\n";
		return;
	}

	int ibanIndex = FindAccountByIBAN(ownedIBAN);
	if (ibanIndex == -1)
	{
		std::cout << "account addition failed : the customer doesn't exist\n";
		return;
	}



	switch (accountType)
	{
		case acc::AccountTypes::ACurrentAccount :
			m_accounts.emplace_back(new CurrentAccount(amount, customerID, ownedIBAN));
			break;

		case acc::AccountTypes::ASavingsAccount :
			float interest = 0.0f;
			std::cout << "Please enter a interest for the Savings Account :";
			std::cin >> interest;
			m_accounts.emplace_back(new SavingsAccount(amount, customerID, ownedIBAN, interest));
			break;

		case acc::AccountTypes::APrivilegeAccount:
			int overdraft = 0;
			std::cout << "Please enter a overdraft for the Privilege Account :";
			std::cin >> overdraft;
			m_accounts.emplace_back(new PrivilegeAccount(amount, customerID, ownedIBAN, overdraft));
			break;

		default:
			break;
	}

	std::cout << "account addition success\n";
}

void Bank::DeleteAccount(const std::string& accountIBAN)
{
	if (!HasCustomers())
	{
		std::cout << "account removal failed : the bank has no customers\n";
		return;
	}

	if (m_accounts.empty())
	{
		std::cout << "account removal failed : the bank has no accounts\n";
		return;
	}

	int ibanIndex = FindAccountByIBAN(accountIBAN);

	if (ibanIndex == -1)
	{
		std::cout << "account removal failed : no account with such id exists\n";
		return;
	}

	delete m_accounts[ibanIndex];
	m_accounts.erase(m_accounts.begin() + ibanIndex);

	std::cout << "account removal success\n";
}

// bank money operations
void Bank::Transfer(const std::string& fromIBAN, const std::string& toIBAN, int ammount)
{
	if (m_customers.empty() == true || m_accounts.empty() == true)
	{
		return;
	}

	int fromIndex = FindAccountByIBAN(fromIBAN);
	int toIndex = FindAccountByIBAN(toIBAN);

	//checks
	if (fromIndex = -1 || toIndex == -1) {
		std::cout << "Can not find such accounts!\n";
		return;
	}
	else if (fromIndex == toIndex) {
		std::cout << "No need to transfer to self!\n";
		return;
	}


	bool withdraw_success = m_accounts[fromIndex]->Withdraw(ammount);

	if (withdraw_success == false) {
		std::cout << "Can not withraw that ammount from the account!\n";
		return;
	}
	else {
		m_accounts[toIndex]->Deposit(ammount);
		std::cout << "Transfer succeessful!\n";
	}

}

void Bank::DepositToAccount(const std::string& deposit_to_iban, int add_ammount)
{
	int foundIndex = FindAccountByIBAN(deposit_to_iban);

	if (foundIndex == -1) {
		std::cout << "Can not find such account!\n";
		return;
	}

	m_accounts[foundIndex]->Deposit(add_ammount);
	std::cout << "Account deposition success!\n";

}

bool Bank::WithdrawFromAccount(const std::string& withdraw_from_iban, int request_ammount)
{
	int foundIndex = FindAccountByIBAN(withdraw_from_iban);

	if (foundIndex == -1) {
		std::cout << "Can not find such account!\n";
		return false;
	}


	bool withdraw_success = m_accounts[foundIndex]->Withdraw(request_ammount);

	if (withdraw_success == false) {
		std::cout << "Can not withraw that ammount from the account!\n";
		return false;
	}
	else {
		std::cout << "Account withdrawing success!\n";
		return true;
	}

}

// bank information 
void Bank::ListCustomers() const
{
	if (!HasCustomers())
	{
		std::cout << "bank has no customers to display\n";
		return;
	}

	std::cout << "Printing bank customers : \n";
	for (const Customer& customer : m_customers)
	{
		customer.DisplayCustomerInfo();
	}
}

void Bank::ListAccounts() const
{
	if (!HasCustomers())
	{
		std::cout << "bank has no customers";
		return;
	}

	if (m_accounts.empty()) 
	{
		std::cout << "the bank has no accounts\n";
		return;
	}

	std::cout << "Printing bank accounts : \n";
	for (auto account : m_accounts)
	{
		account->DisplayAccount();
	}
}

void Bank::ListCustomerAccount(const std::string& customerID) const
{
	if (!HasCustomers())
	{
		std::cout << "the bank has no customers\n";
		return;
	}

	int idIndex = FindByCustomerID(customerID);

	if (idIndex == -1) 
	{
		std::cout << "customer id not found\n";
		return;
	}

	if (m_accounts.empty())
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

void Bank::DisplayBank() const
{
	std::cout << *(this) << '\n';
}

void Bank::PrintSupportedAccountTypes() const
{
	std::cout << "0 <-> CurrentAccount || (1) <-> Savings Account || (2) <-> Privileged Account\n";
}


// friend methods
std::ostream & operator<<(std::ostream& outStream, const Bank& someBank)
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