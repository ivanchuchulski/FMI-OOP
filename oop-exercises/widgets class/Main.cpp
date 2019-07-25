#include <iostream>
#include <functional>		// std::invoke
#include <fstream>

#include "Widget.h"
#include "WidgetInit.h"


class C
{
private:
	int i;
public:

	explicit C(int integer)
		:	i{integer}
	{}

	explicit C()
		:	i{}
	{}

	C(const C& other)
		:	i{other.i}
	{}

	C& operator=(const C& other)
	{
		if (this != &other)
			i = other.i;

		return *this;
	}

	~C()
	{}


};

// Main---------------------------------------
int main() {

	{

		//auto& wig1 = *GetAWidgetPtr(1);		//memory leak
		//
		//auto wig2{ GetAWidgetPtr(0) };		// potential memory leak

		//wig2->PrintName();

		//// free memory after use
		//delete wig2;


			//	auto wid3{ GetAWidgetWorse(1) };


		//Widget w{};

		//void (Widget::*PrintPtr)() const = &Widget::PrintName;

		//std::invoke(PrintPtr, w);
		//(w.*PrintPtr)();
	}


		std::ofstream myfile1 ("test1.txt", std::ios::out);

		Widget w1{"w1"};

		if (myfile1.is_open())
		{
			myfile1 << w1;
		}
		
		else
		{
			std::cout << "opa\n";
		}

		//free resources
		myfile1.close();


		C c1{};



	std::cin.get();
	return 0;
}