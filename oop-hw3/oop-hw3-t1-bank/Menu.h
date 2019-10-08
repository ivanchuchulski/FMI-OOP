#pragma once

#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

class Menu
{
public:
	Menu() = default;
	Menu(std::vector<int> legalCommands);
	Menu(const Menu&) = default;
	~Menu() = default;
	Menu& operator=(const Menu&) = default;

	void ShowMenu() const;

	int GetCommand() const;

private:
	int SafetyInputIntegerInBounds(const int lowerBound, const int upperBound) const;

private:
	std::vector<int> m_legalCommands;
};


#endif // !MENU_H






