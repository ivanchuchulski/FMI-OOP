#include "Store.h"

#include <cstring>


Store::Store()
	:	m_capacity(M_CAPACITY_DEFAULT),
		m_top(-1),
		m_mices(nullptr)
{
	m_mices = new ComputerMouse[m_capacity] {};
}

Store::Store(int storeCapacity)
	:	m_capacity((storeCapacity > 0) ? storeCapacity : M_CAPACITY_DEFAULT),
		m_top(-1),
		m_mices(nullptr)
{
	m_mices = new ComputerMouse[m_capacity] {};
}

Store::Store(const Store& otherStore)
	:	m_capacity(otherStore.m_capacity),
		m_top(-1),
		m_mices(nullptr)
{
	m_mices = new ComputerMouse[m_capacity] {};

	for (int i = 0; i < otherStore.CurrentSize(); i++)
		AddProduct(otherStore.m_mices[i]);
}

Store::~Store() 
{
	if (m_mices != nullptr) 
	{
		delete[] m_mices;
		m_mices = nullptr;
	}
}

Store& Store::operator=(const Store& otherStore) 
{
	if (this != &otherStore) 
	{
		Clear();

		m_capacity = otherStore.m_capacity;
		m_mices = new ComputerMouse[m_capacity] {};

		for (int i = 0; i < otherStore.CurrentSize(); i++)
			AddProduct(otherStore.m_mices[i]);
	}

	return *this;
}


bool Store::Empty() const
{
	return m_top == -1;
}

bool Store::Full()
{
	return m_top == m_capacity - 1;
}

int Store::CurrentSize() const
{
	return m_top + 1;
}

void Store::GrowList() 
{
	m_capacity += 5;
	ComputerMouse* newMices = new ComputerMouse[m_capacity] {};

	for (int k = 0; k < CurrentSize(); k++)
		newMices[k] = m_mices[k];

	delete[] m_mices;
	m_mices = newMices;
}

void Store::Clear()
{
	delete[] m_mices;
	m_mices = nullptr;

	m_capacity = M_CAPACITY_DEFAULT;
	m_top = -1;
}

int Store::FindBySKU(const char* someSKU) const 
{
	for (int i = 0; i < CurrentSize(); i++) 
	{
		if (strcmp(m_mices[i].GetSKU(), someSKU) == 0) 
		{
			return i;
		}
	}

	return -1;
}

void Store::InputProductFromUser()
{
	if (Full())
	{
		GrowList();
	}

	std::cin >> m_mices[++m_top];
}

void Store::AddProduct(const ComputerMouse& compMouse)
{
	if (Full())
	{
		GrowList();
	}

	m_mices[++m_top] = compMouse;
}

void Store::DeleteProduct() 
{
	if (Empty()) 
	{
		std::cout << "nothing to delete, the store is empty\n";
		return;
	}

	const int SKU_SIZE = ComputerMouse::GetSKULen();
	char* skuToFind = new char[SKU_SIZE + 1];

	std::memset(skuToFind, '\0', SKU_SIZE + 1);

	std::cout << "Deleting a product ...\n";
	std::cout << "Enter a SKU of a product to delete : ";

	std::cin.getline(skuToFind, SKU_SIZE);

	int indexFound = FindBySKU(skuToFind);

	if (indexFound == -1) 
	{
		std::cout << "No product with such SKU found!\n";
		return;
	}

	//shifting all the object after the one to delete by one position backward
	for (int i = indexFound + 1; i < CurrentSize(); i++)
		m_mices[i - 1] = m_mices[i];


	//setting the object of the top to a default one
	m_mices[m_top] = ComputerMouse();
	m_top--;

	std::cout << "Product removal success\n";

	delete[] skuToFind;
}

void Store::ChangeProduct() 
{
	if (Empty()) 
	{
		std::cout << "nothing to change, the store is empty\n";
		return;
	}

	const int SKU_SIZE = ComputerMouse::GetSKULen();
	char* skuToFind = new char[SKU_SIZE + 1];

	std::memset(skuToFind, '\0', SKU_SIZE + 1);

	std::cout << "Modifying a product ...\n";
	std::cout << "enter a SKU of a product to delete : ";
	std::cin.getline(skuToFind, SKU_SIZE);

	int indexFound = FindBySKU(skuToFind);

	if (indexFound == -1)
	{
		std::cout << "No such SKU found!\n";
		return;
	}

	m_mices[indexFound].ModifyMouse();

	std::cout << "Product changed successfuly\n";
}

void Store::Print() const 
{
	if (Empty())
	{
		std::cout << "noting to print, the store is empty\n";
		return;
	}

	std::cout << "Printing the products in the store : \n";

	for (int i = 0; i < CurrentSize(); i++) 
	{
		std::cout << "Product " << i << " : \n";
		std::cout << m_mices[i] << std::endl;
	}
}