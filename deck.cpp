#include "deck.h"
#include <algorithm>
#include <ctime>

deck::deck() { shuffleDeck(); }

void deck::shuffleDeck() {
    pile.clear();
    Face fs[] = {Face::two, Face::three, Face::four, Face::five, Face::six, Face::seven, Face::eight, Face::nine, Face::ten, Face::jack, Face::queen, Face::king, Face::ace};
    Color cs[] = {Color::clover, Color::spade, Color::heart, Color::diamond};
    for(int t=0; t<4; t++) for(auto f : fs) for(auto c : cs) pile.push_back(card(f, c));
    std::srand(static_cast<unsigned>(std::time(0)));
    std::random_shuffle(pile.begin(), pile.end());
}

card deck::giveCard() {
    if (pile.empty()) shuffleDeck();
    card c = pile.back();
    pile.pop_back();
    // Logika licznika usunięta - teraz tylko zwracamy kartę
    return c;
}
