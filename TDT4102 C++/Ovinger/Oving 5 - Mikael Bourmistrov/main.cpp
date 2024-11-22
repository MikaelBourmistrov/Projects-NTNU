#include "std_lib_facilities.h"
#include "card.h"
#include "card_deck.h"
#include "blackjack.h"

int main(){
///////////////////////////////////////////////////// [1] Enumerasjoner (10%) /////////////////////////////////////////////////////    
///////// Oppgave f) /////////////
    Rank r = Rank::king;
    Suit s = Suit::hearts;
    string rank = rank_to_string(r);
    string suit = suit_to_string(s);
    cout << "Rank: " << rank << '\t' << "Suit: " << suit << endl;

///////////////////////////////////////////////////// [2] Kortklasse (25%) /////////////////////////////////////////////////////
///////// Oppgave f) /////////////
    Card c{Suit::spades, Rank::ace};
    cout << c.to_string() << endl;
    cout << int(c.get_rank()) << endl;

    cout << (is_ace(c)?"IS Ace":"NOT Ace"); //Stor A på Ace, siden dette er hva vi har navngitt det i mappet
    return 0;
}
