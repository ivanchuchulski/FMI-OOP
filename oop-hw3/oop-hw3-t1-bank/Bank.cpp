#include "Bank.h"


/*default ctor*/
Bank::Bank()
	:	m_BankName("the anonymous bank"),	
		m_BankAddress("hidden address"),
		m_Customers(),
		m_Accounts()
{
	//just reserving some bytes in the std::vectors, the size is stil 0 though
	m_Customers.reserve(DEFAULT_CLIENT_NUM);
	m_Accounts.reserve(DEFAULT_CLIENT_NUM);
}

/*copy ctor*/
Bank::Bank(const Bank& someBank)
	:	m_BankName(someBank.m_BankName),
		m_BankAddress(someBank.m_BankAddress),
		m_Customers(),
		m_Accounts()
{
	if (!someBank.m_Customers.empty())
	{
		CopyVectorContent<Customer>(m_Customers, someBank.m_Customers, &Customer::CloneCustomer);
	}
	if (!someBank.m_Accounts.empty())
	{
		CopyVectorContent<Account>(m_Accounts, someBank.m_Accounts, &Account::CloneWithNew);
	}

	
}

/*ctor with parameters*/
Bank::Bank(const std::string & name_bank, const std::string& address_bank, int NumOfClients)
	:	m_BankName(name_bank),
		m_BankAddress(address_bank),
		m_Customers(),
		m_Accounts()
{
	m_Customers.reserve((NumOfClients > 0) ? NumOfClients : DEFAULT_CLIENT_NUM);
	m_Accounts.reserve((NumOfClients > 0)? NumOfClients : DEFAULT_CLIENT_NUM);
}

/*destuctor*/
Bank::~Bank()
{
	//std::vector only deletes the pointers it holds, it does not delete the data, pointed by them
	ClearVectorContent<Customer>(m_Customers);
	ClearVectorContent<Account>(m_Accounts);
}


Bank& Bank::operator=(const Bank& someBank)
{
	if (this != &(someBank)) {
		//copy the new data
		m_BankName = someBank.m_BankName;
		m_BankAddress = someBank.m_BankAddress;

		if (!someBank.m_Customers.empty())
			CopyVectorContent<Customer>(m_Customers, someBank.m_Customers, &Customer::CloneCustomer);

		if (!someBank.m_Accounts.empty())
			CopyVectorContent<Account>(m_Accounts, someBank.m_Accounts, &Account::CloneWithNew);
	
	}

	return *(this);			// TODO: insert return statement here
}


void Bank::ChangeBankName(const std::string& name) {
	m_BankName = name;
}

void Bank::ChangeBankAddress(const std::string& address) {
	m_BankAddress = address;
}

const std::string Bank::GetName() const
{
	return std::string(m_BankName);
}

const std::string Bank::GetAddress() const
{
	return std::string(m_BankAddress);
}



int Bank::FindByCustomerID(const std::string& customerID) const
{
	for (std::size_t i = 0; i < m_Customers.size(); i++)
	{
		if (m_Customers[i]->GetID() == customerID) {
			return i;
		}
	}

	return -1;			//if nothing found
}

void Bank::AddCustomer(const std::string& customer_id, const std::string& name, const std::string& address)
{
	int foundIndex = FindByCustomerID(customer_id);

	if (foundIndex == -1) {
		//add the new customer
		m_Customers.emplace_back(new Customer(customer_id, name, address));
		std::cout << "Customer add success!\n";
	}

	else {
		std::cout << "this customer already exists!\n";
		//maybe change the found customer data ?
	//	m_Customers[foundIndex]->SetID(customer_id);
	//	m_Customers[foundIndex]->SetName(name);
	//	m_Customers[foundIndex]->SetAddress(address);
	}
}

void Bank::ListCustomers() const
{
	if (m_Customers.empty() == true) {
		std::cout << "No customers to display!\n";
		return;
	}

	std::cout << "Printing bank customers : \n";
	for (std::size_t i = 0; i < m_Customers.size(); i++) {
		std::cout << '\t';
		m_Customers[i]->Display();
	}
}


/*delete the customer and all of its Accounts*/
void Bank::DeleteCustomer(const std::string& customer_id)
{
	if (m_Customers.empty() == true) {
		std::cout << "No customers to delete!\n";
		return;
	}

	int foundIndex = FindByCustomerID(customer_id);

	if (foundIndex == -1) {
		std::cout << "Customer not found!\n";
	}

	else {

		//first deleting all the accounts for the customer
		for (std::size_t i = 0; i < m_Accounts.size(); i++)
		{
			if (m_Accounts[i]->GetOwnerID() == customer_id) {
				//delete the info pointed by the pointer and then the pointer by the erase method
				delete m_Accounts[i];
				m_Accounts.erase(m_Accounts.begin() + i);
			}
		}

		//then delete the customer
		delete m_Customers[foundIndex];
		m_Customers.erase(m_Customers.begin() + foundIndex);
		std::cout << "Customer removal success!\n";
	}

}


