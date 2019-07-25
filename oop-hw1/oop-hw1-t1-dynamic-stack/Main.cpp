#include <iostream>
#include <string.h>
#include "DynamicStack.h"


int ascii_To_int(char sym) {
	if (sym >= '0' && sym <= '9') {
		return (sym - '0');
	}
}

int strLen(const char* srce) {
	int counter = 0;

	if (srce == nullptr) {
		return 0;
	}
	while (*srce != '\0') {
		srce++;
		counter++;
	}
	return counter;
}

int getArgsNum(char oper) {

	switch (oper) {
		case '+':
			return 2;
		case '-':
			return 2;
		case '*':
			return 2;
		case '/':
			return 2;
		case '%':
			return 2;
	default:
		return 2;
	}
}

int calculate(char* expr, int len, DynamicStack& numStack) {

	int result = 1;
	int argsNum = 0;
	int numsPushed = 0;

	int firstOperand = 0;
	int secondOperand = 0;

	const char separation = ' ';
	int moreThanOneDigit = 0;
	int digitCounter = 0;

	for (int i = 0; i < len; i++) {

		//if the char is operator
		if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '%') {
			argsNum = getArgsNum(expr[i]);

			if (argsNum > numsPushed) {
				//numsPushed is 0,1
				std::cout << "Error, not enough operands!\n";
				return 0;
			}


			secondOperand = numStack.popOut();
			firstOperand = numStack.popOut();
			numsPushed -= 2;

			//evaluate the operator
			switch (expr[i]) {
			case '+':
				result = firstOperand + secondOperand;
				break;
			case '-':
				result = firstOperand - secondOperand;
				break;
			case '*':
				result = firstOperand * secondOperand;
				break;
			case '/': {
				if (secondOperand == 0) {
					std::cout << "Error, division by zero !\n";
					return 0;
				}
				else {
					result = firstOperand / secondOperand;
					break;
				}
			}
			case '%': {
				if (secondOperand == 0) {
					std::cout << "Error, modulus division by zero!\n";
					return 0;
				}
				else {
					result = firstOperand % secondOperand;
					break;
				}
			}
			}
			//putting back the result in
			numStack.pushIn(result);
			numsPushed++;
		}

		//if the first one is a space
		else if (i == 0 && expr[i] == separation) {
			for (int k = i + 1; expr[k] != separation; k++, i = k) {
				moreThanOneDigit = 10 * moreThanOneDigit + ascii_To_int(expr[k]);
			}
			numStack.pushIn(moreThanOneDigit);
			numsPushed++;
			moreThanOneDigit = 0;				//nullifying for next iteration
		}

		//the char is number => we have to put it in the stack
		else if (expr[i] >= '0' && expr[i] <= '9') {
			for (int k = i; expr[k] != separation; k++, i = k) {
				moreThanOneDigit = 10 * moreThanOneDigit + ascii_To_int(expr[k]);
			}
			numStack.pushIn(moreThanOneDigit);
			numsPushed++;
			moreThanOneDigit = 0;				//nullifying for next iteration
		}
	}

	//check if there is more numbers, after the last operator
	if (numsPushed > 1) {
		std::cout << "Incorrect expression!\n";
		return 0;
	}

	return result;
}


int main() {

	const char OPERATORS_ARR[6] = { '+', '-', '*', '/', '%', '\0' };
	char userInput[101];	
	DynamicStack numberStack = DynamicStack();

	/*some sample inputs*/
	//char sampleInput0[] = { " 5 1 2 + 4 * + 3 -" };
	//char sampleInput1[] = { "3 10 + 6 *" };
	//char sampleInput2[] = { " 10 3 + 6 *" };


	memset(userInput, '\0', 101);		//nullify the array

	/*	get userInput	*/
	std::cout << "Enter an expression in RPN:\n!Surround two or more digit numbers with spaces please!\n";
	std::cin.getline(userInput, 101);

	int exprLen = strLen(userInput);
	bool emptyInput = false;
	bool hasOperators = false;
	bool hasNumbers = false;

	/*	input handling	*/
	if (exprLen == 0) {
		emptyInput = true;
	}
	else {
		for (int j = 0; j < exprLen; ++j) {
			//check for numbers
			if (userInput[j] >= '0' && userInput[j] <= '9') {
				hasNumbers = true;
			}
			//check for operators
			else if (userInput[j] == OPERATORS_ARR[0]	||		//checking for +
					 userInput[j] == OPERATORS_ARR[1]	||		//checking for -
					 userInput[j] == OPERATORS_ARR[2]	||		//checking for *
					 userInput[j] == OPERATORS_ARR[3]	||		//checking for /
					 userInput[j] == OPERATORS_ARR[4])			//checking for %
			{
				hasOperators = true;
			}
		}
	}

	if (emptyInput == true) {
		std::cout << "Wrong input, empty string!\n";
		return 0;
	}
	if (hasNumbers == false) {
		std::cout << "Wrong input, no numbers!\n";
		return 0;
	}
	else if (hasOperators == false) {
		std::cout << "Wrong input, no operators!\n";
		return 0;
	}

	int result  = calculate(userInput, exprLen, numberStack);
	std::cout << "Result = " << result << '\n';

	/*ending to keep window open*/
//	std::cin.get();
	return 0;
}