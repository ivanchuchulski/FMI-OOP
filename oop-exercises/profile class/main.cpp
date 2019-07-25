#include <iostream>

#include "Profile.h"		//also includes <iostream>,<string>
#include "RandomProfile.h"


int main() {



	/*
	{
		const size_t star_size = 5;
		char* star = new char[star_size] { '\n' };
		std::string str1("sdasdad");

		//getline in the std::basic_istream
		std::cin.getline(star, star_size * sizeof(char), '\n');

		//same getline but redefined in the std::string class
		std::getline(std::cin, str1, '\n');

		std::cout << str1 << '\n';

		for (size_t i = 0; i < star_size; i++) {
			std::cout << star[i];
		}

		delete[] star;
	}
	*/

	{

		Profile pr1("jane", "henderson", 1979);
		Profile pr2(0, 0, 1000);

	//	std::cin >> pr1;

		pr1.DisplayInfo();
		float number = 123.123f;

		RandomProfile<float> randprof1(number);
		RandomProfile<float> randprof2;

		randprof2 = randprof1;
	}

//	std::cerr << "Opa\n";



	std::cin.get();
	system("pause");
	return 0;
}