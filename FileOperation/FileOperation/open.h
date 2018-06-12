//////////////////////////////////////////////////////////////////////////
//  @file     open.h
//  @author   VincentLee
//  @date     2018/06/12
//  @mail     vincentleecn@163.com
//
//  @version  2018/06/12
//  -added 
//  @remark   
//  @note
//////////////////////////////////////////////////////////////////////////

#ifndef OPEN_H
#define OPEN_H

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

namespace open_cm
{
	void write()
	{
		fstream fin;
		fin.open("../letter.txt", ios::in | ios::out | ios::binary);
		if (fin.is_open())
		{
			fin << "this is a line.\r\n";
			fin << "this is a another line.\r\n";
			fin.close();
		}

	}

	void copy()
	{
		fstream fin;
		fin.open("../letter.txt", ios::in | ios::binary);

		if (!fin.is_open())
		{
			cout << "open letter.txt fail" << endl;
		}

		// get the associated filebuf object
		fstream fout("../copy.txt", ios::out | ios::binary | ios::app);
		fout << fin.rdbuf();
		fin.close();
		fout.close();
	}

	void read()
	{
		fstream fin;
		fin.open("../letter.txt", ios::in | ios::binary);
		string line;

		//while (getline(fin, line))  // read by line
		//{
		//	cout << line << endl;
		//}
		
		while (fin >> line)  // read by backspace
		{
			cout << line << endl;
		}
	}

	void seekp()
	{
		fstream fin;
		fin.open("../letter.txt");

		fin.write("This is an apple", 16);
		long pos = fin.tellp();
		fin.seekp(pos - 7);
		fin.write(" sam", 4);

		fin.close();
	}

	// 据此，我们可以得出以下结论：
	//（1） >> 操作符会忽略前面的空白符和换行符，但不会越过后面的换行符和空白符
	//（2）get()方法不会略过任何符号
	//（3）peek()方法预读取下一个字符（不管是何符号）
	void plain()
	{
		fstream inFile;
		inFile.open("../plain.txt", ios::in);
		int iNum;
		inFile >> iNum;
		cout << (char)inFile.peek() << endl;
	}
	
	void tie()
	{
		std::ostream *prevstr;
		std::ofstream ofs;
		ofs.open("../test.txt");

		std::cout << "tie example:\n";

		*std::cin.tie() << "This is inserted into cout";
		//prevstr = std::cin.tie(&ofs);
		//*std::cin.tie() << "This is inserted into the file";
		//std::cin.tie(prevstr);

		ofs.close();
	}

	
}

#endif // OPEN_H