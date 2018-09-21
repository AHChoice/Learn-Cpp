#pragma once
#include <afx.h>

class cell
{
public:
    cell();
    ~cell();
    cell(CString name) :name_(name), is_underline_(false) {}

public:
    CString name_;
    bool is_underline_;
};

