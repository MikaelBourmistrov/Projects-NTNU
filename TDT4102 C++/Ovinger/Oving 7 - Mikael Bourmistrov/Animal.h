#pragma once
#include "std_lib_facilities.h"

/////////////////////////////// [1] Introduksjon til arv og polymorfi (10%) ///////////////////////////////
/////////// Oppgave a) ///////////
// Public: Public funksjoner og variabler kan bli aksesert av hva/hvem som helst som er av klassetypen med public i den
// Private: Private er motsatt, ingen utenfor klassen i seg selv (klasserammene), kan aksesere funksjonene / variablene deklarert
// Protected: My som private, men kan nå også akseseres av arvede klasser (men fortsatt bare innenfor klassen).

class Animal {
    protected:
        int age;
        string name;
    public:
        Animal(int age, const string& name);
        virtual ~Animal() {};
        virtual string toString() = 0;  //om man fjerner virtual vil programmet forstå at pointersene på dog og cat vil kalle Animal::toString, virtual vil gjøre att den kan "overrides".
};

class Dog : public Animal {
    public:
        Dog(int AniAge, const string& AniName);
        string toString() override; 
};

class Cat : public Animal {
    public:
        Cat(int AniAge, const string& AniName);
        string toString() override;
};

void testAnimal();
