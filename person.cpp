#include<vector>
#include "person.h"

person::person() {
    name = "Unknown";
    hands.push_back(hand());
}
person::person(std::string& name, std::vector<hand> hands) : name(name) {
    hands.push_back(hand());
}

void person::showDeck() {
    for (hand hand : hands) {
        hand.displayHand();
    }
}

void person::takeCard(deck& D) {
    if (hands[0].isEmpty()) {
        hands[0].takeCard(D.giveCard());
        hands[0].takeCard(D.giveCard());
    }
    else {
        hands[0].takeCard(D.giveCard());
    }
}
void person::setName(std::string &Name) {
    name = Name;
}

hand& person::getHand(int index) {
    return hands[index];
}


