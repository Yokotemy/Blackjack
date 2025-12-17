#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include "person.h"

class player: public person {
    int balance = 0;
    bool stand = false;
    public:
        void setBalance(int newBalance);
        void setBet(int B);
        int getBalance();
        void setStand();
        void split(deck &D);
        void setName(std::string& Name);
        void hit(deck &D);
        void setDouble(int Bet,deck &D);

};
//stad chyba wyjebue te setstand itd bo mi lepiej to biedzie spiac w game

#endif //BLACKJACK_PLAYER_H