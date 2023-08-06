#include <iostream>

#include "bits.hpp"
#include "bits.cpp"

int main() {
	int a = 13;
	for(auto el : AquIce::bits::get<int, 3>(a, 2)) {
		std::cout << el << std::endl;
	}
	/* AquIce::bits::set<int, 2>(&a, 0, {1, 1});
	for(auto el : AquIce::bits::get<int, 3>(a, 2)) {
		std::cout << el << std::endl;
	} */
	std::cout << AquIce::bits::get<int, 1, true>(a, 1) << std::endl;
	std::cout << a << std::endl;
	AquIce::bits::set<int, 2, true>(&a, 3, 0);
	std::cout << a << std::endl;
}