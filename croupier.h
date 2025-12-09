#ifndef BLACKJACK_CROUPIER_H
#define BLACKJACK_CROUPIER_H

#include "person.h"
#include "deck.h"
#include "card.h"
#include "hand.h"

class croupier : person {
    public:
        void showDeck(int round);
        void takeCard(deck& D);
};


#endif //BLACKJACK_CROUPIER_H