//////////////////////////////////////////////////////////////////////////
//  @file     string_append.h
//  @author   VincentLee
//  @date     2018-05-29
//  @mail     vincentleecn@163.com
//
//  @version  2018-05-29
//  -added 
//  @remark   
//  @note
//////////////////////////////////////////////////////////////////////////

#ifndef STRING_APPEND_H
#define STRING_APPEND_H

#include <iostream>
#include <string>
#include "Line.h"

namespace string_append
{
	int append()
	{
		LINE(PLOG_STR(append));
		
		// string& string::operator+= (const string& str)
		// string& string::append (const string& str)

		std::string souce("one");
		souce += std::string("two");

		std::string str_three(" three");
		souce.append(str_three);

		std::cout << souce << std::endl;

		// string& string::append (const string& str, size_type index, size_type num)

		souce = std::string("one ");
		const std::string str_temp("twothreefour");
		souce.append(str_temp, 3, 5); // append substring of str_temp at index 3 of length 5
		std::cout << souce << std::endl;
		
		// string& string::operator+= (const char* str)
		// string& string::append (const char* str)
		
		souce = std::string("one");
		souce += " two";
		souce.append(" three");
		std::cout << souce << std::endl;

		// There is an additional flavor of append() that works on C-style strings:
		// string& string::append (const char* str, size_type len)

		// Appends the first len characters of str to the string.
		// Returns *this so they can be ¡°chained¡±.
		// Throw a length_error exception if the result exceeds the maximum 
		// number of characters.
		// Ignores special characters (including ¡±)

		souce = std::string("one ");
		souce.append("threefour", 5);
		std::cout << souce << std::endl;

		// string& string::operator+= (char c)
		// void string::push_back (char c)

		souce = std::string("one");

		souce += ' ';
		souce.push_back('2');
		
		std::cout << souce << std::endl;

		// string& string::append (size_type num, char c)
		// string& string::append (InputIterator start, InputIterator end)

		souce = std::string("aaa");

		souce.append(4, 'b');
		std::cout << souce << std::endl;


		return 0;
	}
}


#endif // STRING_APPEND_H