#ifndef __AQU_BITS__
#define __AQU_BITS__

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>

namespace AquIce {
	namespace bits {
		class BitRangeException : public std::exception {
		public:
			const char* what() {
				return "Bit Range Exception Error";
			}
		};

		template <typename T = int, size_t S = 8>
		class BitArray {
		protected:
			std::array<bool, S> arr;
		public:
			BitArray(T);
			T value(int, int = S - 1);
			std::string toString();
			bool* operator [](int);
			T operator!();
			BitArray<T, S> operator&(BitArray<T, S>);
			BitArray<T, S> operator|(BitArray<T, S>);
			BitArray<T, S> operator^(BitArray<T, S>);
			BitArray<T, S> operator~();
			BitArray<T, S> operator<<(int);
			BitArray<T, S> operator>>(int);

			template <size_t S_>
			BitArray<T, S + S_> operator+(BitArray<T, S_>);
		};

		template <typename T>
		bool get(T, int);

		template <typename T, int Nb>
		std::array<bool, Nb> get(T, int);

		template <typename T, int Nb, bool IsT>
		T get(T, int);

		template <typename T>
		void set(T*, int, bool);

		template <typename T, int Nb>
		void set(T*, int, std::array<bool, Nb>);

		template <typename T, int Nb, bool IsT>
		void set(T*, int, T);
	}
}

#endif
