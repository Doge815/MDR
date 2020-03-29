#pragma once
#include <cstdint>

template <size_t dimensions, typename T> struct vec
{
private:
    T values[dimensions];
public:
    vec()
    { 
        for (size_t i = 0; i < dimensions; values[i++] = T());
    }

    T& operator[](const size_t i) { assert(i < dimensions); return values[i]; }
};

typedef vec<3, double> Vec3d;
typedef vec<3, uint8_t> Color;

template<size_t dimensions, typename T> T operator*(const vec<dimensions, T>& lhs, const vec<dimensions, T>& rhs) {
    T ret = T();
    for (size_t i = dimensions; i--; ret += lhs[i] * rhs[i]);
    return ret;
}

template<size_t dimensions, typename T>vec<dimensions, T> operator+(vec<dimensions, T> lhs, const vec<dimensions, T>& rhs) {
    for (size_t i = dimensions; i--; lhs[i] += rhs[i]);
    return lhs;
}

template<size_t dimensions, typename T>vec<dimensions, T> operator-(vec<dimensions, T> lhs, const vec<dimensions, T>& rhs) {
    for (size_t i = dimensions; i--; lhs[i] -= rhs[i]);
    return lhs;
}