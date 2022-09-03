#pragma once
#ifndef _CERVER_KSTRING_KSTRING__
#define _CERVER_KSTRING_KSTRING__

#include <vector>
#include <string>
#include <functional>

namespace Cervice {
	namespace Obj{
		namespace String {

			// 字符拆分 基础整形或浮点变量
			template<typename T> // 字符串 分隔符
			inline std::vector<typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type>
				stringPlist(std::string str, char calm);

			// 字符拆分 自定义拆分类型
			template<typename T> // 字符串 分隔符 转换函数
			inline std::vector<T>
				stringPlist(std::string str, char calm, T(*func)(std::string));

			// 字符转换 基础整形或浮点变量
			template<typename T> // 字符串
			inline typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type
				stringTo(std::string str);

			// 字符拆分 字符串
			std::vector<std::string>
				stringPlist(std::string str, char calm);

			// 将字符串转换为大写
			std::string StringToUpper(std::string str);
			std::string StringToUpper(const char * cstr , size_t lens);

			// 将字符串转换为小写
			std::string StringToLower(std::string str);
			std::string StringToLower(const char * cstr , size_t lens);
		}
	}
}


#include "kString.tpp"

#endif