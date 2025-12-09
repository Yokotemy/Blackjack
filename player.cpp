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
