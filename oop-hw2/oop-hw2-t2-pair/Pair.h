#pragma once

#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include "String.h"

template<typename Type>
class Pair 
{
public:
	Pair();
	Pair(const Pair<Type>& somePair);
	Pair(const String& key, const Type& value);

	~Pair();

	Pair<Type>& operator=(const Pair<Type>& somePair);

	void SetValue(const Type& value);
	void SetKey(const String& key);

	String GetKey() const;
	Type GetValue() const;

	
	friend std::ostream& operator<<(std::ostream& outStream, const Pair<Type>& pair)
	{
		outStream << pair.m_key << ' ' << pair.m_value;

		return outStream;
	}

private:
	String m_key;
	Type m_value;
};


template<typename Type>
inline Pair<Type>::Pair()
	:	m_key(), 
		m_value()
{}

template<typename Type>
inline Pair<Type>::Pair(const Pair<Type>& somePair)
	:	m_key(somePair.m_key),
		m_value(somePair.m_value)
{}

template<typename Type>
inline Pair<Type>::Pair(const String& key, const Type& value)
	:	m_key(key), 
		m_value(value)
{}

template<typename Type>
inline Pair<Type>::~Pair() 
{}

template<typename Type>
inline Pair<Type>& Pair<Type>::operator=(const Pair<Type>& somePair)
{
	if (this != &somePair) 
	{
		m_key = somePair.m_key;
		m_value = somePair.m_value;
	}

	return *this;
}


template<typename Type>
inline void Pair<Type>::SetValue(const Type & value)
{
	m_value = value;
}

template<typename Type>
inline void Pair<Type>::SetKey(const String& key)
{
	m_key = key;
}

template<typename Type>
inline String Pair<Type>::GetKey() const
{
	return m_key;
}

template<typename Type>
inline Type Pair<Type>::GetValue() const
{
	return Type(m_value);
}

#endif // !PAIR_H