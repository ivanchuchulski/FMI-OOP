#pragma once

#ifndef SETTINGS_H
#define SETTINGS_H

#include "Vector.h"
#include "Pair.h"

template<typename Type>
class Settings 
{
public:
	Settings();
	Settings(int settingsSize);
	Settings(const Settings<Type>& other);

	~Settings();

	Settings<Type>& operator=(const Settings<Type>& other);

	// returns how many Pair objects are in the array
	int Count() const;

	// if a entity with key is present, then it's value is set to value argument
	// else a new entity is created
	void Set(const char* key, const Type& value);

	// if a entity with key is present, then value is set to it's value and true is returned
	// else the method returns false and does nothing to value
	bool Get(const char* key, const Type& value);

	friend std::ostream& operator<<(std::ostream& outStream, const Settings<Type>& settings)
	{
		for (int i = 0; i < settings.Count(); i++)
		{ 
			outStream << settings.m_pairs[i] << '\n';
		}

		return outStream;
	}

private:
	int FindByKey(const String& keyToFind);

private:
	Vector<Pair<Type>> m_pairs;
};


template<typename Type>
inline Settings<Type>::Settings()
	:	m_pairs()
{}

template<typename Type>
inline Settings<Type>::Settings(int settingsSize)
	:	m_pairs(settingsSize)
{}


template<typename Type>
inline Settings<Type>::Settings(const Settings<Type>& other)
	:	m_pairs(other.m_pairs)
{}

template<typename Type>
inline Settings<Type>::~Settings()
{}

template<typename Type>
inline Settings<Type>& Settings<Type>::operator=(const Settings<Type>& other)
{
	if (this != &other) 
	{
		m_pairs = other.m_pairs;
	}

	return *this;
}

template<typename Type>
inline int Settings<Type>::FindByKey(const String& keyToFind)
{
	for (int i = 0; i < Count(); i++) 
	{
		if (keyToFind == m_pairs[i].GetKey()) 
		{
			return i;
		}
	}

	return -1;
}

template<typename Type>
inline int Settings<Type>::Count() const
{
	return m_pairs.Size();
}

template<typename Type>
inline void Settings<Type>::Set(const char* key, const Type& value)
{
	int foundIndex = FindByKey(key);

	if (foundIndex == -1)
	{
		m_pairs.PushBack(Pair(key, value));
	}

	else 
	{
		m_pairs[foundIndex].SetValue(value);
	}
}

template<typename Type>
inline bool Settings<Type>::Get(const char* key, const Type& value)
{
	int foundIndex = FindByKey(key);

	if (foundIndex == -1) 
	{
		return false;
	}

	value = m_pairs[foundIndex].GetValue();

	return true;
}

#endif // !SETTINGS_H





