#include "croupier.h"

void croupier::playTurn(deck &d) {
    myHand.getCard(1).show();
    while (myHand.calculateHand() < 17) {
        takeCard(d);
    }
}
