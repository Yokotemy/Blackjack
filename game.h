#ifndef BLACKJACK_GAME_H
#define BLACKJACK_GAME_H

#include "deck.h"
#include "croupier.h"
#include "player.h"


class game {
    player Player;
    croupier Croupier;
    deck Deck;
    int bet = 0;
    int round = 1;
    public:
        game();
        void setBet(int Bet);
        void setUpGame();
        void gameplay();
        void compareDecks();

};


#endif //BLACKJACK_GAME_H