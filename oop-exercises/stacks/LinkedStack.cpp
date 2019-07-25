#include <iostream>
#include "LinkedStack.h"


/*		class LinkedStack mehtods definition		*/

/*		constructors and destructor		*/

LinkedStack::LinkedStack()
	//_empty stack, setting the top to null
	:	m_stackTop(nullptr)
{
}

LinkedStack::LinkedStack(const LinkedStack& otherLinked) {

	if (otherLinked.m_stackTop != nullptr) {

		ElementNode* toCopy = otherLinked.m_stackTop;
		ElementNode* nodeNew = nullptr;					//to create new node
		ElementNode* prevNode = nullptr;				//to move the nextNode pointer(prevNode is a link to it)

		nodeNew = new ElementNode();

		nodeNew->m_Data = toCopy->m_Data;
		nodeNew->m_nextNode = nullptr;

		m_stackTop = nodeNew;
		prevNode = m_stackTop;
		//prevNode = m_stackTop = nodeNew;

		toCopy = toCopy->m_nextNode;

		while (toCopy != nullptr) {
			nodeNew = new ElementNode();

			nodeNew->m_Data = toCopy->m_Data;
			nodeNew->m_nextNode = nullptr;		//eventually setting the last pointer to nullptr

			prevNode->m_nextNode = nodeNew;		//moving the nextNode pointer to the newly created node
			prevNode = nodeNew;					//moving prevNode to current one

			toCopy = toCopy->m_nextNode;
		}
	}

	else {
		//otherLinked is an empty stack
		m_stackTop = nullptr;
	}

}


LinkedStack::~LinkedStack() {

	if (m_stackTop != nullptr) {
		ElementNode* toDelete;
		while (m_stackTop != nullptr) {
			toDelete = m_stackTop;					
			m_stackTop = m_stackTop->m_nextNode;	//moving the stack top to the previous node
			delete toDelete;						//free old node memory
		}											
	}
}

LinkedStack& LinkedStack::operator=(const LinkedStack& otherLinked) {

	if (this != &otherLinked) {

		if (otherLinked.m_stackTop != nullptr) {
			ElementNode* toCopy = otherLinked.m_stackTop;
			ElementNode* nodeAdd = nullptr;
			ElementNode* prevNode = nullptr;

			nodeAdd = new ElementNode();

			nodeAdd->m_Data = toCopy->m_Data;
			nodeAdd->m_nextNode = nullptr;

			m_stackTop = nodeAdd;
			prevNode = m_stackTop;

			toCopy = toCopy->m_nextNode;

			while (toCopy != nullptr) {
				nodeAdd = new ElementNode();

				nodeAdd->m_Data = toCopy->m_Data;
				nodeAdd->m_nextNode = nullptr;

				prevNode->m_nextNode = nodeAdd;
				prevNode = nodeAdd;

				toCopy = toCopy->m_nextNode;
			}

		}

		else {
			deleteStack();
			//m_stackTop = nullptr; no need for that
		}
	}


	// TODO: insert return statement here
	return *this;
}

void LinkedStack::deleteStack() {
	if (m_stackTop != nullptr) {
		ElementNode* toDelete;
		while (m_stackTop != nullptr) {
			toDelete = m_stackTop;
			m_stackTop = m_stackTop->m_nextNode;	//moving the stack top to the previous node
			delete toDelete;						//free old node memory
		}
	}
}

/*access functions*/
bool LinkedStack::isEmpty() const {
	return (m_stackTop == nullptr);
}

float LinkedStack::peekTop() const {
	if (m_stackTop == nullptr) {
		std::cout << "No peeking the empty stack!\n";
		return -1.0f;
	}
	//dereferencing the pointer and returning m_Data
	return m_stackTop->m_Data;
}

/*pop and push functions*/
float LinkedStack::popOut() {

	if (m_stackTop == nullptr) {
		std::cout << "Nothing to pop out!\n";
		return -1.0f;
	}

	ElementNode* nodeRmove = m_stackTop;

	float tempData = m_stackTop->m_Data;
	m_stackTop = m_stackTop->m_nextNode;	//moving the stack top to the previous node
	delete nodeRmove;						//free old node memory

	return tempData;
}

void LinkedStack::pushIn(float otherData) {
	
	//create new node
	ElementNode* nodeAdd = new ElementNode();

	nodeAdd->m_Data = otherData;
	nodeAdd->m_nextNode = m_stackTop;

	//setting the stackTop
	m_stackTop = nodeAdd;

}