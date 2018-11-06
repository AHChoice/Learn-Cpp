// run.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include <map>
#include "option.h"

using namespace std;
using namespace program_options;
#define LINK_MULTIPLE(a,b) a##b

#define EXECUTE(str)  } else if(str == name) {

#define BEGIN {
#define END   } 

#define NAME(str) _T(str)

#include "cell.h"

void findValue(CString title, CString name)
{
    //CString str = _T("");
    if (0)
    BEGIN

    EXECUTE(_T("1"))
        int a(0);    

    EXECUTE(_T("2"))
        int b(0);
    END
    
}
void print(int n)
{
    cout << n << endl;
}


void print1(int n)
{
    cout << n << endl;
}


void print2(int n)
{
    cout << n << endl;
}


void print3(int n)
{
    cout << n << endl;
}

void other()
{
    cout << "other" << endl;
}

int main()
{
    print(1);
    void(*arr[5])(int) = { print, print1, print2, print3 };

    //Switch<int> s(0);
    //s.found(0, (*arr[0]));
    //s.found(1, (*arr[1]));
    //s.found(2, (*arr[2]));
    //s.found(3, (*arr[3]));

    for (int i = 0; i < 4; ++i)
    {
        int n = i + 12;
        (*arr[i])(n);
    }

    

    //findValue(_T("1"),"2");
    system("pause");
    return 0;
}





