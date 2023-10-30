#include <iostream>
#include <sstream>
#include <list>
#include <vector>


#include "QuickLib/quicklib.h"

using namespace kstring;
using namespace kbase64;
using namespace kmd5;

int main() {
	bool has = true;
	std::string abc = "123|111";
	std::wstring wabc = kconvert::GbkToUtf8(abc);
	kstring::StringReplace(abc, "|", ":");
}