#include<iostream>
#include<string>
#include "game.h"
#include "person.h"
#include "hand.h"
#include "croupier.h"
#include "player.h" 

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

int gamehelpy(int wygrana, player &p, int Bet){
    int decyzja = 69;
    p.setBalance(wygrana);
    wygrana = wygrana - Bet; //bo matematycznie zabieramy najpeirw bet wiec trzeba go oddac ale zysk sam w sobie to wygrana - zakład
    std::cout << "Twoja wygrana wynosi: " << wygrana
    << "Twój obecny balans wynosi: " << p.getBalance() << std::endl;
    if (p.getBalance() > 0){
    std::cout << "Czy chcesz kontynuować grę (yes=1/no=0): " << std::endl;
    std::cin >> decyzja;
    switch(decyzja){
        case 0:
            std::cout << "Dzięki za grę!";
            return 0;
        case 1:
            std::cout << "Kolejna runda!";
            return 1;
        }
    }
    else {
        std::cout << "Nie masz już pieniędzy. Koniec gry." << std::endl;
        return 0;}
    //bo nie można kontynuować gry jak sie nie ma pieniędzy
}

int game::res_double(player &p, croupier &c, int Bet, int wygrana, deck &d){
    p.takeCard(d);
    p.setBet(Bet);
    p.showDeck();
    c.getHand(0).getCard(1).show();
    std::cout << "Twój obecny balans: " << p.getBalance() << std::endl;
    std::cout << "Karty krupiera: " << std::endl;
    c.showDeck();
    int res = 67;
    res = compareDecks(p.getHand(0), c.getHand(0));
    switch(res){
        case 0:
            std::cout << "Remis! Twój zakład wraca do Ciebie." << std::endl;
            wygrana = 2*Bet;
            int decyzja = gamehelpy(wygrana, p, Bet);
            return decyzja; 
        case 1:
            std::cout << "Wygrywasz!" << std::endl;
            wygrana = 4*Bet;
            int decyzja = gamehelpy(wygrana, p, Bet);
            return decyzja;
        case 2:
            std::cout << "Przegrywasz." << std::endl;
            wygrana = 0;
            int decyzja = gamehelpy(wygrana, p, Bet);
            return decyzja; 
    }
}


int game::gameplay(int Bet, player &p, croupier &c, deck &d){
    bool f = true;
    int wygrana = 2137;
    while (f){
        std::string move;
        if (p.getHand(0).calculateHand() == 21){
            std::cout << "BLACKJACK! Wygrywasz!\n";
            wygrana = 2.5*Bet;
            int decyzja = gamehelpy(wygrana, p, Bet);
            f = false;
            return decyzja;
        }
        std::cout << "Co chcesz zrobic? (stand/double/hit/split)" << std::endl;
        std::cin >> move;
        if (move == "double"){
            int decyzja = res_double(p,c,Bet,wygrana,d);
            f = false;
            return decyzja;
        }
        else {
            std::cout << "Nie rozponano ruchu. Co chcesz zrobic? (stand/double/hit/split)" << std::endl;
            std::cin >> move;
        }
         
    }
}
