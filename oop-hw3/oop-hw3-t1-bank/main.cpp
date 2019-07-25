/*

	->faculty num : 62167
	->OOP_HW3_Task1
	->compiler : Visual C++

*/

#include <iostream>
#include <string>
#include <array>

#include "Customer.h"			//also includes <iostream>, <string>
//#include "Account.h"			//also includes <iostream>, <string>
#include "CurrentAccount.h"		//also includes "Account.h"
#include "SavingsAccount.h"		//also includes "Account.h"
#include "PrivilegeAccount.h"	//also includes "Account.h"

#include "Bank.h"


char toUpper(char symbol) {
	if (symbol >= 'a' && symbol <= 'z') {
		return symbol - ('a' - 'A');
	}
	return symbol;
}

/*main menu*/
void DisplayMenu() {

	std::cout << "\n\t 1 \t List customers\n"
				<< "\t 2 \t Add new customer\n"
				<< "\t 3 \t Delete customer\n"
				<< "\t 4 \t List all accounts\n"
				<< "\t 5 \t List customer accounts\n"
				<< "\t 6 \t Add new account\n"
				<< "\t 7 \t Delete account\n"
				<< "\t 8 \t Withdraw from account\n"
				<< "\t 9 \t Deposit to account\n"
				<< "\t 10 \t Transfer\n"
				<< "\t 11 \t Display information for the bank\n"
				<< "\t 12 \t Quit\n"
				<< "\t 0 \t Show the menu\n";

}

int ExtractSymbol(char* promptString) 
{
	int response;

	std::cout << promptString;
	std::cin >> response;

	std::cin.get();

	return response;
}

bool DetermineLegalCommand(int cmd) 
{

	for (int legal_cmd = 0; legal_cmd <= 12 ; legal_cmd++) 
	{
		if (cmd == legal_cmd) {
			return true;
		}
	}

	return false;
}

int GetCommand()
{
	int userCommand = ExtractSymbol("\n\nEnter an command [0, 12] _> ");	//get a char from the console

	while (DetermineLegalCommand(userCommand) == false) 
	{
		std::cout << "\nIllegal command, please enter again";
		DisplayMenu();
		userCommand = ExtractSymbol("\n\nEnter an integer [0, 12] _> ");
	}

	return userCommand;
}


void MakeString (const char* msg, std::string& str_to_make)
{

	std::cout << msg;

	std::getline(std::cin, str_to_make, '\n');

}


