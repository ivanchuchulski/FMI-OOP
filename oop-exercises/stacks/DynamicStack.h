#pragma once
class DynamicStack {

/*private members*/
private:

	static const int MAX_SIZE = 20;
	int m_stackTop;
	int m_Size;
	float* m_Data;

/*private member functions*/
private:
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
	bool isFull() const;
	float peekTop() const;

	/*mutator functions*/
	float popOut();
	void pushIn(float elem);




};