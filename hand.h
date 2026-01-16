#ifndef HAND_H
#define HAND_H

#include <vector>
#include "card.h"

class hand {
    std::vector<card> cards;
public:
    void displayHand() const;
    card& getCard(int index);
    void takeCard(card c);
    bool isEmpty() const;
    int calculateHand() const;
    void clear();
};

#endif
