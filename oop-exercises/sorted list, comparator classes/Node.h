#pragma once


template<typename Type>
class Node {

private:
	Type m_Data;
	Node<Type>* m_NextNode;

public:
	Node();
	Node(const Type& data, const Node<Type>* nextNode);
	Node(const Node<Type>& someNode);

	~Node();

	Node<Type>& operator=(const Node<Type>& someNode);



};


/*class methods definition*/
#pragma region

/*default ctor*/
template<typename Type>
inline Node<Type>::Node()
	:	m_Data(),
		m_NextNode(nullptr)
{}

/*ctor with parameters*/
template<typename Type>
inline Node<Type>::Node(const Type & data, const Node<Type>* nextNode)
	:	m_Data(data),
		m_NextNode(m_NextNode)
{}

/*copy ctor*/
template<typename Type>
inline Node<Type>::Node(const Node<Type>& someNode)
	:	m_Data(someNode.m_Data),
		m_NextNode(someNode.m_NextNode)
{}

/*destructor*/
template<typename Type>
inline Node<Type>::~Node()
{}

/*copy assignment*/
template<typename Type>
inline Node<Type>& Node<Type>::operator=(const Node<Type>& someNode)
{
	if (this != &(someNode)) {
		m_Data = someNode.m_Data;
		m_NextNode = someNode.m_NextNode;
	}

	return *this;		// TODO: insert return statement here
}
















#pragma endregion
