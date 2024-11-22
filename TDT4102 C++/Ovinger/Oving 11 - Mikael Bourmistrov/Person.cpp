#include "Person.h"

Person::Person(std::string fornavn, std::string etternavn): mFornavn(fornavn), mEtternavn(etternavn) { }

std::string Person::getName() const {
    return mFornavn;
}

std::string Person::getSurname() const {
    return mEtternavn;
}

std::ostream& operator << (std::ostream& os, const Person& person) {
    return os << person.getName() << " " << person.getSurname();
}

////////////////////// Alfabetisk sortering og innseting //////////////////////
void insertOrdered(std::list<Person>& l, const Person& p) {  /// se video, while tp!= nullptr
    if (l.size() == 0) { l.emplace_front(p); }
    else {
        std::list<Person>::iterator it = l.begin();

        while (it != l.end()) {
            if (it->getName() == p.getName()) {
                if (it->getSurname() > p.getSurname()) { l.insert(it, p); }
                else { it++; l.insert(it, p); }
                return;
            }
            else {
                if (it->getName() > p.getName()) { 
                l.insert(it, p);
                return;
                }
            }
            it++; 
        }

        l.insert(l.end(), p);
    }     
}