#pragma once
#ifndef _CERVER_KENCRYPT_MD5__
#define _CERVER_KENCRYPT_MD5__

#include <string>

namespace Cervice {
	namespace Obj {
		namespace Encrypt {
			namespace md5 {
				// md5����32λ - Դ�ַ��� ����ֵ�Ƿ�ȫ����д
				std::string StrToMd5_32(std::string& strPlain,bool upper = false);
				std::string StrToMd5_32(std::string&& strPlain, bool upper = false);

				// md5����32λ - Դ�ַ��� ���� ����ֵ�Ƿ�ȫ����д
				std::string StrToMd5_32(size_t lens ,const char* strPlain , bool upper = false);

				// md5����16λ - Դ�ַ��� ����ֵ�Ƿ�ȫ����д
				std::string StrToMd5_16(std::string& strPlain, bool upper = false);
				std::string StrToMd5_16(std::string&& strPlain, bool upper = false);

				// md5����16λ - Դ�ַ��� ���� ����ֵ�Ƿ�ȫ����д
				std::string StrToMd5_16(size_t lens, const char* strPlain, bool upper = false);
			}
		}
	}
}

#endif