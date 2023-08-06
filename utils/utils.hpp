#ifndef __AQU_UTILS__
#define __AQU_UTILS__

#include <string>
#include <vector>

namespace std {
	std::vector<std::string> split(const std::string& s, const std::string& delim);
	
	/* template <typename T>
	class dynamic_array : public std::vector<T> {
	public:
		dynamic_array() : std::vector<T>();
		dynamic_array(...T) : std::vector<T>(T...);
		dynamic_array<T> operator+(std::dynamic_array<T>);
		dynamic_array<T> operator+(std::vector<T>);
		dynamic_array<T> operator+(T);
	}; */
}

#endif