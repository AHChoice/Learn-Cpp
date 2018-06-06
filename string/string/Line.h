//////////////////////////////////////////////////////////////////////////
//  @file     Line.h
//  @author   VincentLee
//  @date     2018-05-30
//  @mail     vincentleecn@163.com
//
//  @version  2018-05-30
//  -added 
//  @remark   
//  @note
//////////////////////////////////////////////////////////////////////////

#ifndef LINE_H
#define LINE_H

#include <iostream>

#define LINE(name) \
	std::string line(50, '-'); \
	line.replace(20, name.length(), name); \
	std::cout << line << std::endl;

#define  _PLOG_STR(x) static_cast<std::string>(#x)
#define  PLOG_STR(x) _PLOG_STR(x)

#endif // LINE_H