#include <iostream>
#include "FloatingNumberber.h"

int main() {

	FloatingNumber pi_num = FloatingNumber(3141592, 10, -6);
	FloatingNumber e_num = FloatingNumber(2718281, 10, -6);

	//initializing with copy constructor
	FloatingNumber num1 = e_num;

	// using operator +
	FloatingNumber num2 = pi_num + e_num;
	 
	std::cout << pi_num << '\n';

	std::cout << e_num << '\n';

	std::cout << num1 << '\n';

	std::cout << num2 << '\n';

	std::cin >> num2;

	std::cout << num2 << '\n';

	std::cout << "PI significant part : " << pi_num.GetSignif() << '\n';

	return 0;
}