#ifndef QL_CUSTOM_QUICK_LIB_H
#define QL_CUSTOM_QUICK_LIB_H
#include <iostream>

namespace QuickLib{
	namespace encrypt{

		class Base {

		private:
			bool is_base64(unsigned char c);

		public:
			std::string base64_encode(unsigned char const* cstr, unsigned int len);
			std::string base64_encode(std::string str, int len = -1);

			std::string base64_decode(unsigned char * str, int len);
			std::string base64_decode(std::string const& s);

			Base() {};
			~Base() {};
		};
	};

	namespace debug {
		void log(const char * str ,...);
		void printif(bool var, const char *str , ...);

		void log(const char * str, va_list args);
	};
};

namespace QuiL = QuickLib;
namespace Qencrypt = QuickLib::encrypt;
namespace Qdebug = QuickLib::debug;

#endif