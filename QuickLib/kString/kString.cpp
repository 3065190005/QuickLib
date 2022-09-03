#include "kString.h"
#include <algorithm> 

std::vector<std::string>
Cervice::Obj::String::stringPlist(std::string str, char calm) {
	std::string path;
	std::stringstream ss(str);

	std::vector<std::string> ret;

	while (std::getline(ss, path, calm)) {
		ret.emplace_back(path);
	}

	return ret;
}

std::string Cervice::Obj::String::StringToUpper(std::string str)
{
	std::transform(str.begin(), str.end(),str.begin(), ::toupper);
	return str;
}

std::string Cervice::Obj::String::StringToUpper(const char* cstr, size_t lens)
{
	if (!(lens > 0)) {
		return std::string();
	}

	std::string ret;
	ret.append(cstr, lens);
	return StringToUpper(ret);
}

std::string Cervice::Obj::String::StringToLower(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

std::string Cervice::Obj::String::StringToLower(const char* cstr, size_t lens)
{
	if (!(lens > 0)) {
		return std::string();
	}

	std::string ret;
	ret.append(cstr, lens);
	return StringToLower(ret);
}
