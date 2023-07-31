#include "kString.h"
#include <algorithm> 

std::vector<std::string>
QuickLib::Obj::String::stringSplit(std::string str, char calm) {
	std::string path;
	std::stringstream ss(str);

	std::vector<std::string> ret;

	while (std::getline(ss, path, calm)) {
		if (path.empty())continue;
		ret.emplace_back(path);
	}

	return ret;
}

std::vector<std::string>
QuickLib::Obj::String::stringSplit(std::string str, std::string calm) {
	std::string path;
	std::vector<std::string> ret;

	while (str.rfind(calm) != str.npos) {
		std::string path = str.substr(str.rfind(calm) + calm.length());
		str = str.substr(0, str.rfind(calm));
		if (path.empty()) continue;
		ret.emplace_back(std::move(path));
	}
	ret.emplace_back(str);

	return ret;
}

std::optional<std::pair<std::string, std::string>>
QuickLib::Obj::String::cutString(std::string str, std::string calm)
{
	std::pair<std::string, std::string> ret;

	if (str.find(calm) != str.npos) {
		ret.second = str.substr(str.find(calm) + calm.length());
		ret.first = str.substr(0, str.find(calm));

		return { ret };
	}

	return std::nullopt;
}

std::string QuickLib::Obj::String::StringToUpper(std::string str)
{
	std::transform(str.begin(), str.end(),str.begin(), ::toupper);
	return str;
}

std::string QuickLib::Obj::String::StringToUpper(const char* cstr, size_t lens)
{
	if (!(lens > 0)) {
		return std::string();
	}

	std::string ret;
	ret.append(cstr, lens);
	return StringToUpper(ret);
}

std::string QuickLib::Obj::String::StringToLower(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

std::string QuickLib::Obj::String::StringToLower(const char* cstr, size_t lens)
{
	if (!(lens > 0)) {
		return std::string();
	}

	std::string ret;
	ret.append(cstr, lens);
	return StringToLower(ret);
}

std::string QuickLib::Obj::String::StringTirm(std::string str)
{
	auto beg = str.find_first_not_of(' ');
	auto end = str.find_last_not_of(' ');
	if (beg != str.npos && end != str.npos) {
		str = str.substr(beg, end - beg + 1);
	}
	else {
		return "";
	}
	return str;
}

size_t QuickLib::Obj::String::StringCount(std::string str, std::string fin)
{
	size_t ret = 0;
	while (str.rfind(fin) != str.npos)
	{
		str = str.substr(0, str.rfind(fin));
		ret++;
	}

	return ret;
}

std::string QuickLib::Obj::String::StringReplace(std::string txt, std::string sub, std::string ne, int count)
{
	size_t sublens = sub.length();
	int ncount = 0;
	while (count < 0 || count >= 0 && ncount < count)
	{
		size_t step = txt.find(sub);
		if (step != txt.npos) {
			txt.replace(step, sublens, ne);
			ncount++;
			continue;
		}

		break;
	}

	return txt;
}

std::vector<size_t> QuickLib::Obj::String::StringFindIndex(std::string str, std::string tar, long cnt)
{
	std::vector<size_t> retV;
	size_t pos = str.find(tar);
	size_t base = pos;
	while (pos != str.npos && cnt != 0) {
		if(cnt > 0 )
			cnt--;
		retV.push_back(base);
		str = str.substr(pos + tar.length());
		pos = str.find(tar);
		base += pos + tar.length();
	}

	return retV;
}

std::vector<std::pair<std::size_t, std::string>>
QuickLib::Obj::String::StringNotFindIndex(std::string str, std::string tar, long cnt)
{
	std::vector<std::pair<std::size_t, std::string>> retV;
	size_t base = 0;
	size_t pos = str.find(tar);
	std::string des;
	while (pos != str.npos && cnt != 0) {
		if (cnt > 0)
			cnt--;

		des = str.substr(0, pos);
		retV.push_back({ base,std::move(des) });
		str = str.substr(pos + tar.length());
		base += pos + tar.length();
		pos = str.find(tar);
	}

	if (!str.empty() && cnt != 0) {
		retV.push_back({ base,std::move(str) });
	}

	return retV;
}

std::vector<size_t> QuickLib::Obj::String::StringrFindIndex(std::string str, std::string tar, long cnt)
{
	std::vector<size_t> retV;
	size_t pos = str.rfind(tar);
	while (pos != str.npos && cnt != 0) {
		if (cnt > 0)
			cnt--;
		retV.push_back(pos);
		str = str.substr(0, pos);
		pos = str.rfind(tar);
	}

	return retV;
}

std::vector<std::pair<std::size_t, std::string>> 
	QuickLib::Obj::String::StringNotrFindIndex(std::string str, std::string tar, long cnt)
{
	std::vector<std::pair<std::size_t, std::string>> retV;
	size_t pos = str.rfind(tar);
	std::string des;
	while (pos != str.npos && cnt != 0) {
		if (cnt > 0)
			cnt--;

		des = str.substr(pos + tar.length());
		retV.push_back({ pos + tar.length(),std::move(des) });
		str = str.substr(0, pos);
		pos = str.rfind(tar);
	}

	if (!str.empty() && cnt != 0) {
		retV.push_back({0 ,std::move(str) });
	}

	return retV;
}
