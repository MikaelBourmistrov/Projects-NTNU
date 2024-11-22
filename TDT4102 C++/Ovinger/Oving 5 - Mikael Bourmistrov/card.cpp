#include "card.h"

///////// Oppgave c-d) /////////////
map<Suit, string> suit_names = { {Suit::spades, "Spades"},
                                 {Suit::clubs, "Clubs" },
								 {Suit::diamonds, "Diamonds"},
								 {Suit::hearts, "Hearts"} };

map<Rank, string> rank_names = { {Rank::two, "Two" },
								 {Rank::three, "Three"},
								 {Rank::four, "Four"},
								 {Rank::five, "Five"},
								 {Rank::six, "Six"},
								 {Rank::seven, "Seven"},
								 {Rank::eight, "Eight"},
								 {Rank::nine, "Nine"},
								 {Rank::ten, "Ten"},
								 {Rank::jack, "Jack"},
								 {Rank::queen, "Queen"},
								 {Rank::king, "King"},
								 {Rank::ace, "Ace"} };

string suit_to_string(Suit s) {return suit_names[s];}

string rank_to_string(Rank r) {return rank_names[r];}

///////////////////////////////////////////////////// [2] Kortklasse (25%) /////////////////////////////////////////////////////
///////// Oppgave b-e) /////////////
Card::Card(Suit suit, Rank rank) {
	s = suit;
	r = rank; 
}

Suit Card::get_suit() {return s;}
Rank Card::get_rank() {return r;}
    
string Card::to_string() {return rank_to_string(r) + " of " + suit_to_string(s);}