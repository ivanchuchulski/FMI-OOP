#pragma once


#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H


/*			class DynamicStack definition		*/
class DynamicStack {

/*private members*/
private:

	static const int MAX_SIZE = 50;
	int m_stackTop;
	int m_Size;
	int* m_Data;

/*private member functions*/
private:
	bool isFull() const;
	void growStack();

/*public member functions*/
public:

	/*ctors and dtor*/
	DynamicStack();
	DynamicStack(const DynamicStack& otherDynStack);
	~DynamicStack();

	/*copy assignment operator*/
	DynamicStack& operator=(const DynamicStack& otherDynStack);

	/*access functions*/
	bool isEmpty() const;

	int peekTop() const;

	/*pop and push functions*/
	int popOut();
	void pushIn(int elem);




};

#endif // !DYNAMICSTACK_H


