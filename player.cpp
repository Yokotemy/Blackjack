#include "player.h"

void player::setBalance(int newBalance) {
    balance+=newBalance;
}
void player::setBet(int B) {
    balance-=B;
}
int player::getBalance() {
    return balance;
}
void player::setStand() {
    stand = true;
}
//jak cos to ja nie mam za bardzo pojecia co robie i to moze byc zle xd 
void player::hit(deck &D){
    takeCard(D);
}
void player::setDouble(int Bet,deck &D){
    takeCard(D);
    setBet(Bet);
}

