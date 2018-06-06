// AutoTemplate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cents.h"
#include "AHTemplateClass.h"
#include "non-type.h"
#include "FuncSpec.h"
#include "ClassSpec.h"
#include "PointerSpec.h"

const char CENTS = 0;
const char TEMCLASS = 0;
const char NONTYPE = 0;
const char FUNC_SPEC = 1;
const char CLASS_SPEC = 0;
const char POINT_SPEC = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	if (CENTS)
		cents();

	if (TEMCLASS)
		TemplateClass();

	if (NONTYPE)
		non_type();

	if (FUNC_SPEC)
		FuncSpec();

	if (CLASS_SPEC)
		ClassSpec();

	if (POINT_SPEC)
		PointerSpec();

	return 0;
}

