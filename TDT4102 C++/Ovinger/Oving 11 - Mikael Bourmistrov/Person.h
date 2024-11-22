#pragma once

#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include <set>
#include <list>

class Person {
    private:
        std::string mFornavn;
        std::string mEtternavn;
    public:
        Person(std::string fornavn, std::string etternavn);
        std::string getName() const;
        std::string getSurname() const;
        friend std::ostream& operator << (std::ostream& os, const Person& person);
};
void insertOrdered(std::list<Person>& l, const Person& p);