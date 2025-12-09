#include <ctime>
#include <iostream>
#include <ostream>
#include <random>
#include "deck.h"

// pomocnicze listy do budowy talii
static Face faces[] = {
    Face::two, Face::three, Face::four, Face::five,
    Face::six, Face::seven, Face::eight, Face::nine, Face::ten,
    Face::jack, Face::queen, Face::king, Face::ace};

static Color colors[] = {Color::clover, Color::spade, Color::heart, Color::diamond};


deck::deck(){
    for (Face f : faces) {
        for (Color c : colors) {
            pile.push_back(card(f, c));
        }
    }
}


void deck::displayDeck() {
    for (int i = 0; i < 52; i++) {
        pile[i].displayCard();
    }
    std::cout << std::endl;
}

void deck::shuffleDeck() {
    std::cout << "Shuffling deck..." << std::endl;
    std::srand(time(nullptr));
    for (size_t i = pile.size()-1; i>0; i--) {
        int j = rand() % (i+1);
        card tmp = pile[i];
        pile[i] = pile[j];
        pile[j] = tmp;
    }
}

card deck::giveCard() {
    if (pile.empty()) {
        std::cout << "Deck is empty." << std::endl;
    }
    card tmp = pile.back();
    pile.pop_back();
    return tmp;
}