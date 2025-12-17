#include<iostream>
#include<string>
#include "game.h"
#include "person.h"
#include "hand.h"
#include "croupier.h" // tp tez nw czy porebne
#include "player.h" //nw jeszce czy an pewno potrzebne

game::game() : Player(), Croupier(), Deck() {}
void game::setUpGame() {
    std::string Name;
    std::cout << "Podaj nazwę użytkownika: ";
    std::cin >> Name;
    Player.setName(Name);
}

int game::compareDecks(hand& player, hand& croupier){
    int player_value = player.calculateHand();
    int croupier_value = croupier.calculateHand();
    
    if (player_value > croupier_value){
        return 1;
    }
    else if (player_value < croupier_value){
        return 2;
    }
    else {return 0;}
}


