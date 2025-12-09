#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include "person.h"

class player: person {
    int balance = 0;
    bool stand = false;
    public:
        void setBalance(int newBalance);
        void setBet(int B);
        int getBalance();
        void setStand();
        void split();
};


#endif //BLACKJACK_PLAYER_H