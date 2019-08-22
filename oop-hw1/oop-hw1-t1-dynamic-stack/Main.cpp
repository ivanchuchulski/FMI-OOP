/*	oop summer 2017-2018
	homework 1 task 1 : calculator for expressions in reverse polish notation
	STL classes are prohibited
*/

#include <iostream>
#include <cstring>

#include "DynamicStack.h"

#define ERR_EMPTY_INPUT 1;
#define ERR_INCORRECT_INPUT 2;
#define ERR_NO_NUMBERS 3;
#define ERR_NO_OPERATORS 4;
#define ERR_ZERO_DIVISION 5;

int AsciiToInt(char sym)
{
	if (sym >= '0' && sym <= '9')
		return (sym - '0');
	else
		return sym;
}

int GetNeededOperandCount(char oper)
{
	switch (oper)
	{
		case '+' :
			return 2;
		case '-':
			return 2;

		case '*' :
			return 2;

		case '/' :
			return 2;

		case '%' :
			return 2;

		default:
			return 2;
	}
}

bool IsNumber(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

bool IsOperator(char symbol, const char* operators, const int size_operators)
{
	for (int i = 0; i < size_operators; i++)
	{
		if (symbol == operators[i])
			return true;
	}

	return false;
}

bool IsSpace(char symbol)
{
	return symbol == ' ';
}

int CalculateExpression(char* expression, int len, DynamicStack& num_stack) 
{
	const char separation = ' ';

	int result = 0;
	int operands_in_stack = 0;

	int first_operand = 0;
	int second_operand = 0;


	for (int i = 0; i < len; i++) 
	{
		if (IsOperator(expression[i]))
		{
			if (GetNeededOperandCount(expression[i]) > operands_in_stack) 
			{
				std::cout << "error : wrong operand count, not enough operands\n";
				return ERR_INCORRECT_INPUT;
			}

			second_operand = num_stack.PopOut();
			first_operand = num_stack.PopOut();
			operands_in_stack -= 2;

			switch (expression[i]) 
			{
				case '+' :
					result = first_operand + second_operand;
					break;

				case '-' :
					result = first_operand - second_operand;
					break;

				case '*' :
					result = first_operand * second_operand;
					break;

				case '/' : 
				{
					if (second_operand == 0) 
					{
						std::cout << "error : division by zero\n";
						return ERR_ZERO_DIVISION;
					}

					result = first_operand / second_operand;
					break;
				}

				case '%' : 
				{
					if (second_operand == 0) 
					{
						std::cout << "error : modulus division by zero\n";
						return ERR_ZERO_DIVISION;
					}

					result = first_operand % second_operand;
					break;
				}
			}

			num_stack.PushIn(result);
			operands_in_stack++;
		}

		else if (IsNumber(expression[i])) 
		{
			int number = 0;

			for (int k = i; expression[k] != separation; k++, i = k)
			{
				number = 10 * number + AsciiToInt(expression[k]);
			}

			num_stack.PushIn(number);
			operands_in_stack++;
		}

		// the last case is spaces
		else
		{
			continue;
		}

	}

	//check if there is more numbers, after the last operator
	if (operands_in_stack > 1) 
	{
		std::cout << "error : not enough operands\n";
		return ERR_INCORRECT_INPUT;
	}

	return result;
}


int main()
{
	const int LEN_OPERATORS_ARR = 5;
	const int MAX_EXPRESSION_LEN = 100;
	const char OPERATORS_ARR[LEN_OPERATORS_ARR + 1] = { '+', '-', '*', '/', '%', '\0' };
	char expression[MAX_EXPRESSION_LEN + 1];
	DynamicStack calculatorStack = DynamicStack();

	std::memset(expression, '\0', 101);		//nullify the array

	// user input
	std::cout << "Enter an expression in RPN:\ncalculator works only with whole numbers\n!Surround two or more digit numbers with spaces\n";
	std::cin.getline(expression, 101);

	int expression_len = std::strlen(expression);
	bool empty_input = false;
	bool has_operators = false;
	bool has_numbers = false;
	bool has_wrong_char = false;

	// error checking
	// RPN expressions don't need braces, they consist only of numbers and arithmetic operators and in our case spaces
	if (expression_len == 0)
	{
		std::cout << "error : wrong input, empty string\n";
		return ERR_INCORRECT_INPUT;
	}

	for (int i = 0; i < expression_len; i++)
	{
		if (IsOperator(expression[i]))
			has_operators = true;

		else if (IsNumber(expression[i]))
			has_numbers = true;

		else if (IsSpace(expression[i]))
			continue;

		else
		{
			has_wrong_char = true;
			break;
		}
	}

	if (has_wrong_char)
	{
		std::cout << "error : wrong input, expression should only contain digits, arithmetic operators and spaces";
		return ERR_INCORRECT_INPUT;
	}

	else if (!has_numbers) 
	{
		std::cout << "error : wrong input, no numbers in the expression\n";
		return ERR_NO_NUMBERS;
	}

	else if (!has_operators) 
	{
		std::cout << "error : wrong input, no operators in the expression\n";
		return ERR_NO_OPERATORS;
	}

	int result = CalculateExpression(expression, expression_len, calculatorStack);

	std::cout << "Result = " << result << '\n';

	// some sample inputs
	//char sampleInput0[] = { " 5 1 2 + 4 * + 3 -" };
	//char sampleInput1[] = { "3 10 + 6 *" };
	//char sampleInput2[] = { " 10 3 + 6 *" };

	return 0;
}
