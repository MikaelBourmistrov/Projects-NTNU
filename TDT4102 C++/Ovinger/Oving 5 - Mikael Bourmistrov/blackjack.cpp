#include "blackjack.h"

bool is_ace(Card c) {                                //Var det dette som mentes med hjelpefunskjon? (Utenfor klassen)
    return (rank_to_string(c.get_rank()) == "Ace");
}

int Blackjack::get_card_value(Card c) {
    if (is_ace(c)) return 11;                        //if (is_ace(c)) {int input_number; do {cout << "Vil du at essen skal være verdt 11 eller 1?: "; cin >> input_number;} while (input_number != 11 && input_number != 1);return input_number;}
    else if (int(c.get_rank()) >= 10) return 10;
    else return int(c.get_rank());   
}

int Blackjack::get_hand_score(vector<Card> cards) {
    int score = 0;
    for (Card tempcard : cards) {
        score += get_card_value(tempcard);
        if (is_ace(tempcard) && (score > 21)) score -= 10;}
    return score;
}

bool Blackjack::ask_player_draw_card() {                         // char player_input; cout << "Har du lyst på ett nytt kort? [Y/N]: "; cin >> player_input; return ((player_input == 'Y')?1:0);
    char player_input;
    do {cout << "Har du lyst på ett nytt kort? [Y/N]: ";
    cin >> player_input; 
    } while (player_input != 'Y' && player_input != 'N');
    return ((player_input == 'Y')?true:false);
}

void Blackjack::draw_player_card() {
    player_hand.push_back(deck.draw_card());                 // ikke rett å bruke deck, hvordan aksesere deck-et?
    player_hand_sum = get_hand_score(player_hand);
}

void Blackjack::draw_dealer_card() {
    dealer_hand.push_back(deck.draw_card());
    dealer_hand_sum = get_hand_score(dealer_hand);
}

void Blackjack::play_game() {
    Card_deck cards = Card_deck();
    cards.shuffle(100000);
}