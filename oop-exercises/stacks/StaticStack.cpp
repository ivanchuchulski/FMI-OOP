#include <iostream>
#include "StaticStack.h"


/*				StaticStack methods definitions				*/
#pragma region

/*	ctors and dtor	*/#pragma region

	StaticStack::StaticStack()
		//creating an empty stack
		:	m_stackTop(-1), 
			m_Data()		//this seems to nullify the array
	{
		//nullifying the m_Data array
		int i = 0;
		for (i = 0; i < MAX_SIZE; ++i) {
			m_Data[i] = 0.0f;
		}
		//memset(m_Data, 0, MAX_SIZE * sizeof(float));	
	}

	StaticStack::StaticStack(const StaticStack& otherStack)
		:	m_stackTop(otherStack.m_stackTop), 
			m_Data()
	{
		int i = 0;
		if (m_stackTop == -1) {
			//nullify, the other stack if empty
			for (i = 0; i < MAX_SIZE; ++i) {
				m_Data[i] = 0;
			}
		}
		else {
			//copy the data
			for (i = 0; i < m_stackTop; ++i) {
				m_Data[i] = otherStack.m_Data[i];
			}
		}
	}

	StaticStack::~StaticStack()
	{}
#pragma endregion

/*copy assignment operator*/
	StaticStack& StaticStack::operator=(const StaticStack& otherStack) {
		if (this != &otherStack) {
			m_stackTop = otherStack.m_stackTop;
			int i = 0;
			for (i = 0; i < m_stackTop; ++i) {
				m_Data[i] = otherStack.m_Data[i];
			}

		}
		// TODO: insert return statement here
		return *this;
	}

/*	access functions	*/#pragma region

	bool StaticStack::isEmpty() const {
		//check if the top is at the minimum index
		return (m_stackTop == -1);
	}

	bool StaticStack::isFull() const {
		//check if the top is at the maximum index
		return (m_stackTop == MAX_SIZE -1);
	}

	float StaticStack::peekTop() const {
		if (m_stackTop == -1) {
			std::cout << "Do not peek the empty stack !\n";
			return -1.0f;
			}
			//returning the element on the top of the stack
			return m_Data[m_stackTop];
		}
#pragma endregion
	
/*mutator functions*/#pragma region

	float StaticStack::popOut() {

		//if (this->isEmpty() == true) {
		if ( m_stackTop == -1 ) {
			std::cout << "Stack is empty, can not pop!\n";
			return -1.0f;
		}
		else {
			return m_Data[m_stackTop--];
		}
	}

	void StaticStack::pushIn(float elem) {
		//if (this->isFull() == true) {
		if( m_stackTop == (MAX_SIZE -1) ) {
			std::cout << "Stack is full, can not push !\n";
			return;
		}
		else {
			//increenting the stackTop(default is -1) and adding the element
			m_Data[++m_stackTop] = elem;
		}
	}

#pragma endregion
	

#pragma endregion