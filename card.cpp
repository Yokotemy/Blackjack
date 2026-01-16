#include "card.h"
#include <iostream>

card::card() : face(Face::two), color(Color::clover), visible(true) {}
card::card(Face f, Color c, bool v) : face(f), color(c), visible(v) {}

int card::getVal() const {
    switch (face) {
        case Face::ace: return 11;
        case Face::jack: case Face::queen: case Face::king: case Face::ten: return 10;
        default: return static_cast<int>(face) + 2;
    }
}

void card::displayCard() const {
    if (!visible) { std::cout << "[???]"; return; }
    const std::string f[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    const std::string c[] = {"Trefl", "Pik", "Kier", "Karo"};
    std::cout << f[static_cast<int>(face)] << " " << c[static_cast<int>(color)];
}

Face card::getFace() const { return face; }
void card::show() { visible = true; }
void card::hide() { visible = false; }
bool card::isVisible() const { return visible; }
