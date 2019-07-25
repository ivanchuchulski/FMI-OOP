#include <string.h>
#include "Store.h"



/*class Store methods definitions*/
#pragma region

/*method to find a product, by a given unique ID*/
int Store::FindBySKU(char* someSKU) const {

	for (int i = 0; i < m_MiceCount; i++) {
		//searching for a match in the MiceList
		if (strcmp(m_MiceList[i].getSKU(), someSKU) == 0) {
			return i;
		}
	}

	//if the loop search did not find any matches
	return -1;

}

/*method to increase the size of the array*/
void Store::GrowList() {
	m_MaxSize += 5;		//increase max size
	Mouse* bufferList = new Mouse[m_MaxSize];

	//copying from current list
	for (int k = 0; k < m_MiceCount; k++) {
		bufferList[k] = m_MiceList[k];
	}

	delete[] m_MiceList;			//free memory
	m_MiceList = bufferList;		//assign pointer to the newly created block of memory
}

/*default ctor*/
Store::Store()
	:	m_MaxSize(5),
		m_MiceCount(0),
		m_MiceList(nullptr)
{
	m_MiceList = new Mouse[m_MaxSize];
}

/*ctor with parameters*/
Store::Store(int N)
	:	m_MaxSize(5),
		m_MiceCount(0),
		m_MiceList(nullptr)
{
	if (N > 0) {
		m_MaxSize = N;
		m_MiceList = new Mouse[m_MaxSize];
	}
	else {
		m_MiceList = new Mouse[m_MaxSize];
	}
}

/*copy ctor*/
Store::Store(const Store& otherStore)
	:	m_MaxSize(otherStore.m_MaxSize),
		m_MiceCount(otherStore.m_MiceCount),
		m_MiceList(nullptr)
{
	m_MiceList = new Mouse[m_MaxSize];
	//copying from the other store
	for (int i = 0; i < m_MiceCount; i++) {
		m_MiceList[i] = otherStore.m_MiceList[i];
	}
}

/*destructor*/
Store::~Store() {
	//calls the destructor for each Mouse object in the list
	if (m_MiceList != nullptr) {
		delete[] m_MiceList;
		m_MiceList = nullptr;
	}
}

/*copy assignment*/
Store& Store::operator=(const Store& otherStore) {

	if (this != &otherStore) {
		//free current memory if needed
		if (m_MiceList != nullptr) {
			delete[] m_MiceList;
			m_MiceList = nullptr;
		}

		m_MaxSize = otherStore.m_MaxSize;
		m_MiceCount = otherStore.m_MiceCount;
		m_MiceList = new Mouse[m_MaxSize];

		//copying from the other store
		for (int i = 0; i < m_MiceCount; i++) {
			m_MiceList[i] = otherStore.m_MiceList[i];
		}
	}
	// TODO: insert return statement here
	return *this;
}



/*method to get user input*/
void Store::InputProduct() {
	//check if the list needs to grow
	if (m_MiceCount == m_MaxSize) {
		GrowList();
	}

	//get input from the console
	std::cin >> m_MiceList[m_MiceCount];
	m_MiceCount++;
}

void Store::DeleteProduct() {
	//check
	if (m_MiceCount == 0) {
		std::cout << "The store is empty!\n";
		return;
	}

	else {
		char toFindSKU[20];

		std::cout << "\nEnter a SKU of a product to delete : ";
		std::cin.getline(toFindSKU, 20);

		int foundIndex = FindBySKU(toFindSKU);

		if (foundIndex == -1) {
			std::cout << '\t' << "No such SKU found!\n";
		}

		else {
			for (int i = foundIndex + 1; i < m_MaxSize; i++) {
				m_MiceList[i - 1] = m_MiceList[i];
			}
			m_MiceCount--;
			std::cout << "\t Product removed!\n";
		}
	}
}

/*Modifying method*/
void Store::ChangeProduct() {

	//check
	if (m_MiceCount == 0) {
		std::cout << "The store is empty!\n";
		return;
	}
	else {
		char toFindSKU[20];

		std::cout << "\nEnter a SKU of a product to change : ";
		std::cin.getline(toFindSKU, 20);

		int foundIndex = FindBySKU(toFindSKU);

		if (foundIndex == -1) {
			std::cout << '\t' << "No such SKU found!\n";
		}

		else {
			//calling the modify method
			m_MiceList[foundIndex].ModifyMouse();
			std::cout << "\t Product changed!\n";
		}
	}
}

void Store::Print() const {
	//check
	if (m_MiceCount == 0) {
		std::cout << "The store is empty!\n";
		return;
	}
	else {
		std::cout << "Printing the products in the store : \n";

		for (int i = 0; i < m_MaxSize; i++) {
			std::cout << "Product " << i + 1 << " : \n";
			std::cout << m_MiceList[i] << std::endl;
		}
	}

}

#pragma endregion