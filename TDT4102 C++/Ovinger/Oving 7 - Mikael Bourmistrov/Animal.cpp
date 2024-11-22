#include "std_lib_facilities.h"
#include "Animal.h"

Animal::Animal(int AniAge, const string& AniName) {name = AniName, age = AniAge;}
//string Animal::toString() { return "Animal: " + name + ", " + to_string(age); }

string Dog::toString() { return "Dog: " + name + ", " + to_string(age); };
Dog::Dog(int AniAge, const string& AniName): Animal(AniAge, AniName) { } // dette funker men ikke innenfor klamme? Hva er forskjell generelt sett å initialisere slikt

string Cat::toString() { return "Cat: " + name + ", " + to_string(age); };
Cat::Cat(int AniAge, const string& AniName): Animal(AniAge, AniName) { }

void testAnimal() {
    vector<unique_ptr<Animal>> v;
        // v.emplace_back(new Animal(3, "Fluffy")); // I en abstracgt function må vi ha underklasser som definerer hva en funksjon gjør. Altså alle arveklasser MÅ ha noe som kan ovveride Animal sin toString
        v.emplace_back(new Dog(2, "Fido"));  // trenger ikke new, men vil bare ha praksisen for vanlige pointers
        v.emplace_back(new Cat(1, "Wiskers"));

    for (int i = 0; i < v.size(); i++) cout << v.at(i) -> toString() << endl;
}