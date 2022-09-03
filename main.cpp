#include <iostream>
#include <sstream>
#include "QuickLib/quicklib.h"

using namespace kstring;
using namespace kbase64;
using namespace kmd5;

// 学生类
class student {
public: int num = 0;		// 成绩
public: char type = '0';	// 学生名称
};

student stuFunc(std::string num) {
	auto vec = stringPlist(num, ':');
	return student{ stringTo<int>(vec[1]),stringTo<char>(vec[0])};
}

int main() {
	std::string sources = "S:100|B:80|C:60|D:15";
	auto vec = stringPlist<student>(sources, '|', stuFunc);

	for (size_t i = 0; i < vec.size(); i ++) {
		std::cout << "SType : " << vec.at(i).type << std::endl;
		std::cout << "Score : " << vec.at(i).num << std::endl;
		std::cout << "\n<--------->\n";
	}
}