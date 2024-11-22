#include "Dummy.h"

void dummyTest() {

//////////////////// Oppgave a) ////////////////////
    Dummy a;
    *a.num = 4;
    Dummy b{a};    // tar en shallow copy av a, og setter b lik pointern til a, altså nå har vi to pointers som peker mot a.
    Dummy c;       
    c = a;         //her tar vi en til shallow copy, bare med annen notason. a og c er jo begge av typen dummys, som inneholder bare en pointer.

    std::cout << "a: " << *a.num << '\n';
    std::cout << "b: " << *b.num << '\n';  //alle printer samme, siden de peker til samme minne adresse, og når vi henter ut pointern (minneadressen) og spørr hva som er i den er det selvfølgelig 4.
    std::cout << "c: " << *c.num << '\n';

    *b.num = 3;    // setter pointern sin minnealokerte verdi (den den peker på) lik 3
    *c.num = 5;    // setter pointern sin minnealokerte verdi (den den peker på) lik 5, siden alle deler samme pointer, vil den peke nå til samme verdi

    std::cout << "a: " << *a.num << '\n';
    std::cout << "b: " << *b.num << '\n'; // printer ut 5
    std::cout << "c: " << *c.num << '\n';
} 

Dummy::Dummy(const Dummy& other): num(new int) {  // hva er forskjellen på dette og hvis jeg tar num(nullptr), this->num = new int (begge er jo allokert i heap og setter av minne som skal overrides)
    *num = *other.num;
}

Dummy& Dummy::operator = (Dummy rhs) {
    std::swap(num, rhs.num);
    return *this;
}

 
