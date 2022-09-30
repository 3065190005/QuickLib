#pragma once
#ifndef _CERVER_KENCRYPT_MD5__
#define _CERVER_KENCRYPT_MD5__

#include <string>

namespace Cervice {
	namespace Obj {
		namespace Encrypt {
			namespace md5 {
				// md5加密32位 - 源字符串 返回值是否全部大写
				std::string StrToMd5_32(std::string& strPlain,bool upper = false);
				std::string StrToMd5_32(std::string&& strPlain, bool upper = false);

				// md5加密32位 - 源字符串 长度 返回值是否全部大写
				std::string StrToMd5_32(size_t lens ,const char* strPlain , bool upper = false);

				// md5加密16位 - 源字符串 返回值是否全部大写
				std::string StrToMd5_16(std::string& strPlain, bool upper = false);
				std::string StrToMd5_16(std::string&& strPlain, bool upper = false);

				// md5加密16位 - 源字符串 长度 返回值是否全部大写
				std::string StrToMd5_16(size_t lens, const char* strPlain, bool upper = false);
			}
		}
	}
}

#endif