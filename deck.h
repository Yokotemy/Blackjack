#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include<vector>
#include "card.h"

class deck {
    std::vector<card> pile;

    public:
        deck();
        void displayDeck(); // wyświetlenie talii
        void shuffleDeck(); // potasowanie talii
        card giveCard(); // zwraca kartę z talii
};


#endif //BLACKJACK_DECK_H