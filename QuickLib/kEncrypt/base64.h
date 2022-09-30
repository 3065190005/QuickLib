#pragma once
#ifndef _CERVER_KENCRYPT_BASE64__
#define _CERVER_KENCRYPT_BASE64__

#include <string>

namespace Cervice {
	namespace Obj {
		namespace Encrypt {
			namespace base64 {

				// base64加密 原文字符串 长度
				std::string base64_encode(unsigned char const* cstr, unsigned int len);
				std::string base64_encode(std::string str, int len = -1);

				// base64解密 密文字符串 长度
				std::string base64_decode(unsigned char* str, int len);
				std::string base64_decode(std::string const& s);
			};
		};
	};
};

#endif