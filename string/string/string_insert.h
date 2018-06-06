//////////////////////////////////////////////////////////////////////////
//  @file     string_insert.h
//  @author   VincentLee
//  @date     2018-05-29
//  @mail     vincentleecn@163.com
//
//  @version  2018-05-29
//  -added 
//  @remark   
//  @note
//////////////////////////////////////////////////////////////////////////

#ifndef STRING_INSERT_H
#define STRING_INSERT_H


#include <iostream>
#include <string>
#include "Line.h"

namespace string_insert
{
	int insert()
	{
		LINE(PLOG_STR(insert));

		// string& string::insert (size_type index, const string& str)
		// string& string::insert (size_type index, const char* str)
		
		std::string source("aaaa");
		std::cout << source << std::endl;

		source.insert(2, std::string("bbbb"));
		std::cout << source << std::endl;

		source.insert(4, "cccc");
		std::cout << source << std::endl;

		// Here¡¯s a crazy version of insert() that allows you to insert a 
		// substring into a string at an arbitrary index:

		// string& string::insert (size_type index, const string& str, 
		// size_type startindex, size_type num)

		source = std::string("aaaa");

		const std::string str_insert("01234567");
		source.insert(2, str_insert, 3, 4);
		std::cout << source << std::endl;

		// string& string::insert(size_type index, const char* str, size_type len)
		
		source = std::string("aaaa");

		source.insert(2, "bcdef", 3);
		std::cout << source << std::endl;

		// string& string::insert(size_type index, size_type num, char c)

		source = std::string("aaaa");

		source.insert(2, 4, 'c');
		std::cout << source << std::endl;

		// And finally, the insert() function also has three different versions 
		// that use iterators:

		// void insert(iterator it, size_type num, char c)
		// iterator string::insert(iterator it, char c)
		// void string::insert(iterator it, InputIterator begin, InputIterator end)

		return 0;
	}
}

#endif // STRING_INSERT_H