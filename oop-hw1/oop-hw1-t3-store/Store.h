#pragma once


#ifndef STORE_H
#define STORE_H

#include "Mouse.h"

/*class Store definition*/
class Store {

/*private member data*/
private:
	int m_MaxSize;
	int m_MiceCount;
	Mouse* m_MiceList;

/*private methods*/
private:
	void GrowList();
	int FindBySKU(char* someSKU) const;

/*public methods*/
public:
	/*constructor and destructor*/
	Store();
	Store(int N);
	Store(const Store& otherStore);
	~Store();

	/*copy asssignment operator*/
	Store& operator=(const Store& otherStore);

	void InputProduct();

	void DeleteProduct();

	void ChangeProduct();

	void Print() const;

};

#endif // !STORE_H




