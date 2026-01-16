#include<iostream>
#include "deck.h"
#include "hand.h"
#include "croupier.h"
#include "game.h"
#include "player.h"
#include "person.h"
#include "card.h"
#include "move.h"



int start(int &round,player &p, croupier &c,deck &d){
    //initialising round & bet, shuffling deck, dealing and showing cards
    //repeatable actions in every round
    int rd = round + 1; 
    int Bet;

    round++;
    std::cout << "Twój obecny balans wynosi: " << p.getBalance() << "\n";
    std::cout << "Postaw zakład: " << std::endl;
    std::cout << "Runda " << rd << std::endl;
    std::cin >> Bet; 
    p.setBet(Bet);

    d.shuffleDeck();

    p.takeCard(d);
    c.takeCard(d);
    p.takeCard(d);
    c.takeCard(d);
    c.getHand(0).getCard(1).hide(); //ukrycie drugiej karty krupiera
    std::cout << "\nTwoja ręka: ";
    p.getHand(0).displayHand();
    std::cout << "\nRęka krupiera: ";
    c.getHand(0).displayHand();

    return Bet;
}

void end(player &p, croupier &c){
    // paying player their win, clearing hands for dealer and player
    //additionally deleting extra hands if player did split

    p.clearHands();
    c.clearHands();
}



int main() {
    int round = 0;
    int bet = 0;
    player p;
    croupier c;
    deck d;

    game g;
    g.setUpGame();

    int decyzja = 1;

    while(decyzja == 1){
        bet = start(round, p, c,d);
        decyzja = g.gameplay(bet,p,c,d);
        end(p,c);
    }

    return 0;
}