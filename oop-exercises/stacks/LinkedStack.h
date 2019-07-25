#pragma once

class ElementNode {
	friend class LinkedStack;
private:
	float m_Data;
	ElementNode* m_nextNode;
};


/*LinkedStack class definition*/
class LinkedStack {

private:
	ElementNode* m_stackTop;

private:
	void deleteStack();

public:

	/*ctors and dtor*/
	LinkedStack();
	LinkedStack(const LinkedStack& otherLinked);
	~LinkedStack();

	/*copy assignment operator*/
	LinkedStack& operator=(const LinkedStack& otherLinked);

	/*access functions*/
	bool isEmpty() const;
	//bool isFull() const;
	float peekTop() const;

	/*pop and push functions*/
	float popOut();
	void pushIn(float otherData);

};

