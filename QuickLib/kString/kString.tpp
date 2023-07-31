#include "kString.h"
#include <sstream>

template<typename T>
std::vector<typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type>
	QuickLib::Obj::String::stringSplit(std::string str, char calm)
{
	using retType = typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type;
	std::string path;
	std::stringstream ss(str);

	std::vector<retType> ret;
	stringTo<retType>(path);

	while (std::getline(ss, path, calm)) {
		if (path.empty()) continue;
		ret.push_back(stringTo<retType>(path));
	}

	return ret;
}

template<typename T>
std::vector<T> QuickLib::Obj::String::stringSplit(std::string str, char calm, T(*func)(std::string))
{
	if (func == nullptr) {
		throw("callback cant be nullptr");
	}

	std::string path;
	std::stringstream ss(str);

	std::vector<T> ret;

	while (std::getline(ss, path, calm)) {
		if (path.empty()) continue;
		ret.push_back(func(path));
	}

	return ret;
}

template<typename T>
std::vector<typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type> 
QuickLib::Obj::String::stringSplit(std::string str, std::string calm)
{
	using retType = typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type;
	std::string path;

	std::vector<retType> ret;
	stringTo<retType>(path);

	while (str.rfind(calm) != str.npos) {
		std::string path = str.substr(str.rfind(calm) + calm.length());
		str = str.substr(0, str.rfind(calm));
		if (path.empty()) continue;
		ret.emplace_back(stringTo<retType>(path));
	}

	ret.emplace_back(str);

	return ret;
}


template<typename T>
std::vector<T> QuickLib::Obj::String::stringSplit(std::string str, std::string calm, T(*func)(std::string))
{
	if (func == nullptr) {
		throw("callback cant be nullptr");
	}

	using retType = typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type;
	std::string path;

	std::vector<retType> ret;
	stringTo<retType>(path);

	while (str.rfind(calm) != str.npos) {
		std::string path = str.substr(str.rfind(calm) + calm.length());
		str = str.substr(0, str.rfind(calm));
		if (path.empty()) continue;
		ret.emplace_back(func(path));
	}
	ret.emplace_back(stringTo<retType>(str));

	return ret;
}

template<typename T>
typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type
QuickLib::Obj::String::stringTo(std::string str, bool* has) {
	std::stringstream ss;
	ss << str;

	typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type ret;
	ss >> ret;

	if (has && !(ss.eof() && !ss.fail())) {
		*has = false;
	}

	return ret;
}

template<typename T>
std::string QuickLib::Obj::String::stringFrom(
	typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type num,
	bool* has)
{
	std::string ret;
	std::stringstream ss;
	ss << num;
	ss >> ret;

	if (has && !(ss.eof() && !ss.fail())) {
		*has = false;
	}

	return ret;
}

