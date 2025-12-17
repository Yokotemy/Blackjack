#ifndef BLACKJACK_CROUPIER_H
#define BLACKJACK_CROUPIER_H
//tbf nie wiem czy ta kalsa wgl jest potzrebna bo w sumie croupier moze byc stricte jako osoba?
//bo showdeck i takecard to sa chyba te same co ma osoba
#include "person.h"
#include "deck.h"
#include "card.h"
#include "hand.h"

class croupier : public person {
    /*public:
        void showDeck(int round);
        void takeCard(deck& D);*/
};


#endif //BLACKJACK_CROUPIER_H