#include <iostream>
#include "StaticStack.h"
#include "DynamicStack.h"
#include "LinkedStack.h"

int main() {


	StaticStack s1 = StaticStack();
	StaticStack s2 = StaticStack(s1);

	DynamicStack dyn1 = DynamicStack();
	DynamicStack dyn2 = DynamicStack(dyn1);

	LinkedStack l1 = LinkedStack();

	for (float k = 5.0f; k < 11.0f; ++k) {
		l1.pushIn(k);
	}

	LinkedStack l2 = LinkedStack(l1);
	LinkedStack l3 = LinkedStack();
	LinkedStack l4 = LinkedStack();

	l3 = l4;
	l3 = l1;

	std::cin.get();
	return 0;
}