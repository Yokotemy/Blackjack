#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

class deck {
    std::vector<card> pile;
public:
    deck();
    void shuffleDeck();
    card giveCard();
};

#endif
