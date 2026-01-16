#include "hand.h"
#include <iostream>

void hand::displayHand() const {
    if (cards.empty()) { std::cout << "Pusta reka"; return; }
    for (const auto& c : cards) {
        c.displayCard();
        std::cout << "  ";
    }
}

card& hand::getCard(int index) { return cards.at(index); }
void hand::takeCard(card c) { cards.push_back(c); }
bool hand::isEmpty() const { return cards.empty(); }

int hand::calculateHand() const {
    int sum = 0, aces = 0;
    for (const auto& c : cards) {
        sum += c.getVal();
        if (c.getFace() == Face::ace) aces++;
    }
    while (sum > 21 && aces > 0) { sum -= 10; aces--; }
    return sum;
}

void hand::clear() { cards.clear(); }
