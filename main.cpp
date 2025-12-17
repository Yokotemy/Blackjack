#include<iostream>
#include "deck.h"
#include "hand.h"
#include "croupier.h"
#include "game.h"
#include "player.h"
#include "person.h"
#include "card.h"


void start(int round,player &p, croupier &c,deck &d){
    //initialising round & bet, shuffling deck, dealing and showing cards
    //repeatable actions in every round
    int rd = round;
    int Bet;

    round++;
    std::cout << "Twój obecny balans wynosi: " << p.getBalance() << "\n";
    std::cout << "Postaw zakład: " << std::endl;
    std::cin >> Bet; 
    p.setBet(Bet);

    d.shuffleDeck();

    p.takeCard(d);
    c.takeCard(d);
    p.takeCard(d);
    c.takeCard(d);
    c.getHand(0).getCard(1).hide(); //ukrycie drugiej karty krupiera
    p.getHand(0).displayHand();
    c.getHand(0).displayHand();

}

void end(int wygrana, player &p, croupier &c){
    // paying player their win, clearing hands for dealer and player
    //additionally deleting extra hands if player did split

    p.setBalance(wygrana);
    p.clearHands();
    c.clearHands();
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