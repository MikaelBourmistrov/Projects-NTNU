#pragma once
#include "card.h"

///////////////////////////////////////////////////// [3] Kortstokklasse (25%) /////////////////////////////////////////////////////
class Card_deck {
    private:
        vector<Card> cards;
       
    public:
        Card_deck();
        void swap(int from_index, int to_index);
        void print();
        void shuffle(int shuffle_factor);
        Card draw_card();
};
