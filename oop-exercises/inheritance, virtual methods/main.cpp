#include <iostream>

class Base {

private:
	int m_BaseData;

public:

	//ctor
	Base() 
		:	m_BaseData(0)
	{
		std::cout << "Base ctor\n";
	};
	//dtor
	virtual ~Base() {
		std::cout << "Base dtor\n";
	}

	virtual void PrintFunc() const {
		std::cout << "Hello from the Base class !\n";
	}

	void AnotherFunc() const {
		std::cout << "This is another from the Base class !\n";
	}

};

class ChildOne : public Base
{
private:
	int m_ChildData;

public:
	ChildOne()
		:	Base(),
			m_ChildData(10)
	{
		std::cout << "Child ctor\n";
	}

	~ChildOne() {
		std::cout << "ChildOne dtor\n";
	}

	void PrintFunc() const override {
		std::cout << "Hello from the ChildOne class !\n";
	}

	void AnotherFunc() const {
		std::cout << "This is another from the Child class !\n";
	}

	void setChildData(int a) {
		m_ChildData = a;
	}

};


int main() {


	ChildOne* child1 = new ChildOne();

	child1->PrintFunc();
	//child1->Base::PrintFunc();		//explicitly call the method in the Base class
	child1->AnotherFunc();

	//polymorphism
	Base* polyChild = new ChildOne();

	polyChild->PrintFunc();
	polyChild->AnotherFunc();


	Base* const b = child1;
	b->AnotherFunc();


	/*free memory*/
	delete polyChild;
	delete child1;

	std::cin.get();
	return 0;
}