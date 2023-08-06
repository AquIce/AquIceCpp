#include "utils.hpp"

std::vector<std::string> std::split(const std::string& s, const std::string& delim) {
	std::vector<std::string> result;
	std::string::size_type act = 0;
	std::string::size_type prev = 0;
	while((act = s.find(delim, prev)) != std::string::npos) {
		result.push_back(s.substr(prev, act - prev));
		prev = act + delim.size();
	}
	result.push_back(s.substr(prev));
	return result;
}

/* template <typename T>
std::dynamic_array<T>::dynamic_array() : std::vector<T>() {}
template <typename T>
std::dynamic_array<T> std::dynamic_array<T>::operator+(std::dynamic_array<T> other) {
	std::dynamic_array<T> res = std::dynamic_array<T>();
	for(T el : this) {
		res.push_back(el);
	} for(T el : other) {
		res.push_back(el);
	}
	return res;
}
template <typename T>
std::dynamic_array<T> std::dynamic_array<T>:: operator+(std::vector<T>) {

}
template <typename T>
std::dynamic_array<T> std::dynamic_array<T>::operator+(T) {

} */