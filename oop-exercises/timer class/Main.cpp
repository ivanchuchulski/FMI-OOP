#include <iostream>
#include "Timer.hpp"



int main() {

	{
		Timer t1{};

		for (int i = 0; i < 50; i++)
		{
			if (i % 2 == 0)
				std::cout << t1 .GetTime() << "ms\n";
			else
				std::cout << "opa\n";
		}



	}




	std::cin.get();
	return 0;
}