#include "JsonEx.h"

int JsonEx::maxDepth = 100;

template<typename T>
T JsonEx::makeDeepCopy(const T& object) {
    return object;
}

template<typename T>
std::string JsonEx::stringify(const T& object) {
    return "{}";
}

template<typename T>
T JsonEx::parse(const std::string& json) {
    return T();
}
