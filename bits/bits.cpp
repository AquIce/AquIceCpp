#include "bits.hpp"

template <typename T, size_t S>
AquIce::bits::BitArray<T, S>::BitArray(T value) {
	for(int i = S - 1; i >= 0; i--) {
		arr[i] = value >= std::pow(2, i);
		value -= arr[i] * std::pow(2, i);
	}
	if(value != 0) {
		throw AquIce::bits::BitRangeException();
	}
}

template <typename T, size_t S>
T AquIce::bits::BitArray<T, S>::value(int start, int end) {
	T value = 0;
	for(int i = start; i < end; i++) {
		value += pow(2, i) * arr[i];
	}
	return value;
}

template <typename T, size_t S>
std::string AquIce::bits::BitArray<T, S>::toString() {
	std::string repr = "";
	for(int i = S - 1; i >= 0; i--) {
		repr += arr[i] ? '1' : '0';
	}
	return repr;
}

template <typename T, size_t S>
bool* AquIce::bits::BitArray<T, S>::operator [](int index) {
	return &(this->arr[index]);
}

template <typename T, size_t S>
T AquIce::bits::BitArray<T, S>::operator!() {
	return this->value(0);
}

template <typename T, size_t S>
AquIce::bits::BitArray<T, S> AquIce::bits::BitArray<T, S>::operator&(BitArray<T, S> other) {
	AquIce::bits::BitArray<T, S> res = {0};
	for(int i = 0; i < S; i++) {
		*res[i] = *(*this)[i] && *other[i];
	}
	return res;
}
template <typename T, size_t S>
AquIce::bits::BitArray<T, S> AquIce::bits::BitArray<T, S>::operator|(BitArray<T, S> other) {
	AquIce::bits::BitArray<T, S> res = {0};
	for(int i = 0; i < S; i++) {
		*res[i] = *(*this)[i] || *other[i];
	}
	return res;
}
template <typename T, size_t S>
AquIce::bits::BitArray<T, S> AquIce::bits::BitArray<T, S>::operator^(BitArray<T, S> other) {
	AquIce::bits::BitArray<T, S> res = {0};
	for(int i = 0; i < S; i++) {
		*res[i] = (*(*this)[i] || *other[i]) && !(*(*this)[i] && *other[i]);
	}
	return res;
}
template <typename T, size_t S>
AquIce::bits::BitArray<T, S> AquIce::bits::BitArray<T, S>::operator~() {
	AquIce::bits::BitArray<T, S> res = {0};
	for(int i = 0; i < S; i++) {
		*res[i] = !(*this)[i];
	}
	return res;
}
template <typename T, size_t S>
AquIce::bits::BitArray<T, S> AquIce::bits::BitArray<T, S>::operator<<(int offset) {
	AquIce::bits::BitArray<T, S> res = {0};
	for(int i = S - 1; i >= offset; i--) {
		*res[S - i - offset] = *(*this)[S - i];
	}
	return res;
}
template <typename T, size_t S>
AquIce::bits::BitArray<T, S> AquIce::bits::BitArray<T, S>::operator>>(int offset) {
	AquIce::bits::BitArray<T, S> res = {0};
	for(int i = offset; i < S; i++) {
		*res[i - offset] = *(*this)[i];
	}
	return res;
}

template <typename T, size_t S> template <size_t S_>
AquIce::bits::BitArray<T, S + S_> AquIce::bits::BitArray<T, S>::operator+(AquIce::bits::BitArray<T, S_> other) {
	AquIce::bits::BitArray<T, S + S_> res = {0};
	for(int i = 0; i < S_; i++) {
		*res[i] = *other[i];
	} for(int i = 0; i < S; i++) {
		*res[i + S_] = *(*this)[i];
	}
	return res;
}

template <typename T>
bool AquIce::bits::get(T value, int index) {
	return (value >> index) & 1ULL;
}
template <typename T, int Nb>
std::array<bool, Nb> AquIce::bits::get(T value, int index) {
	std::array<bool, Nb> res;
	for(int i = index; i > index - Nb; i--) {
		res[index - i] = AquIce::bits::get(value, i);
	}
	return res;
}
template <typename T, int Nb, bool IsT>
T AquIce::bits::get(T value, int index) {
	T res = 0;
	for(int i = index; i > index - Nb; i--) {
		res += AquIce::bits::get(value, i) * std::pow(2, i);
	}
	return res;
}

template <typename T>
void AquIce::bits::set(T* value, int index, bool nval) {
	*value ^= (-nval ^ *value) & (1ULL << index);
}
template <typename T, int Nb>
void AquIce::bits::set(T* value, int index, std::array<bool, Nb> nvals) {
	for(int i = index; i < index + Nb; i++) {
		AquIce::bits::set(value, i, nvals[i - index]);
	}
}
template <typename T, int Nb, bool IsT>
void AquIce::bits::set(T* value, int index, T nval) {
	for(int i = index; i > index - Nb; i--) {
		AquIce::bits::set(value, i, AquIce::bits::get(nval, i - index));
	}
}