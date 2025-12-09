#include<iostream>
#include "deck.h"
#include "hand.h"
#include "croupier.h"

int main() {

    int round = 1;
    deck Talia;
    Talia.shuffleDeck();
    croupier Krupier;

    Krupier.showDeck(round);
    round++;
    Krupier.showDeck(round);
    Krupier.showDeck(round);

    return 0;
}