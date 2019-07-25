
/*
		->faculty num : 62167
		->OOP_Task1
		->compiler : Visual C++
*/


#include <iostream>
#include "Expression.h"
#include "Const.h"
#include "Var.h"
#include "Sum.h"


int main() {

	{
		Var v1("var1", 10.5);
		Var v2("var2", 9.5);

		Sum s1(v1, v2);

		s1.Print();

	}

	std::cin.get();
	return 0;
}