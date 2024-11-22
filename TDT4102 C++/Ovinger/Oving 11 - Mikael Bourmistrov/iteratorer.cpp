#include "iteratorer.h"

void replace(std::vector<std::string>& refrenceVector, std::string old, std::string replacement) {
    for (std::vector<std::string>::iterator it = refrenceVector.begin(); it != refrenceVector.end(); it++) {
        if (*it == old) {
            refrenceVector.erase(it);
            refrenceVector.insert(it, replacement);
        }
    }
}

void replace_direct(std::vector<std::string>& refrenceVector, std::string old, std::string replacement) {
    for (std::vector<std::string>::iterator it = refrenceVector.begin(); it != refrenceVector.end(); it++) {
        if (*it == old) { *it = replacement; }
    }
}