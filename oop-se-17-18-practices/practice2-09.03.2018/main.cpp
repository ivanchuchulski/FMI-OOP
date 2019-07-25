#include <iostream>
#include "Rod.h"

int main() {

	Rod rod2 = Rod(5, true, Wooden, nullptr);		//using overloaded defualt
	Rod rod3 = Rod(rod2);							//using copy constuctor
	Rod	rod1 = Rod();								//using default constructor

//	rod3.setName("Ivo");


	std::cin.get();
	return 0;
}