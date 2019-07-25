#pragma once

#include <cstddef>

namespace spn {

	/*specification for single object*/
	template<typename Type>
	class Unique_ptr
	{
	private:
		Type* m_Data;

	public:
		/*constructors*/
		Unique_ptr();
		Unique_ptr(Type* ptr);
		Unique_ptr(const Unique_ptr<Type>& otherPtr) = delete;

		/*destructor*/
		~Unique_ptr();

		/*copy equals*/
		Unique_ptr<Type>& operator=(const Unique_ptr<Type>& otherPtr) = delete;

	};

	/*specification for array-type allocation*/
	//template<typename Type>
	//class Unique_ptr<Type[]>
	//{
	//private:
	//	Type* m_Data;

	//public:
	//	/*constructors*/
	//	Unique_ptr();
	//	Unique_ptr(size_t obj_size);
	//	Unique_ptr(const Unique_ptr<Type[]> & otherPtr) = delete;

	//	/*destructor*/
	//	~Unique_ptr();

	//	/*copy equals*/
	//	Unique_ptr<Type[]> & operator=(const Unique_ptr<Type[]> & otherPtr) = delete;

	//};
}

/*		single-object class methods definition	*/
#pragma region
/*default ctor*/
template<typename Type>
inline spn::Unique_ptr<Type>::Unique_ptr()
	:	m_Data(nullptr)
{}


template<typename Type>
inline spn::Unique_ptr<Type>::Unique_ptr(Type* ptr)
	:	m_Data(nullptr)
{
	m_Data = ptr;
}

/*destructor*/
template<typename Type>
inline spn::Unique_ptr<Type>::~Unique_ptr()
{
	if (m_Data)
	{
		delete m_Data;
	}
}


#pragma endregion



/*		array object specification class methods definition		*/

/*default ctor*/
//template<typename Type>
//inline spn::Unique_ptr<Type[]>::Unique_ptr()
//	:	m_Data(nullptr)
//{}

