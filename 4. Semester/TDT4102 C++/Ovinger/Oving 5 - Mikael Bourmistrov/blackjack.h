#pragma once
#include "card_deck.h"
#include "card.h"

bool is_ace(Card c);             //Var det dette som mentes med hjelpefunskjon? (Utenfor klassen)

class Blackjack {
    private:
        Card_deck deck;
        vector<Card> player_hand, dealer_hand;
        int player_hand_sum, dealer_hand_sum; 
    public:
        int get_card_value(Card c);
        int get_hand_score(vector<Card>);
        bool ask_player_draw_card();
        void draw_player_card();
        void draw_dealer_card();
        void play_game();
};

// Rakk ikke mer men skal bli ferdig til studdasstimen