#pragma once

#ifndef MENU_H
#define MENU_H

#include <string>


class Menu
{
public:
	Menu() = default;
	Menu(std::string legalCommands);
	Menu(const Menu&) = default;
	~Menu() = default;

	Menu& operator=(const Menu&) = default;

	void ShowMenu();

	char GetCommand();

private:
	char ConvertToUpperCase(char symbol);
	char ExtractSymbol();

	bool LegalCommand(char symbol);

private:
	std::string m_LegalCommands;

};


#endif // !MENU_H






