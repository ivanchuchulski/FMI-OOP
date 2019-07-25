#pragma once

#include "Node.h"
#include "Comparator.h"

template<typename Type>
class SortedList
	: public Comparator
{

private:
	Node<Type>* m_ListTop;

private:
	void CopyFromOther(const SortedList<Type>& someList);
	void Destroy();

public:
	/*constructors*/
	SortedList();
	SortedList(const Comparator<Type>* compar);
	SortedList(const SortedList<Type> someList);

	/*destructor*/
	~SortedList();

	/*overriding the pure virtual methods*/
	int Compare(const Type& left, const Type& right) const override;


	void Add(const Type& element);



};


template<typename Type>
inline void SortedList<Type>::CopyFromOther(const SortedList<Type>& someList)
{
	if (someList.m_ListTop == nullptr) {
		m_ListTop = nullptr;
	}

	else {
		Node<Type>* toCopyFrom = someList.m_ListTop;
		Node<Type>* toMake = nullptr;
		Node<Type>* prevNode = nullptr;

		toMake = new Node<Type>();

		toMake->m_Data = toCopyFrom->m_Data;
		toMake->m_NextNode = nullptr;

		m_ListTop = toMake;
		prevNode = m_ListTop;

		toCopyFrom = toCopyFrom->m_NextNode;		//moving to the next node

		while (toCopyFrom != nullptr) 
		{
			toMake = new Node<Type>();

			toMake->m_Data = toCopyFrom->m_Data;
			toMake->m_NextNode = nullptr;

			prevNode->m_NextNode = toMake;
			prevNode = toMake;

			toCopyFrom = toCopyFrom->m_NextNode;		//moving to the next node

		}
	}
}

template<typename Type>
inline void SortedList<Type>::Destroy()
{
	if (m_ListTop != nullptr) {
		Node<Type>* toRemove = nullptr;

		while (m_ListTop != nullptr) 
		{
			toRemove = m_ListTop;
			m_ListTop = m_ListTop->m_NextNode;

			delete m_ListTop;		//free the memory
		}
	}

}

template<typename Type>
inline SortedList<Type>::SortedList()
	:	m_ListTop(nullptr)
{}


template<typename Type>
inline SortedList<Type>::SortedList(const Comparator<Type>* compar)
	:	m_ListTop(nullptr)
{
}