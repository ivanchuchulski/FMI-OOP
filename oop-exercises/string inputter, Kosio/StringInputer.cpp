#include "StringInputer.h"

using namespace std;

void StringInputer::grow()
{
	int newCapacity = this->capacity * GROW_FACTOR + 1;
	char * newArray = new char[newCapacity];
	memcpy(newArray, this->array, capacity);

	delete[] array;
	array = newArray;
	capacity = newCapacity;
}

StringInputer::StringInputer()
{
	array = new char[INITIAL_CAPACITY];
	capacity = INITIAL_CAPACITY;
}


StringInputer::~StringInputer()
{
	delete[] array;
}

char * StringInputer::getString()
{
	char current;
	this->idx = 0;

	bool started = false;

	while (true)
	{
		current = cin.get();
		// skip leading white spaces
		if (!started && current == ' ') continue;
		started = true;

		if (current == '\n') break;

		if (this->idx >= this->capacity - 1) grow(); // if we exceed the current buffer capacity, we make a new one
		this->array[this->idx++] = current;
	}

	char * result = new char[this->idx + 1];
	result[this->idx] = 0;
	memcpy(result, this->array, this->idx);

	return result;
}
