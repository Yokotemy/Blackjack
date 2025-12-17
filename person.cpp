#include<vector>
#include "person.h"

person::person() {
    name = "Unknown";
    hands.push_back(hand());
}
person::person(std::string& name, std::vector<hand> hands) : name(name) {
    hands.push_back(hand());
}
/*person::person(std::string& name, std::vector<hand> h) : name(name), hands(h) {
    if (hands.empty()) {
        hands.push_back(hand()); // zawsze dodajemy pierwszą pustą rękę
    }
}
*/
//podobno tak ma byc lepiej ale co ja tam wiem

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
void person::clearHands() {
    if (hands.empty()) return;

    //czysci karty wszystkie
    for (hand& h : hands) {
        h.clear();
    }

    //jakby byl split np to zostawia tylko jedna reke do istnienia
    hand firstHand = hands[0];
    hands.clear(); 
    hands.push_back(firstHand); 
}