void Bank::AddAccount(acc::AccountTypes accountType, int amount, const std::string& owner_id, const std::string& iban)
{
	//first check if there are any customers in the bank
	if (m_Customers.empty() == true)
	{
		std::cout << "No customers in the bank, consider becoming one first!\n";
		//return;
	}

	//setting to false by default bec if m_Customers is empty the loop wont start, so the result it false
	bool foundCustomer = false;
	bool alreadyExistingIban = false;

	//searching for customer
	for (std::size_t i = 0; i < m_Customers.size(); i++)
	{
		if (m_Customers[i]->GetID() == owner_id) {
			foundCustomer = true;
			break;
		}
	}

	if (foundCustomer == false) {
		std::cout << "No customer has that ID, try adding a customer first!\n";
		return;
	}

	//searching for already existing iban
	for (std::size_t i = 0; i < m_Accounts.size(); i++)
	{
		if (m_Accounts[i]->GetIban() == iban) {
			alreadyExistingIban = true;
			break;
		}
	}

	if (alreadyExistingIban == true) {
		std::cout << "This IBAN already exists!\n";
		return;
	}

	float interest = 0.0f;
	int overdraft = 0;
	switch (accountType)
	{
		case acc::AccountTypes::ACurrentAccount :

			m_Accounts.emplace_back(new CurrentAccount(amount, owner_id, iban));
			//m_Accounts.push_back(new CurrentAccount(amount, owner_id, iban));
			break;

		case acc::AccountTypes::ASavingsAccount :

			std::cout << "Please enter a interest for the Savings Account :";
			std::cin >> interest;
			m_Accounts.emplace_back(new SavingsAccount(amount, owner_id, iban, interest));
			break;

		case acc::AccountTypes::APrivilegeAccount:

			std::cout << "Please enter a overdraft for the Privilege Account :";
			std::cin >> overdraft;
			m_Accounts.emplace_back(new PrivilegeAccount(amount, owner_id, iban, overdraft));
			break;

		default:
			break;
	}

	std::cout << "Account add success!\n";

}


void Bank::DeleteAccount(const std::string& iban)
{
	for (std::size_t i = 0; i < m_Accounts.size(); i++)
	{
		if (m_Accounts[i]->GetIban() == iban) {
			delete m_Accounts[i];
			m_Accounts.erase(m_Accounts.begin() + i);
			std::cout << "Account removal success!\n";
			break;
		}
	}
}

void Bank::ListAccounts() const
{
	if (m_Accounts.size() == 0) {
		std::cout << "No accounts to display!\n";
		return;
	}
	else {
		std::cout << "Printing bank accounts : \n";
		//using a range for loop (c++11)
		for (auto account : m_Accounts)
		{
			std::cout << '\t';
			account->DisplayAccount();
		}

	}
}


void Bank::ListCustomerAccount(const std::string& customer_id) const
{
	int foundIndex = FindByCustomerID(customer_id);

	if (foundIndex == -1) {
		std::cout << "No such customer found!\n";
		return;
	}

	else {
		bool foundAccount = false;
		for (std::size_t i = 0; i < m_Accounts.size(); i++)
		{
			if (m_Accounts[i]->GetOwnerID() == customer_id) {
				m_Accounts[i]->DisplayAccount();
				foundAccount = true;
			}
		}

		if (foundAccount == false) {
			std::cout << "No accounts with the given customer id found!\n";
		}
	}
}

int Bank::FindAccountByIBAN(const std::string & iban_to_find) const
{
	for (std::size_t i = 0; i < m_Accounts.size(); i++)
	{
		if (m_Accounts[i]->GetIban() == iban_to_find) {
			return i;
		}
	}

	return -1;
}

void Bank::Transfer(const std::string& fromIBAN, const std::string& toIBAN, int ammount)
{

	if (m_Customers.empty() == true || m_Accounts.empty() == true)
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


	bool withdraw_success =  m_Accounts[fromIndex]->Withdraw(ammount);

	if (withdraw_success == false) {
		std::cout << "Can not withraw that ammount from the account!\n";
		return;
	}
	else {
		m_Accounts[toIndex]->Deposit(ammount);
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

	m_Accounts[foundIndex]->Deposit(add_ammount);
	std::cout << "Account deposition success!\n";

}

bool Bank::WithdrawFromAccount(const std::string& withdraw_from_iban, int request_ammount)
{
	int foundIndex = FindAccountByIBAN(withdraw_from_iban);

	if (foundIndex == -1) {
		std::cout << "Can not find such account!\n";
		return false;
	}


	bool withdraw_success = m_Accounts[foundIndex]->Withdraw(request_ammount);

	if (withdraw_success == false) {
		std::cout << "Can not withraw that ammount from the account!\n";
		return false;
	}
	else {
		std::cout << "Account withdrawing success!\n";
		return true;
	}

}


std::ostream & operator<<(std::ostream& outStream, const Bank& someBank)
{
	outStream << "\nBank " << someBank.GetName() << " info : \n"
		<< "\taddress : " << someBank.GetAddress();
	
	outStream << '\n';
	someBank.ListCustomers();

	outStream << '\n';
	someBank.ListAccounts();

	outStream << std::endl;

	return outStream;		// TODO: insert return statement here
}

void Bank::DisplayBank() const
{
	std::cout << *(this) << std::endl;
}


void Bank::PrintSupportedAccountTypes() const
{
	std::cout << "0 <-> CurrentAccount || (1) <-> Savings Account || (2) <-> Privileged Account\n";
}





//clearing method
template<typename Type>
void Bank::ClearVectorContent(std::vector<Type*>& vec)
{
	if (!vec.empty())
	{
		//deleting the content behing the pointers
		for (std::size_t ind = 0; ind < vec.size(); ind++)
		{
			delete vec[ind];
		}

		//clearing the pointers that the vector holds
		vec.clear();
	}
}

template<typename Type>
void Bank::CopyVectorContent(std::vector<Type*>& destination, const std::vector<Type*>& othervec_source, Type* (Type::*CloningMethod)() const)
{
	//clear old data
	ClearVectorContent<Type>(destination);

	//copy new stuff
	for (std::size_t index = 0; index < othervec_source.size(); index++)
	{
		destination.emplace_back((othervec_source[index]->*CloningMethod)());
	}
}