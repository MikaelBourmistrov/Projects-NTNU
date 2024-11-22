#include "std_lib_facilities.h"
#include "card_deck.h"
#include "card.h"

Card_deck::Card_deck() {                          // kortstokk med 2-13 spades, så 2-13 kløver etc.
	for (int sds = 0; sds < 4; sds++) {           // sds = standard deck suits
		for (int sdr = 2; sdr < 2 + 13; sdr++) {  // sdr = standard deck ranks
			cards.push_back(Card((Suit)sds, (Rank)sdr));
		}
	}
}

void Card_deck::swap(int from_index, int to_index) {
	Card temp_card = cards[from_index];

	cards[from_index] = cards[to_index];
	cards[to_index] = temp_card;
}

void Card_deck::print() {
	for (Card temp_card : cards) {
		cout << temp_card.to_string() << endl;
	}
}

int random_num_betweeen_limits(int min, int max) {return rand() % (max - min + 1) + min;} // kunne lagt denne under egen header, man gadd ikke. Fant på nett

void Card_deck::shuffle(int shuffle_factor) {
	for (int i = 0; i < shuffle_factor; i++) {
		swap(random_num_betweeen_limits(0, cards.size() - 1), random_num_betweeen_limits(0, cards.size() - 1));   // Selvfølgelig er det smartest her å bruke det vi allerede har, som er swap.
	}
}

Card Card_deck::draw_card() { 
	Card top_card = cards[-1];

    cards.pop_back();
    return top_card;
}