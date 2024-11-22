///////////////////////////////////////////////////// [1] Enumerasjoner (10%) /////////////////////////////////////////////////////
#pragma once
#include "std_lib_facilities.h"

///////// Oppgave a-d) /////////////
enum class Suit {spades, clubs, diamonds, hearts}; //Enum0 har verdi 0, rekkefølge av "styrke" til kortet.

enum class Rank {two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

string suit_to_string(Suit type);

string rank_to_string(Rank power); // power kommer fra at høyere tall er "sterkere" i kortspill, både i verdig og størrelse.

///////// Oppgave e) /////////////


///////////////////////////////////////////////////// [2] Kortklasse (25%) /////////////////////////////////////////////////////
///////// Oppgave b-e) /////////////
class Card {
    private:
	    Suit s;
	    Rank r;
    public:
        Card(Suit suit, Rank rank); 
        Suit get_suit();
        Rank get_rank();
        string to_string();
};