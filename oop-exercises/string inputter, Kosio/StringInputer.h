#pragma once
#include <iostream>

// Helper class for inputting a variable length C-string
class StringInputer
{
private:
	const float GROW_FACTOR = 1.7f;
	const int INITIAL_CAPACITY = 128;

	char * array;
	int capacity;
	int idx;

	void grow();

public:
	StringInputer();
	~StringInputer();

	char * getString();
};

