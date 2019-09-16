#pragma once

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

template<typename T>
class Vector
{
public:
	Vector();
	Vector(const Vector<T>& other);
	Vector(int count, const T& value);

	~Vector();

	Vector<T>& operator=(const Vector<T>& other);

	// element access
	T& At(int pos);
	T& operator[](int pos);
	const T& operator[](int pos) const;

	T& Front();
	const T& Front() const;

	T& Back();
	const T& Back() const;

	// capacity methods
	bool Empty() const;
	int Size() const;
	int Capacity() const;

	// modifiers
	void Clear();
	//int Insert(int pos, const T& value);
	//void Insert(int pos, int count, const T& value);
	void Erase(int pos);
	void PushBack(const T& value);
	void PopBack();

	// friend methods
	friend std::ostream& operator<<(std::ostream& outStream, const Vector<T>& vec)
	{
		for (int i = 0; i < vec.Size(); i++)
			outStream << vec.m_data[i] << ' ';

		outStream << '\n';

		return outStream;
	}

private:
	void ClearContents();
	void DefaultAllocate();
	void CopyOtherVector(const Vector<T>& other);

	void Grow();

	bool Full() const;

private:
	int M_CAPACITY_DEFAULT = 15;

private:
	int m_capacity;
	int m_size;
	T* m_data;
};

template<typename T>
inline Vector<T>::Vector()
	:	m_capacity(M_CAPACITY_DEFAULT),
		m_size(0),
		m_data(nullptr)
{
	DefaultAllocate();
}

template<typename T>
inline Vector<T>::Vector(const Vector<T>& other)
	:	m_capacity(M_CAPACITY_DEFAULT),
		m_size(0),
		m_data(nullptr)
{
	if (other.Empty())
		DefaultAllocate();
	else
		CopyOtherVector(other);
}

template<typename T>
inline Vector<T>::Vector(int count, const T& value)
	:	m_capacity(M_CAPACITY_DEFAULT),
		m_size(0),
		m_data(nullptr)
{
	if (count <= 0)
	{
		DefaultAllocate();
		return;
	}

	m_capacity = count + (count / 2);
	m_size = count;
	m_data = new T[static_cast<size_t>(m_capacity)] {};

	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = value;
	}
}

template<typename T>
inline Vector<T>::~Vector()
{
	ClearContents();
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		ClearContents();

		if (other.Empty())
			DefaultAllocate();
		else
			CopyOtherVector(other);
	}

	return *this;
}

// private helper methods
template<typename T>
inline void Vector<T>::ClearContents()
{
	if (m_data != nullptr)
	{
		delete[] m_data;
		m_data = nullptr;
	}
}

template<typename T>
inline void Vector<T>::DefaultAllocate()
{
	m_capacity = M_CAPACITY_DEFAULT;
	m_size = 0;
	m_data = new T[static_cast<size_t>(m_capacity)]{};
}

template<typename T>
inline void Vector<T>::CopyOtherVector(const Vector<T>& other)
{
	m_capacity = other.Capacity();
	m_size = other.Size();
	m_data = new T[static_cast<size_t>(m_capacity)]{};

	std::memcpy(m_data, other.m_data, static_cast<size_t>(other.Size()) * sizeof(T));

	//for (int i = 0; i < other.Size(); i++)
	//{
	//	m_data[i] = other.m_data[i];
	//}
}

template<typename T>
inline void Vector<T>::Grow()
{
	int newCapacity = m_capacity * 2;
	T* newData = new T[static_cast<size_t>(newCapacity)];

	for (int i = 0; i < Size(); i++)
		newData[i] = m_data[i];

	delete[] m_data;

	m_capacity = newCapacity;
	m_data = newData;
}

template<typename T>
inline bool Vector<T>::Full() const
{
	return m_size == m_capacity;
}

// element access
template<typename T>
inline T& Vector<T>::At(int pos)
{
	if (pos < 0 || pos >= m_size)
		throw std::out_of_range("error : index is out of range");

	return m_data[pos];
}

template<typename T>
inline T& Vector<T>::operator[](int pos)
{
	if (pos < 0 || pos >= m_size)
		throw std::out_of_range("error : index is out of range");

	return m_data[pos];
}

template<typename T>
inline const T& Vector<T>::operator[](int pos) const
{
	if (pos < 0 || pos >= m_size)
		throw std::out_of_range("error : index is out of range");

	return m_data[pos];
}

template<typename T>
inline T& Vector<T>::Front()
{
	return m_data[0];
}

template<typename T>
inline const T& Vector<T>::Front() const
{
	return m_data[0];
}

template<typename T>
inline T& Vector<T>::Back()
{
	return m_data[m_size - 1];
}

template<typename T>
inline const T& Vector<T>::Back() const
{
	return m_data[m_size - 1];
}

// capacity and size
template<typename T>
inline bool Vector<T>::Empty() const
{
	return m_size == 0;
}

template<typename T>
inline int Vector<T>::Size() const
{
	return m_size;
}

template<typename T>
inline int Vector<T>::Capacity() const
{
	return m_capacity;
}

// modifiers
template<typename T>
inline void Vector<T>::Clear()
{
	ClearContents();
	DefaultAllocate();
}

template<typename T>
inline void Vector<T>::Erase(int pos)
{
	if (pos < 0 || pos >= m_size)
		throw std::out_of_range("error : index is out of range\n");

	for (int i = pos + 1; i < m_size; i++)
	{
		m_data[i - 1] = m_data[i];
	}

	m_size--;
}

template<typename T>
inline void Vector<T>::PushBack(const T& value)
{
	if (Full())
		Grow();

	m_data[m_size++] = value;
}

template<typename T>
inline void Vector<T>::PopBack()
{
	if (Empty())
		return;

	m_size--;
}


#endif // !VECTOR_H