#include "md5.h"
#include "implement/md5encrypt.h"
#include "..\kString\kString.h"

std::string Cervice::Obj::Encrypt::md5::StrToMd5_32(std::string& strPlain, bool upper)
{
	std::string ret;
	ret.append(strPlain);

	namespace imp = Cervice::Obj::Encrypt::md5::implement;
	imp::MD5_CTX mdContext;
	imp::MD5Init(&mdContext);
	imp::MD5Update(&mdContext, (unsigned char*)const_cast<char*>(ret.c_str()), ret.size());
	imp::MD5Final(&mdContext);

	std::string md5;
	char buf[3];
	for (int i = 0; i < 16; i++)
	{
		sprintf_s(buf, "%02x", mdContext.digest[i]);
		md5.append(buf);
	}
	
	if (upper)
		md5 = String::StringToUpper(md5);

	return md5;
}

std::string Cervice::Obj::Encrypt::md5::StrToMd5_32(std::string&& strPlain, bool upper)
{
	return StrToMd5_32(strPlain, upper);
}

std::string Cervice::Obj::Encrypt::md5::StrToMd5_32(size_t lens, const char* strPlain, bool upper)
{
	if (!(lens > 0)) {
		return std::string();
	}

	std::string ret;
	ret.append(strPlain, lens);
	return StrToMd5_32(ret, upper);
}

std::string Cervice::Obj::Encrypt::md5::StrToMd5_16(std::string& strPlain, bool upper)
{
	std::string ret = StrToMd5_32(strPlain, upper);
	ret = ret.substr(8, 16);
	return ret;
}

std::string Cervice::Obj::Encrypt::md5::StrToMd5_16(std::string&& strPlain, bool upper)
{
	return StrToMd5_16(strPlain, upper);
}

std::string Cervice::Obj::Encrypt::md5::StrToMd5_16(size_t lens, const char* strPlain,  bool upper)
{
	std::string ret = StrToMd5_32(lens, strPlain, upper);
	ret = ret.substr(8, 16);
	return ret;
}
