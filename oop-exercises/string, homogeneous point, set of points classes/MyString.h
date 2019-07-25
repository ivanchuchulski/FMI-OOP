#pragma once

#include <cstring>
#include <stdexcept>

namespace ich {


	class MyString
	{
	private:
		size_t m_Capacity;		//reserved bytes in memory including the '\0'
		size_t m_Length;		//current size(index), bytes occupied with characters, excluding the '\0'
		char* m_Data;			//the actual string

	protected:
		void Expand();

	public:
		/*constructors*/
		MyString();
		MyString(const MyString& someString);
		MyString(const char* source_str);

		/*destructor*/
		~MyString();

		/*copy assignment*/
		MyString& operator=(const MyString& someString);

		const char* GetData() const;

		size_t Length() const;
		void Clear();
		bool IsEmpty() const;

		char& operator[](size_t index);				//for non-constant access
		const char& operator[](size_t index) const;		//for constant access


		friend bool operator<(const MyString& lhs_string, const MyString& rhs_string);
		friend bool operator>(const MyString& lhs_string, const MyString& rhs_string);
		friend bool operator==(const MyString& lhs_string, const MyString& rhs_string);

	};

}