/*

	->	fn : 62167
	->	compiler : Visual C++

*/

/*
	_> from the task we can deduce the following :
		friend methods are NOT INHERITED, but can be called (by implicit Type conversion) if : 
			there is no implementation of the same operator as a friend or as a normal in the derived class

*/

#include <iostream>
#include "Building.h"
#include "Block.h"

int main() {


	Building oneBuilding = Building(150, 10);
	//std::cout << oneBuild;

	Block ZeroBlock = Block();
	Block FirstBlock = Block(400, 10, 25, "Vitosha 200");

	++oneBuilding;
	++FirstBlock;

	Building& baseRef_ZeroBlock = ZeroBlock;
	Building& baseRef_FirstBlock = FirstBlock;

//	ZeroBlock.Building::operator<((Building&)FirstBlock);
//	ZeroBlock.Building::operator<(FirstBlock);


	//calling the base operator < by the references
	baseRef_ZeroBlock < baseRef_FirstBlock;		

	//calling the < in the derived class
	ZeroBlock < FirstBlock;

	//ZeroBlock.operator>(FirstBlock);		//cant call, there is no such member in the Block
	(Building&)ZeroBlock > ((Building&)FirstBlock);
	ZeroBlock > FirstBlock;

	std::cout << ZeroBlock;

	std::cin.get();
	return 0;
}