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

	// �ݴˣ����ǿ��Եó����½��ۣ�
	//��1�� >> �����������ǰ��Ŀհ׷��ͻ��з���������Խ������Ļ��з��Ϳհ׷�
	//��2��get()���������Թ��κη���
	//��3��peek()����Ԥ��ȡ��һ���ַ��������Ǻη��ţ�
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