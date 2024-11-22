#pragma once
#include <iostream>
#include <utility>

class Dummy {
    public:
        int* num;
        Dummy() {
                num = new int{0};
        }

        Dummy(const Dummy& other);

        Dummy& operator = (Dummy rhs); // hvordan fungerer denne? Hvorfor skal det returnere en referanse?

        ~Dummy() {
            delete num;
        }
};

void dummyTest();
