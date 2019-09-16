#pragma once

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <stdexcept>

class String
{
public:
	String();
	String(const String& other);
	String(const char* str);

	~String();

	String& operator=(const String& other);

	// element access
	char& At(int index);
	char& operator[](int index);
	char& Front();
	char& Back();
	char* Data();

	const char& At(int index) const;
	const char& operator[](int index) const;
	const char& Front() const;
	const char& Back() const;
	const char* Data() const;

	const char* CStr() const;

	// capacity and size
	bool Empty() const;
	int Length() const;
	int Size() const;
	int Capacity() const;

	// operations
	void Clear();
	//void Insert(size_t index, char symbol);
	//void insert(size_t index, size_t count, char symbol);
	//void Erase(size_t index);
	void PushBack(char symbol);
	void PopBack(char symbol);
	void Append(char symbol);

	// operators overload
	bool operator==(const String& right);

	//friend methods
	friend std::ostream& operator<<(std::ostream& outStream, const String& str);

private:
	void ClearContents();
	void DefaultAllcocate();
	void CopyOtherString(const String& other);

	void Grow();

	bool Full() const;

private:
	const int M_CAPACITY_DEFAULT = 15;

private:
	int m_capacity;			// maximux possible length in bytes excluding \0
	int m_length;			// current length in bytes excluding \0
	char* m_data;
};


#endif // !STRING_H
