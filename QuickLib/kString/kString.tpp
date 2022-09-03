#include "kString.h"
#include <sstream>

template<typename T>
std::vector<typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type>
	Cervice::Obj::String::stringPlist(std::string str, char calm)
{
	using retType = typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type;
	std::string path;
	std::stringstream ss(str);

	std::vector<retType> ret;
	stringTo<retType>(path);

	while (std::getline(ss, path, calm)) {
		ret.push_back(stringTo<retType>(path));
	}

	return ret;
}

template<typename T>
std::vector<T> Cervice::Obj::String::stringPlist(std::string str, char calm, T(*func)(std::string))
{
	if (func == nullptr) {
		throw("callback cant be nullptr");
	}

	std::string path;
	std::stringstream ss(str);

	std::vector<T> ret;

	while (std::getline(ss, path, calm)) {
		ret.push_back(func(path));
	}

	return ret;
}


template<typename T>
typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type
Cervice::Obj::String::stringTo(std::string str) {
	std::stringstream ss;
	ss << str;

	typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type ret;
	ss >> ret;
	return ret;
}

