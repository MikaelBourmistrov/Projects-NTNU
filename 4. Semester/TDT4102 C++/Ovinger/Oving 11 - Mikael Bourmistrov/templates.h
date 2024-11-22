#pragma once

#include <algorithm>
#include <random>

template<typename T>
T maximum(T a, T b) {
    return std::max(a, b);
}

template<typename T>
void shuffle(T& v) {
    std::shuffle(v.begin(), v.end(), std::random_device());
}

