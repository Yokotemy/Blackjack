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
        void setBet(int Bet); //jak to jest w player tez to chyba nie trzeba rozpisywac tego 
        //w game.cpp cn
        void setUpGame();
        int gameplay(int Bet, player &p, croupier &c, deck &d);//bedzie zwracac czy gracz chce kolejne rundy(1) czy konczy(0)
        int compareDecks(hand& player, hand& croupier); //ja bym zrobila int gdzie np 0-to samo, 1-gracz wincyj, 2-krupier wincyj
        int res_double(player &p, croupier &c, int Bet, int wygrana,deck &d);
        int res_stand(player &p, croupier &c, int Bet, int wygrana,deck &d);
        


};


#endif //BLACKJACK_GAME_H