/*		Main		*/	
int main() {


	/*tests*/
	/*
	{
		std::array<std::string, 5> IDs_test = { "#012","#123", "#234", "#345", "#456" };
		std::array<std::string, 6> Names_test = { "Kolyo" ,"Dragan", "Petkan", "Vladimir", "Darina", "Anton" };
		std::array<std::string, 6> Addresses_test = { "Sofia", "Varna", "Plovdiv", "New York", "London", "Moscow" };
		std::array<std::string, 5> Ibans_test = { "BG_01_23", "BG_12_34","BG_45_43", "EN_01_23", "RU_56_78" };


		Customer c1 = Customer(IDs_test[0], Names_test[0], Addresses_test[0]);

		CurrentAccount a1(500, IDs_test[0], Ibans_test[0]);

		SavingsAccount s1(1000, IDs_test[1], Ibans_test[1], 5.5f);

		PrivilegeAccount pr1(2500, IDs_test[2], Ibans_test[2], 500);

		std::cout << a1 << std::endl;
		a1.DisplayAccount();

		std::cout << s1 << std::endl;
		s1.DisplayAccount();

		std::cout << pr1 << std::endl;
		pr1.DisplayAccount();

		Bank KTB_bank("KTB", "Sofia", 10);

		KTB_bank.AddCustomer(c1.GetID(), c1.GetName(), c1.GetAddress());
		KTB_bank.AddAccount(acc::AccountTypes::ACurrentAccount, a1.GetBalance(), a1.GetOwnerID(), a1.GetIban());

		KTB_bank.ListAccounts();

		KTB_bank.ListCustomers();

		KTB_bank.DisplayBank();
	}
	*/


	Bank* APromisingBank = new Bank("Bright finances", "Sofia");

	int command = 0;

	/*buffer data used for user input*/
	std::string id_buffer{};
	std::string	name_buffer{};
	std::string	address_buffer{};
	int acc_type_buffer{};
	int amount_buffer = 0;
	std::string iban_from_buffer;
	std::string iban_to_buffer;

	DisplayMenu();

	do 
	{
		command = GetCommand();

		switch (command)
		{
			case 1:
				APromisingBank->ListCustomers();
				break;

			case 2:
				MakeString("Enter customer_id : ", id_buffer);
				MakeString("\nenter name : ", name_buffer);
				MakeString("\nenter address : ", address_buffer);

				APromisingBank->AddCustomer(id_buffer, name_buffer, address_buffer);

				id_buffer.clear();
				name_buffer.clear();
				address_buffer.clear();
				break;

			case 3:
				MakeString("Enter a customer ID to delete : ", id_buffer);

				APromisingBank->DeleteCustomer(id_buffer);

				id_buffer.clear();
				break;

			case 4:
				APromisingBank->ListAccounts();
				break;

			case 5:
				MakeString("Enter customer_id to view : ", id_buffer);

				APromisingBank->ListCustomerAccount(id_buffer);

				id_buffer.clear();
				break;

			case 6:
				APromisingBank->PrintSupportedAccountTypes();
				std::cin >> acc_type_buffer;
				std::cout << "\nenter initial amount in the account : ";
				std::cin >> amount_buffer;
				std::cin.ignore();
				MakeString("\nenter owner_id : ", id_buffer);
				MakeString("\nenter iban : ", iban_from_buffer);

				APromisingBank->AddAccount((acc::AccountTypes)acc_type_buffer, amount_buffer, id_buffer, iban_from_buffer);

				id_buffer.clear();
				iban_from_buffer.clear();
				break;


			case 7:
				MakeString("\nenter account iban to delete : ", iban_from_buffer);
				APromisingBank->DeleteAccount(iban_from_buffer);
				iban_from_buffer.clear();
				break;

			case 8:
				MakeString("\nenter account iban to withdraw from : ", iban_from_buffer);
				std::cout << "\nenter amount to withdraw from the account : ";
				std::cin >> amount_buffer;

				APromisingBank->WithdrawFromAccount(iban_from_buffer, amount_buffer);

				iban_from_buffer.clear();
				break;

			case 9:
				MakeString("\nenter account iban to deposit to : ", iban_from_buffer);
				std::cout << "\nenter amount to deposit to the account : ";
				std::cin >> amount_buffer;


				APromisingBank->DepositToAccount(iban_from_buffer, amount_buffer);

				iban_from_buffer.clear();
				break;

			case 10:
				MakeString("\nenter account iban to withdraw from : ", iban_from_buffer);
				MakeString("\nenter account iban to deposit to : ", iban_to_buffer);

				std::cout << "\nenter amount to transfer : ";
				std::cin >> amount_buffer;

				APromisingBank->Transfer(iban_from_buffer, iban_to_buffer, amount_buffer);
				break;

			case 11:
				APromisingBank->DisplayBank();
				break;

			case 0:
				DisplayMenu();
				break;

			case 12:
				//this is the exit condition
				break;

			default :
				DisplayMenu();
				break;
		}


	} while (command != 12);



	std::cout << "Bye, come again soon!\n";

	Bank* someOtherBank = new Bank(*APromisingBank);

	someOtherBank->DisplayBank();

	/*free dynamic memory*/
	delete APromisingBank;
	delete someOtherBank;

	std::cin.ignore();
	std::cin.get();
	return 0;
}