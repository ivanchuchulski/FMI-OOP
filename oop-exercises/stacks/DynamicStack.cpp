#include <iostream>
#include "DynamicStack.h"

/*		DynamicStack methods definitios		*/
#pragma region

/*ctors and dtor*/#pragma region
DynamicStack::DynamicStack()
	:	m_stackTop(-1),
		m_Size(MAX_SIZE)
{
	//dynamicly allocate the m_Data array
	m_Data = new float[m_Size];
	//nullifying the m_Data array
	int i = 0;
	for (i = 0; i < MAX_SIZE; ++i) {
		m_Data[i] = 0.0f;
	}
}

DynamicStack::DynamicStack(const DynamicStack& otherDynStack) 
	:	m_stackTop(otherDynStack.m_stackTop),
		m_Size(otherDynStack.m_Size)
{
	//m_Data = new float[m_Size] {*(otherDynStack.m_Data)};
	m_Data = new float[m_Size];

	for (int i = 0; i < m_Size; ++i) {
		m_Data[i] = otherDynStack.m_Data[i];
	}
}

DynamicStack::~DynamicStack() {
	if (m_Data != nullptr) {
		//free memory if needed
		delete[] m_Data;
	}
}
#pragma endregion

/*copy assignment operator*/
DynamicStack& DynamicStack::operator=(const DynamicStack& otherDynStack) {

	if (this != &otherDynStack) {
		if (m_Data != nullptr) {
			//free memory if needed
			delete[] m_Data;
		}

		m_Data = new float[otherDynStack.m_Size];
		m_Size = otherDynStack.m_Size;
		m_stackTop = otherDynStack.m_stackTop;

		for (int i = 0; i < m_Size; ++i) {
			m_Data[i] = otherDynStack.m_Data[i];
		}
	}
	// TODO: insert return statement here
	return *this;
}

/*growStack function*/
void DynamicStack::growStack() {

	float* newData = new float[m_Size * 2];
	int i = 0;
	for (i = 0; i < m_Size; ++i) {
		newData[i] = m_Data[i];
	}
	//freeing up memory
	delete[] m_Data;
	//assigning the new array, and increasing m_Size
	m_Data = newData;
	m_Size *= 2;

}

/*accessor functions*/#pragma region
bool DynamicStack::isEmpty() const {
	return (m_stackTop == -1);
}

bool DynamicStack::isFull() const {
	return (m_stackTop == m_Size - 1);
}

float DynamicStack::peekTop() const {
	if (m_stackTop == -1) {
		std::cout << "Do not peek the empty stack!\n";
		return -1.0f;
	}
	return m_Data[m_stackTop];
}
#pragma endregion

/*mutator functions*/#pragma region
float DynamicStack::popOut() {
	if (m_stackTop == -1) {
		std::cout << "Stack is empty, can not pop!\n";
		return -1.0f;
	}
	else {
		return m_Data[m_stackTop--];
	}
}

void DynamicStack::pushIn(float elem) {
	if (m_stackTop == (MAX_SIZE - 1)) {
		//grow the stack
		growStack();
	}
	//assign
	m_Data[++m_stackTop] = elem;
}
#pragma endregion


#pragma endregion
