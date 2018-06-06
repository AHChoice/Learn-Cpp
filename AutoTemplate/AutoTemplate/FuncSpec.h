//////////////////////////////////////////////////////////////////////////
//  @file     FuncSpec.h
//  @author   AutoNet
//  @date     2018-05-23
//  @remark   Function template specialization
//  @note     
//////////////////////////////////////////////////////////////////////////

#ifndef FUNC_SPEC_H
#define FUNC_SPEC_H
#include <string>

template <class T>
class Storage
{
private:
	T m_value;
public:
	Storage(T value)
	{
		m_value = value;
	}

	~Storage()
	{
	}

	void print()
	{
		std::cout << m_value << '\n';
	}
};
// Partial-specialization of Storage class for pointers
template <class T>
class Storage<T*>
{
private:
	T* m_value;
public:
	Storage(T* value)
	{
		m_value = new T(*value);
	}

	~Storage()
	{
		delete m_value;
	}

	void print()
	{
		std::cout << *m_value << '\n';
	}
};

// Now, let¡¯s say we want double values (and only double values) to output in 
// scientific notation. 

//template <>
//void Storage<double>::print()
//{
//	std::cout << std::scientific << m_value << '\n';
//}
//
//template <>
//Storage<char*>::Storage(char* value)
//{
//	// Figure out how long the string in value is
//	int length=0;
//	while (value[length] != '\0')
//		++length;
//	++length; // +1 to account for null terminator
//
//	// Allocate memory to hold the value string
//	m_value = new char[length];
//
//	// Copy the actual value string into the m_value memory we just allocated
//	for (int count=0; count < length; ++count)
//		m_value[count] = value[count];
//}
//
//template <>
//Storage<char*>::~Storage()
//{
//	delete[] m_value;
//}

int FuncSpec()
{
	// Define some storage units
	//Storage<int> nValue(5);
	//Storage<double> dValue(58000.5);

	//// Print out some values
	//nValue.print();
	//dValue.print();

	// Dynamically allocate a temporary string
	//char *string = new char[40];

	// Ask user for their name
	//std::cout << "Enter your name: ";
	//std::cin >> string;

	// Store the name
	string *str = new string("liwenxing");
	Storage<string*> storage(str);

	// Delete the temporary string
	//delete[] string;

	// Print out our value
	storage.print(); // This will print garbage
	return 0;
}



#endif  // FUNC_SPEC_H