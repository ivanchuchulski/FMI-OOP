#include <iostream>
#include <cstdio>


class Base {
private:
	float m_BaseData;
	float* m_AddrData;
public:

	Base() 
		:	m_BaseData(0.0f),
			m_AddrData(&(m_BaseData))
	{}
	Base(float base_data)
		:	m_BaseData(base_data),
			m_AddrData(&(m_BaseData))
	{}

	virtual ~Base()
	{}

	virtual void PrintInfo() const 
	{
		std::puts("Base Info : ...\n");
	}

};

class FirstChild
	: virtual public Base
{
private:	
	float m_FChild_Data;

public:

	FirstChild()
		:	Base(),
			m_FChild_Data(1.0f)
	{}

	FirstChild(float base_data ,float f_data)
		:	Base(base_data),
			m_FChild_Data(f_data)
	{}

	~FirstChild()
	{}

	void PrintInfo() const override
	{
		std::puts("FirstChild info : ...\n");
	}

	virtual void SomeFunc() const
	{}
};

class SecondChild
	: virtual public Base
{
private:
	float m_SecChild_Data;

public:

	SecondChild()
		:	Base(),
			m_SecChild_Data(1.1f)
	{}

	SecondChild(float base_data, float sec_data)
		:	Base(base_data),
			m_SecChild_Data(sec_data)
	{}

	~SecondChild()
	{}

	void PrintInfo() const override
	{
		std::puts("SecondChild info : ...\n");
	}

	virtual void SomeFunc() const
	{}
};


class GrandChild
	: public FirstChild, public SecondChild
{
private:
	float m_GrandChild_Data;

public:
	GrandChild() 
		//GrandChild is obliged to call the ctor of all virtual classes that has, otherwise, the default ctor will be called
		:	Base(),
			FirstChild(),
			SecondChild(),
			m_GrandChild_Data(2.0f)
	{}

	GrandChild(float base_data, float first_data, float second_data, float grand_data)
		:	Base(base_data),
			FirstChild(base_data, first_data),
			SecondChild(base_data, second_data),
			m_GrandChild_Data(grand_data)

	{}

	~GrandChild()
	{}


	void PrintInfo() const override
	{}

	void SomeFunc() const override
	{}
};


int main() {

	Base b1 = Base();

	FirstChild f1 = FirstChild();
	SecondChild s1 = SecondChild();

	GrandChild g1 = GrandChild(5.0f, 6.0f, 7.0f, 8.0f);

	g1.FirstChild::PrintInfo();
	g1.SecondChild::PrintInfo();
	
	g1.SomeFunc();
	g1.PrintInfo();

	std::puts("Hello with puts!\n");
	std::cin.get();
	return 0;
}