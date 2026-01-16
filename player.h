#ifndef PLAYER_H
#define PLAYER_H

#include "person.h"

class player : public person {
    int balance = 0;
public:
    void addBalance(int a) { balance += a; }
    void subBalance(int a) { balance -= a; }
    int getBalance() const { return balance; }
    void playTurn(deck &d) override; // Implementacja w player.cpp
};

#endif
