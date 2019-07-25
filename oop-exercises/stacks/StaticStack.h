#pragma once



class StaticStack {

/*private member variables*/
private:

	int m_stackTop;
	static const int MAX_SIZE = 20;		//stack size constant
	float m_Data[MAX_SIZE];

/*public member functions*/
public:

	/*constructors and destructor*/
	StaticStack();
//	StaticStack(float* otherArr);
	StaticStack(const StaticStack& otherStack);
	~StaticStack();

	/*copy assignment operator*/
	StaticStack& operator=(const StaticStack& otherStack);

	/*access functions*/
	bool isEmpty() const;
	bool isFull() const;
	float peekTop() const;

	/*mutator functions*/
	float popOut();
	void pushIn(float elem);


};

