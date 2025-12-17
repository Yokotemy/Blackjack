#ifndef BLACKJACK_HAND_H
#define BLACKJACK_HAND_H

#include <vector>
#include "card.h"

class hand {
    std::vector<card> cards;

    public:
        void displayHand(); // wyświetlenie ręki
        card getCard(int index);
        card removeCard(int index);
        void takeCard(card Card); // wzięcie karty do ręki
        bool isEmpty();
        int calculateHand(); // obliczenie warości ręki
};

#endif //BLACKJACK_HAND_H