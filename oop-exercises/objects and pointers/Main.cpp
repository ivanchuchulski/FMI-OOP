#include <iostream>

class Base {

private:
	int m_Data;

public:
	Base();
	Base(int data);
	Base(const Base& otherBase);
	~Base();

	void Print() const;
	void SetData(int data);

};

int main() {


	int BasePtrBufferSize = 3;
	int BaseArrSize = 3;

	Base b1 = Base(1);
	Base b2 = Base(2);
	Base b3 = Base(3);


	void(Base::*ptr)() const = &Base::Print;

	if (ptr == nullptr)
	{
		std::cerr << "Opa\n";
	}


	Base** BasePtrBuffer = new Base*[BasePtrBufferSize];


	BasePtrBuffer[0] = new Base(b1);
	BasePtrBuffer[1] = new Base(b2);
	BasePtrBuffer[2] = new Base(b3);


	for (int i = 0; i < BasePtrBufferSize; i++) {

		std::cout << "Address of the pointer in the Buffer[" << i <<"] = " <<  (BasePtrBuffer[i]) << '\n';
		std::cout << "Address of the Object behind the pointer is";
		BasePtrBuffer[i]->Print();
	//	(*(*(BasePtrBuffer + i))).Print();
	}

	Base* BaseArr = new Base[BaseArrSize];

	for (int j = 0; j < BaseArrSize; j++) {
		BaseArr[j].Print();
	}

	/*free memory*/
	delete[] BaseArr;

	for (int i = 0; i < BasePtrBufferSize; i++) {
		//calling the dtor for each object in the Buffer
		delete BasePtrBuffer[i];
	}
	delete[] BasePtrBuffer;		//deleting the pointers on the heap, pointed by the buffer 

	std::cin.get();
	return 0;
}

/*class Base mehthods definitions*/

Base::Base()
	:m_Data(0)
{}

Base::Base(int data)
	:m_Data(data)
{}

Base::Base(const Base & otherBase)
	:m_Data(otherBase.m_Data)
{}

Base::~Base()
{}

void Base::Print() const
{
	std::cout << this << '\n';
} 

void Base::SetData(int data)
{
	m_Data = data;
}




