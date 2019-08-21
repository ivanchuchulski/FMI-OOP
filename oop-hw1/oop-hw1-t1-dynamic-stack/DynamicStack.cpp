#include "DynamicStack.h"

#include <iostream>


DynamicStack::DynamicStack()
	:	m_stackTop(-1),
		m_size(MAX_SIZE)
		m_data(nullptr)
{
	m_data = new int[m_size];

	for (int i = 0; i < m_size; i++)
		m_data[i] = 0;
}

DynamicStack::DynamicStack(const DynamicStack& other)
	:	m_stackTop(other.m_stackTop),
		m_size(other.m_size),
		m_data(nullptr)
{
	m_data = new int[m_size];

	for (int i = 0; i < m_size; ++i)
		m_data[i] = other.m_data[i];
}

DynamicStack::~DynamicStack() 
{
	Clear();
}

DynamicStack& DynamicStack::operator=(const DynamicStack& other) 
{
	if (this != &other) 
	{
		Clear();
		CopyOtherStack(other);
	}

	return *this;
}


void DynamicStack::Clear()
{
	delete[] m_data;

	m_stackTop = -1;
	m_size = 0;
	m_data = nullptr;
}


bool DynamicStack::IsEmpty() const 
{
	return m_stackTop == -1;
}

int DynamicStack::PeekTop() const 
{
	if (IsEmpty()) 
	{
		std::cout << "Do not peek the empty stack!\n";
		return -1;
	}

	return m_data[m_stackTop];
}

int DynamicStack::PopOut() 
{
	if (IsEmpty()) 
	{
		std::cout << "Stack is empty, can not pop!\n";
		return -1;
	}

	return m_data[m_stackTop--];
}

void DynamicStack::PushIn(int elem) 
{
	if (IsFull()) 
		GrowStack();

	m_data[++m_stackTop] = elem;
}

bool DynamicStack::IsFull() const 
{
	return m_stackTop == m_size - 1;
}

void DynamicStack::CopyOtherStack(const DynamicStack& other)
{
	m_data = new int[other.m_size];

	m_size = other.m_size;
	m_stackTop = other.m_stackTop;

	for (int i = 0; i < m_size; ++i) 

		m_data[i] = other.m_data[i];
}

void DynamicStack::GrowStack() 
{
	int newSize = m_size * 2;
	int* newData = new int[newSize];

	for (int i = 0; i < newSize; i++)
		newData = 0;

	for (int i = 0; i < m_size; i++)
		newData[i] = m_data[i];

	delete[] m_data;			//freeing up memory

	m_data = newData;			//assigning the new array, and increasing m_size
	m_size = newSize;
}