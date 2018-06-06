//////////////////////////////////////////////////////////////////////////
//  @file     string_length.h
//  @author   VincentLee
//  @date     2018-05-28
//  @mail     vincentleecn@163.com
//
//  @version  2018-05-29
//  -added std::string length and capacity
//  @remark   
//  @note
//////////////////////////////////////////////////////////////////////////

#ifndef STRING_LENGHT_H
#define STRING_LENGHT_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include "Line.h"

namespace cm_length
{
	int length()
	{
		LINE(PLOG_STR(length));
		// size_type string::length() const
		// size_type string::size() const

		std::string source("0123456789");
		std::cout << source.length() << std::endl;
		std::cout << source.size() << std::endl;

		// bool string::empty() const
		std::string str_notempty("Not Empty");
		std::cout << (str_notempty.empty() ? "true" : "false") << std::endl;
		std::string str_empty;
		std::cout << (str_empty.empty() ? "true" : "false") << std::endl;

		// size_type string::max_size() const
		// Returns the maximum number of characters that a string is allowed to have.
		// This value will vary depending on operating system and system architecture.
		
		std::string str_maxsize("mystring");
		std::cout << str_maxsize.max_size() << std::endl;

		// size_type string::capacity() const
		// Returns the number of characters a string can hold without reallocation.

		std::string str_capacity("0123456789");
		std::cout << "Length: " << str_capacity.length() << std::endl;
		std::cout << "Capacity: " << str_capacity.capacity() << std::endl;


		// void string::reserve() 
		// void string::reserve(size_type unSize)
		// The second flavor of this function sets the capacity of the string
		// to at least unSize (it can be greater). Note that this may require a 
		// reallocation to occur.
		// If the first flavor of the function is called, or the second flavor 
		// is called with unSize less than the current capacity, the function 
		// will try to shrink the capacity to match the length. This is a
		// non-binding request.

		std::string str_reserve("01234567");
		std::cout << "Lenght: " << str_reserve.length() << std::endl;
		std::cout << "Capacity: " << str_reserve.capacity() << std::endl;

		str_reserve.reserve(200);
		std::cout << "Lenght: " << str_reserve.length() << std::endl;
		std::cout << "Capacity: " << str_reserve.capacity() << std::endl;
		
		str_reserve.reserve();
		std::cout << "Lenght: " << str_reserve.length() << std::endl;
		std::cout << "Capacity: " << str_reserve.capacity() << std::endl;

		// Length: 8
		// Capacity: 15
		// Length: 8
		// Capacity: 207
		// Length: 8
		// Capacity: 207

		// If you know in advance that you¡¯re going to be constructing a large 
		// string by doing lots of string operations that will add to the size 
		// of the string, you can avoid having the string reallocated multiple 
		// times by immediately setting the string to its final capacity:

		// Rather than having to reallocate sString multiple times, we set the
		// capacity once and then fill the string up. This can make a huge 
		// difference in performance when constructing large strings via
		// concatenation.

		srand(static_cast<unsigned int>(time(0))); // seed random number generator

		std::string str_final; // length 0
		str_final.reserve(64);

		// Fill string up with random lower case characters
		for (int i = 0; i < 64; ++i)
			str_final += 'a' + rand() % 26;
		
		std::cout << str_final << std::endl;

		return 0;
	}
}


#endif // STRING_LENGHT_H