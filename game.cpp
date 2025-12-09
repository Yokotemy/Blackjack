#include<iostream>
#include<string>
#include "game.h"
#include "person.h"

game::game() : Player(), Croupier(), Deck() {}
void game::setUpGame() {
    std::string Name;
    std::cout << "Podaj nazwę użytkownika: ";
    std::cin >> Name;
    Player.setName(Name);
}




