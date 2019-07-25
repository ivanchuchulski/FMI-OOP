#pragma once
#ifndef SETTINGS_H
#define SETTINGS_H

#include "Pair.h"



/*		---class Settings definition ---		*/
template<typename Type>
class Settings {

/*constants*/
private:
	const int MAX_SIZE_DEFUALT = 5;

private:
	int m_MaxSize;
	int m_CurrentSize;
	Pair<Type> * m_PairsArr;		//array of Pair objects

protected:
	Pair<Type>* MakePairArr(const Pair<Type>* sourcePairs, int maxSize, int currentCount_source);
	int FindByKey(const char* keyToFind);
	void ExpandArr();
public:
	/*constructors*/
	Settings();
	Settings(int max_size);
	Settings(const Settings<Type>& someSettings);

	/*destructor*/
	~Settings();

	/*copy assingment operator*/
	Settings<Type>& operator=(const Settings<Type>& someSettings);

	/*returns how many Pair objects are in the array*/
	int Count() const;

	void Set(const char* key, const Type& value);

	bool Get(const char* key, const Type& value);






};


/*	class Settings methods definition */
#pragma region

/*allocates and if needed copies from source*/
template<typename Type>
inline Pair<Type>* Settings<Type>::MakePairArr(const Pair<Type>* sourcePairs, int maxSize, int currentCount_source)
{
	Pair<Type> * toBuildArr = nullptr;

	if (sourcePairs != nullptr && maxSize > 0) {
		//allcate the array
		toBuildArr = new Pair<Type>[maxSize];

		//loop to copy
		if (currentCount_source > 0) {
			for (int i = 0; i < currentCount_source; i++) {
				toBuildArr[i] = sourcePairs[i];
			}
		}

		return toBuildArr;

	}
	else {
		toBuildArr = new Pair<Type>[maxSize];

		return toBuildArr;
	}
}

/*searches for a pair by a given key*/
template<typename Type>
inline int Settings<Type>::FindByKey(const char* keyToFind)
{
	if (keyToFind == nullptr) { return -1; }
	
	else {
		for (int i = 0; i < m_CurrentSize; i++) {
			if (strcmp(keyToFind, m_PairsArr[i].GetKey()) == 0) {
				return i;
			}
		}
	}

	//no finds at this point
	return -1;

}

/*method to grow the array*/
template<typename Type>
inline void Settings<Type>::ExpandArr() 
{
	int expansionSize = m_MaxSize + 5;

	//allocate new array
	Pair<Type>* expandedArr = new Pair<Type>[expansionSize];

	//copy from the current
	for (int i = 0; i < m_CurrentSize; i++) {
		expandedArr[i] = m_PairsArr[i];
	}

	//free current memory
	delete[] m_PairsArr;

	//assign
	m_PairsArr = expandedArr;
	m_MaxSize = expansionSize;

}

/*default constructor*/
template<typename Type>
inline Settings<Type>::Settings()
	:	m_MaxSize(MAX_SIZE_DEFUALT),
		m_CurrentSize(0),
		m_PairsArr(nullptr)
{
	m_PairsArr = MakePairArr(nullptr, MAX_SIZE_DEFUALT, m_CurrentSize);
}

/*constructor with parameters*/
template<typename Type>
inline Settings<Type>::Settings(int max_size)
	:	m_MaxSize((max_size > 0) ? max_size : MAX_SIZE_DEFUALT),
		m_CurrentSize(0),
		m_PairsArr(nullptr)
{
	m_PairsArr = MakePairArr(nullptr, m_MaxSize, m_CurrentSize);
}


/*copy constructor*/
template<typename Type>
inline Settings<Type>::Settings(const Settings<Type>& someSettings)
	:	m_MaxSize(someSettings.m_MaxSize),
		m_CurrentSize(someSettings.m_CurrentSize),
		m_PairsArr(nullptr)
{
	m_PairsArr = MakePairArr(someSettings.m_PairsArr, someSettings.m_MaxSize, someSettings.m_CurrentSize);
}


/*destructor*/
template<typename Type>
inline Settings<Type>::~Settings()
{
	if (m_PairsArr != nullptr) {
		delete[] m_PairsArr;
	}
}

template<typename Type>
inline Settings<Type>& Settings<Type>::operator=(const Settings<Type>& someSettings)
{
	if (this != &(someSettings)) {

		//free current memory
		if (m_PairsArr != nullptr) {
			delete[] m_PairsArr;
		}

		//copy the new data
		m_MaxSize = someSettings.m_MaxSize;
		m_CurrentSize = someSettings.m_CurrentSize;
		m_PairsArr = MakePairArr(someSettings.m_PairsArr, someSettings.m_MaxSize, someSettings.m_CurrentSize);
	}

	return *this;			// TODO: insert return statement here
}

/*getter for the current size of the array*/
template<typename Type>
inline int Settings<Type>::Count() const
{
	return m_CurrentSize;
}

template<typename Type>
inline void Settings<Type>::Set(const char * key, const Type & value)
{
	int foundIndex = FindByKey(key);

	//the task requires if there is no such pair with that key, a new one to be added and set with the given key and value
	if (foundIndex == -1)
	{
		if (m_CurrentSize == m_MaxSize) {
			ExpandArr();
			m_PairsArr[m_CurrentSize].SetKey(key);
			m_PairsArr[m_CurrentSize].SetValue(value);
			m_CurrentSize++;
		}
		else {
			m_PairsArr[m_CurrentSize].SetKey(key);
			m_PairsArr[m_CurrentSize].SetValue(value);
			m_CurrentSize++;
		}
	}

	//if it is found, then the pair should be modified by the given value
	else 
	{
		//m_PairsArr[foundIndex].SetKey(key);
		m_PairsArr[foundIndex].SetValue(value);
	}
}

template<typename Type>
inline bool Settings<Type>::Get(const char * key, const Type & value)
{
	int foundIndex = FindByKey(key);

	if (foundIndex == -1) {
		return false;
	}

	else {
		value = m_PairsArr[foundIndex].GetValue();
		return true;
	}
}


#pragma endregion

#endif // !SETTINGS_H





