#include "Person.h"

Person::Person(std::string pName, std::string pEmail, std::unique_ptr<Car> pCar): name(pName), email(pEmail), car(std::move(pCar)) { }  // her bruker jeg move for å deklarere at "ownership av uniqepointern går til dem, så man har fortsatt bare en pointer"

std::string Person::getName() const{
    return name;
}

std::string Person::getEmail() const {
    return email;
}

void Person::setEmail(std::string pEmail) { 
    email = pEmail;
}

bool Person::hasAvailableSeats() const {
    return ((car != nullptr) && car->hasFreeSeats());
}

std::ostream& operator << (std::ostream& os, const Person& p) {
    std::string seat = "No";
    if (p.hasAvailableSeats()) seat = "Yes";

    os << "Name: " << p.name << "\nEmail: " << p.email << "\nHas free seats?: " << seat;
    return os;
}