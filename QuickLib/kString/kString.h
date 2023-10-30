#pragma once
#ifndef _QUICKLIB_KSTRING_KSTRING__
#define _QUICKLIB_KSTRING_KSTRING__

#include <vector>
#include <string>
#include <functional>
#include <optional>

namespace QuickLib {
	namespace Obj{
		namespace String {

			// 基于字符判断 字符拆分 基础整形或浮点变量
			template<typename T> // 字符串 分隔符
			inline std::vector<typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type>
				stringSplit(std::string str, char calm);

			// 基于字符判断 字符拆分 自定义拆分类型
			template<typename T> // 字符串 分隔符 转换函数
			inline std::vector<T>
				stringSplit(std::string str, char calm, T(*func)(std::string));

			// 字符拆分 基础整形或浮点变量
			template<typename T> // 字符串 分隔符
			inline std::vector<typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type>
				stringSplit(std::string str, std::string calm);

			// 基于字符判断 字符拆分 自定义拆分类型
			template<typename T> // 字符串 分隔符 转换函数
			inline std::vector<T>
				stringSplit(std::string str, std::string calm, T(*func)(std::string));

			// 基于字符 字符拆分 字符串
			std::vector<std::string>
				stringSplit(std::string str, char calm);

			// 基于字串 字符拆分 字符串
			std::vector<std::string>
				stringSplit(std::string str, std::string calm);

			// 基于字串判断 字符转换 基础整形或浮点变量
			template<typename T> // 字符串 是否成功判断
			inline typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type
				stringTo(std::string str,bool * has = nullptr);

			// 变量转换 基础整形或浮点变量 尝试转换成字符串
			template<typename T> // 字符串 是否成功判断
			std::string	stringFrom(typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type num , bool* has = nullptr);

			// 基于字符串分割
			std::optional<std::pair<std::string,std::string>>
				cutString(std::string str, std::string calm);

			// 将字符串转换为大写
			std::string StringToUpper(std::string str);
			std::string StringToUpper(const char * cstr , size_t lens);

			// 将字符串转换为小写
			std::string StringToLower(std::string str);
			std::string StringToLower(const char * cstr , size_t lens);

			// 删除字符串开头和结尾空白符
			std::string StringTirm(std::string);

			// 查找指定字符串出现的次数
			size_t StringCount(std::string,std::string);

			// 字符串替换 源 目标 替换 次数(-1 全部)
			std::string StringReplace(std::string txt, std::string sub, std::string ne, int count = -1);

			// 正向查找字符串下标 源 目标 次数(-1 全部)
			std::vector<size_t> StringFindIndex(std::string, std::string, long);

			// 正向查找字符串下标 源 非目标 次数(-1 全部)
			std::vector<std::pair<std::size_t,std::string>>
				StringNotFindIndex(std::string, std::string, long);

			// 反向查找字符串下标 源 目标 次数(-1 全部)
			std::vector<size_t> StringrFindIndex(std::string, std::string, long);

			// 反向查找字符串下标 源 非目标 次数(-1 全部)
			std::vector<std::pair<std::size_t, std::string>>
				StringNotrFindIndex(std::string, std::string, long);
		}
	
		namespace Convert
		{
#ifdef _WIN32
			std::wstring GbkToUtf8(std::string_view src_str);
			std::string Utf8ToGbk(std::wstring_view src_str);
#else
			int GbkToUtf8(char* str_str, size_t src_len, char* dst_str, size_t dst_len);
			int Utf8ToGbk(char* src_str, size_t src_len, char* dst_str, size_t dst_len);
#endif
		}
	}
}


#include "kString.tpp"

#endif