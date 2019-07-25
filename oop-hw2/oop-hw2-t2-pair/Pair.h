#pragma once

#ifndef PAIR_H
#define PAIR_H

#include <string.h>



/*		---class Pair definition ---		*/
template<typename Type>
class Pair {

/*contansts*/
private:
	const char NAME_BY_DEFAULT[8] = "Unknown";
	const int LENGTH_BY_DEFAULT = 7;

private:
	char* m_Key;	
	Type m_Value;		//value is stack allocated 

protected:
	char* MakeCString(const char* source = nullptr);
public:
	/*constructors*/
	Pair();
	Pair(const Pair<Type>& somePair);
	Pair(const char* key, const Type& value);

	/*destructor*/
	~Pair();

	/*copy assignment operator*/
	Pair<Type>& operator=(const Pair<Type>& somePair);

	/*setters*/
	void SetValue(const Type& value);
	void SetKey(const char* key);

	/*getters*/
	const char* GetKey() const;
	Type GetValue() const;


};



/*class Pair method definitions*/
#pragma region

template<typename Type>
inline char* Pair<Type>::MakeCString(const char* source) {
	char* toMakeString = nullptr;

	if (source != nullptr) {
		int len = strlen(source);
		toMakeString = new char[len + 1];
		strcpy_s(toMakeString, len + 1, source);

		return toMakeString;
	}
	else {
		toMakeString = new char[LENGTH_BY_DEFAULT + 1];
		strcpy_s(toMakeString, LENGTH_BY_DEFAULT + 1, NAME_BY_DEFAULT);
		
		return toMakeString;
	}
}


/*default constructor*/
template<typename Type>
inline Pair<Type>::Pair()
	:	m_Key(MakeCString()), 
		m_Value()
{}

/*copy constructor*/
template<typename Type>
inline Pair<Type>::Pair(const Pair<Type>& somePair)
	:	m_Key(MakeCString(somePair.m_Key)),
		m_Value(somePair.m_Value)
{}

/*constructor with parameters*/
template<typename Type>
inline Pair<Type>::Pair(const char * key, const Type & value)
	:	m_Key(MakeCString(key)), 
		m_Value(value)
{}

/*destructor*/
template<typename Type>
inline Pair<Type>::~Pair() 
{
	if (m_Key != nullptr) {
		delete[] m_Key;
	}
}



template<typename Type>
inline Pair<Type>& Pair<Type>::operator=(const Pair<Type>& somePair)
{
	if (this != &(somePair)) {
		//free dynamic resource
		if (m_Key != nullptr) {
			delete[] m_Key;
		}

		//copy new data
		m_Key = MakeCString(somePair.m_Key);
		m_Value = somePair.m_Value;

	}

	return *this;// TODO: insert return statement here
}


template<typename Type>
inline void Pair<Type>::SetValue(const Type & value)
{
	m_Value = value;
}

/* setter for the key*/
template<typename Type>
inline void Pair<Type>::SetKey(const char * key)
{
	if (m_Key != nullptr) {
		delete[] m_Key;
	}
	m_Key = MakeCString(key);
}

template<typename Type>
inline const char * Pair<Type>::GetKey() const
{
	return m_Key;
}

template<typename Type>
inline Type Pair<Type>::GetValue() const
{
	return Type(m_Value);
}

#pragma endregion

#endif // !PAIR_H