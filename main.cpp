#include<iostream>
#include "deck.h"
#include "hand.h"
#include "croupier.h"
#include "game.h"
#include "player.h"
#include "person.h"
#include "card.h"


void start(){
    //wszystko to co sie powtarza na początku każdej rundy tj:
    //runda ++; placingbet; shuffledeck; player karta 2 krupier karta 2
}

void end(){
    // wszystko to co sie powtarza na koncu kazdej rundy tj:
    //wyrownanie balansu; wyczyszczenie reku; 
}



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