#include<vector>
#include <iostream>
#include "hand.h"


int val(Face f) {
    switch (f) {
        case Face::two: return 2; case Face::three: return 3; case Face::four: return 4;
        case Face::five: return 5; case Face::six: return 6; case Face::seven: return 7;
        case Face::eight: return 8; case Face::nine: return 9; case Face::ten: return 10;
        case Face::jack: return 10; case Face::queen: return 10; case Face::king: return 10; case Face::ace: return 0;
    }
    return 0;
}

void hand::displayHand() {
    if (cards.empty()) {
        std::cout << "Empty hand" << std::endl;
    }
    for (card& c : cards){
        if (c.isVisible()){
            c.displayCard();
        }
        else std::cout << "Hidden card";
        std::cout << " ";
    }
}

card& hand::getCard(int index) {
    return cards[index];
}

void hand::takeCard(card Card) {
    cards.push_back(Card);
}

bool hand::isEmpty() {
    return cards.empty();
}

int hand::calculateHand() {
    int sum = 0;
    int Aces = 0;
    for (card Card : cards) {
        if (Card.getFace() == Face::ace) {
            Aces+=1;
        }
        sum+=val(Card.getFace());
    }
    if (Aces > 0) {
        int max = 21 - sum;
        max<11 ? sum+=1 : sum+=11;
    }
    return sum;
}

/*int sum = 0;
int Aces = 0;
for (card& c : cards) {
    if (c.getFace() == Face::ace) Aces++;
    sum += val(c.getFace());
}
while (Aces > 0) {
    // jeśli dodanie 11 nie spowoduje przekroczenia 21, dodaj 11
    if (sum + 11 <= 21) sum += 11;
    else sum += 1;
    Aces--;
}*/
//taka o implementacje znalazlam bo niby ta nasza ma sie sypac kiedy bedzie wiecej asow ale ja tam nw

card hand::removeCard(int index) {
    card c = cards[index];
    cards.erase(cards.begin() + index);
    return c;
}