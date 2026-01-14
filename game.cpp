#include <iostream>
#include <string>
#include "game.h"
#include "person.h"
#include "hand.h"
#include "croupier.h"
#include "player.h" 
#include "move.h"

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

// helper function for payouts
int gamehelpy(int wygrana, player &p, int Bet){
    int decyzja = 69;
    p.setBalance(wygrana);
    wygrana = wygrana - Bet;
    std::cout << "Twoja wygrana wynosi: " << wygrana
              << " Twój obecny balans wynosi: " << p.getBalance() << std::endl;
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
        return 0;
    }
}

int game::res_double(player &p, croupier &c, int Bet, int wygrana, deck &d){
    p.takeCard(d);
    p.setBet(Bet);
    p.showDeck();

    // check if player busted
    if (p.is_busted()){
        std::cout << "Przegrywasz." << std::endl;
        wygrana = 0;
        c.getHand(0).getCard(1).show();
        int decyzja = res_stand(p,c,Bet,wygrana,d);
        return decyzja;
    }

    c.getHand(0).getCard(1).show();

    // check if croupier busted after drawing
    if (c.is_busted()){
        std::cout << "Krupier busted!" << std::endl;
        wygrana = 2*Bet; // example payout
        return gamehelpy(wygrana, p, Bet);
    }

    std::cout << "Twój obecny balans: " << p.getBalance() << std::endl;
    Bet *= 2 ;
    int decyzja = res_stand(p,c,Bet,wygrana,d);
    return decyzja;
}

int game::res_stand(player &p, croupier &c, int Bet, int wygrana, deck &d){
    std::cout << "Karty krupiera: " << std::endl;
    c.showDeck();
    if (c.getHand(0).calculateHand() < 16){
        c.takeCard(d);
        std::cout << "Karty krupiera po dobraniu jednej karty: " << std::endl;
        c.showDeck();

        // check if croupier busted immediately
        if (c.is_busted()){
            std::cout << "Krupier busted! Wygrywasz!" << std::endl;
            wygrana = 2*Bet;
            return gamehelpy(wygrana, p, Bet);
        }
    }

    int res = compareDecks(p.getHand(0), c.getHand(0));
    switch(res){
        case 0:
            std::cout << "Remis! Twój zakład wraca do Ciebie." << std::endl;
            wygrana = Bet;
            return gamehelpy(wygrana, p, Bet); 
        case 1:
            std::cout << "Wygrywasz!" << std::endl;
            wygrana = 2*Bet;
            return gamehelpy(wygrana, p, Bet);
        case 2:
            std::cout << "Przegrywasz." << std::endl;
            wygrana = 0;
            return gamehelpy(wygrana, p, Bet); 
    }
}

int game::gameplay(int Bet, player &p, croupier &c, deck &d){
    bool f = true;
    int wygrana = 2137;
    while (f){
        std::string move;

        // check if player has blackjack
        if (p.getHand(0).calculateHand() == 21){
            std::cout << "BLACKJACK! Wygrywasz!\n";
            wygrana = 2.5*Bet;
            int decyzja = gamehelpy(wygrana, p, Bet);
            f = false;
            return decyzja;
        }

        std::cout << "Co chcesz zrobic? (stand/double/hit/split)" << std::endl;
        MoveStrategy* strat = nullptr;
        std::cin >> move;
        if (move == "stand") strat = new StandStrategy();
        else if (move == "double") strat = new DoubleStrategy();
        else if (move == "hit") strat = new HitStrategy();

        if (!strat) {
            std::cout << "Nieznany ruch\n";
            continue;
        }

        std::string action = strat->getMoveName();
        if (action =="stand"){
            int decyzja = res_stand(p,c,Bet,wygrana,d);
            f = false;
            return decyzja;
        }
        else if (action  == "double"){
            int decyzja = res_double(p,c,Bet,wygrana,d);
            f = false;
            return decyzja;
        }
        else if (action  == "hit"){
            bool flag = true;
            int odp = 420;
            while (flag){
                p.takeCard(d);
                p.showDeck();

                // check if player busted after each hit
                if (p.is_busted()){
                    std::cout << "Przegrywasz. Twoja ręka przekroczyła 21." << std::endl;
                    wygrana = 0;
                    return gamehelpy(wygrana, p, Bet);
                }

                std::cout << "Czy chcesz dobrać koleją kartę? (yes/no)" << std::endl;
                std::cin >> odp;
                switch(odp){
                    case 0:
                        int decyzja = res_stand(p,c,Bet,wygrana,d);
                        flag = false;
                        f = false;
                        return decyzja;
                    case 1:
                        std::cout << "Kolejna runda!" << std::endl;
                        // continue loop to hit again
                        break;
                }
            }
        }
        else {
            std::cout << "Nie rozpoznano ruchu. Co chcesz zrobic? (stand/double/hit/split)" << std::endl;
            std::cin >> move;
        }
    }
}
