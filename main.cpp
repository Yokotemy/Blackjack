#include<iostream>
#include "deck.h"
#include "hand.h"
#include "croupier.h"
#include "game.h"
#include "player.h"
#include "person.h"
#include "card.h"


void start(int round, int initialBet, player &p, croupier &c,deck &d){
    //wszystko to co sie powtarza na początku każdej rundy tj:
    //runda ++; placingbet; shuffledeck; player karta 2 krupier karta 2
    int rd = round;
    int iB = initialBet;
    int Bet;

    round++;

    std::cout << "Postaw zakład: ";
    std::cin >> Bet; 
    p.setBet(Bet);

    d.shuffleDeck();
    p.takeCard(d);
    c.takeCard(d);
    p.takeCard(d);
    c.takeCard(d);

    c.
    


}

void end(){
    // wszystko to co sie powtarza na koncu kazdej rundy tj:
    //wyrownanie balansu; wyczyszczenie reku 
}



int main() {

    int round = 1;
    int initialBet; //tu trzeba imo cin zrobic i gracz podaje ile ma pieniedzy

    deck Talia;
    Talia.shuffleDeck();
    croupier Krupier;

    Krupier.showDeck(round);
    round++;
    Krupier.showDeck(round);
    Krupier.showDeck(round);

    return 0;
}