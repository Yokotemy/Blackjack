#include <iostream>
#include <ostream>
#include "card.h"

card::card()
    :face(Face::two), color(Color::clover) {}

card::card(Face face, Color color, bool v)
    :face(face), color(color), visible(v) {}

// wyświetlanie face'a
std::string faceToString(Face f) {
    switch(f) {
        case Face::two: return "2"; case Face::three: return "3"; case Face::four: return "4";
        case Face::five: return "5"; case Face::six: return "6"; case Face::seven: return "7";
        case Face::eight: return "8"; case Face::nine: return "9"; case Face::ten: return "10";
        case Face::jack: return "Jack"; case Face::queen: return "Queen"; 
        case Face::king: return "King"; case Face::ace: return "Ace";
    }
    return "?";
}

// wyświetlanie koloru
std::string colorToString(Color c) {
    switch(c) {
        case Color::clover: return "Clover";
        case Color::spade: return "Spade";
        case Color::heart: return "Heart";
        case Color::diamond: return "Diamond";
    }
    return "?";
}

void card::hide(){
    visible = false;
}

void card::show(){
    visible = true;
}

bool card::isVisible(){
    return visible;
}

void card::displayCard() {
    if (!visible){
        std::cout << "Hidden card";
        return;
    }
    std::cout << faceToString(face) << ' ' << colorToString(color) << std::endl;
}

Face card::getFace() {
    return face;
}
