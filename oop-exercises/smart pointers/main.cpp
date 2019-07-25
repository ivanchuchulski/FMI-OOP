#include <iostream>
#include <memory>

#include "unique_ptr.h"

template<bool GateLevel, typename T>
void Gate();

template<>
void Gate<true, int>() = delete;

//can use the namespace here also
namespace spn
{
	constexpr void SomeFunc();

}

int main() {

	//Gate<true, int>();

	{
		spn::Unique_ptr<int> p1 = new int(78);

		//vtn::unique_ptr<int> p2 = new int[10] { 1 };		// memory leak in the destruction !
		//p2 = p1;

		std::unique_ptr<int[]> sp1(new int[10]{ 1 });

	//	std::unique_ptr<int[]> sp1 = std::make_unique(*(new int[10]{ 1 }));
	}




	std::cin.get();
	return 0;
}