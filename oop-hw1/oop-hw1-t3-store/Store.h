#pragma once

#ifndef STORE_H
#define STORE_H

#include "Mouse.h"

// implements a container with LIFO-like principle on insertion and with random place removal
//		insertion : amortized O(1)
//		removal : O(N), N - current number of entries in the container
class Store 
{
public:
	Store();
	Store(int storeCapacity);
	Store(const Store& otherStore);
	~Store();

	Store& operator=(const Store& otherStore);

	bool Empty() const;
	int CurrentSize() const;

	void InputProductFromUser();
	void AddProduct(const ComputerMouse& compMouse);

	void DeleteProduct();

	void ChangeProduct();

	void Print() const;

private:
	bool Full();
	void GrowList();
	void Clear();

	//returns first found index, or -1 on no match 
	int FindBySKU(const char* sku) const;

private:
	int m_capacity;
	int m_top;
	ComputerMouse* m_mices;

private:
	const int M_CAPACITY_DEFAULT = 5;
};

#endif // !STORE_H




