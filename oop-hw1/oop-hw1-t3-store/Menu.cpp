#include "Menu.h"

#include <iostream>
#include <cstring>

Menu::Menu(std::string legalCommands)
	: m_LegalCommands(legalCommands)
{}

char Menu::ConvertToUpperCase(char symbol)
{
	if (symbol >= 'a' && symbol <= 'z')
		return symbol - ('a' - 'A');

	return symbol;
}


char Menu::ExtractSymbol()
{
	char response;

	std::cout << "Enter a command  : ";

	std::cin >> response;
	std::cin.get();

	return ConvertToUpperCase(response);
}

bool Menu::LegalCommand(char symbol)
{
	for (char cmd : m_LegalCommands)
	{
		if (cmd == symbol)
			return true;
	}

	return false;
}

void Menu::ShowMenu()
{
	std::cout << "\n\t\t###### Computer Mice Shop ######";

	std::cout << "\n\tA \tAdd a new mouse";
	std::cout << "\n\tX \tDelete a mouse";
	std::cout << "\n\tC \tUpdate a mouse spec";
	std::cout << "\n\tD \tDisplay the mice in the shop";

	std::cout << "\n\t? \tShow the menu";
	std::cout << "\n\tQ \tQuit\n";
}

char Menu::GetCommand()
{
	char userCommand = ExtractSymbol();

	while (!LegalCommand(userCommand))
	{
		std::cout << "Illegal command, please enter again";
		ShowMenu();
		userCommand = ExtractSymbol();
	}

	return userCommand;
}










