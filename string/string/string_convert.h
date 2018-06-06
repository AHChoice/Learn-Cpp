//////////////////////////////////////////////////////////////////////////
//  @file     string_convert.h
//  @author   VincentLee
//  @date     2018-05-29
//  @mail     vincentleecn@163.com
//
//  @version  2018-05-29
//  -added  std::string character access and conversion to C-style arrays
//  @remark   
//  @note
//////////////////////////////////////////////////////////////////////////

#ifndef STRING_CONVERT_H
#define STRING_CONVERT_H

#include <iostream>
#include <string>
#include <sstream>
#include "Line.h"

namespace cm_convert
{
	int getCharacter()
	{
		LINE(PLOG_STR(character));
		// char£¦string :: operator []£¨size_type nIndex£©
		// const char£¦string :: operator []£¨size_type nIndex£©const
		std::string source("abcdefg")		;
		std::cout << source[5] << std::endl;
		source[5] = 'x';
		std::cout << source << std::endl;

		// output:
		// f
		// abcdexg

		// There is also a non-operator version. This version is slower since
		// it uses exceptions to check if the nIndex is valid. If you are not 
		// sure whether nIndex is valid, you should use this version to access
		// the array:

		// char& string::at (size_type nIndex)
		// const char& string::at (size_type nIndex) const

		// Both of these functions return the character with index nIndex
		// Passing an invalid index results in an out_of_range exception
		// Because char& is the return type, you can use this to edit characters
		// in the array

		std::cout << source.at(5) << std::endl;
		source.at(5) = 'x';
		std::cout << source << std::endl;

		// output:
		// f
		// abcdexg

		// Conversion to C-style arrays
		// const char* string::c_str() const
		// const char* string::data() const
		// size_type string :: copy£¨char * szBuf£¬size_type nLength£©const 
		//size_type string :: copy£¨char * szBuf£¬size_type nLength£¬size_type nIndex£©const

		source.c_str();
		source.data();
		std::string str_long("sphinx of black quartz, judge my vow");

		char szBuf[20];
		size_t nLength = str_long.copy(szBuf, 5, 10);
		szBuf[nLength] = '\0'; // Make suer we terminate the string in the buffer
		
		std::cout << szBuf << std::endl;

		return 0;
	}
}

#endif // STRING_CONVERT_H