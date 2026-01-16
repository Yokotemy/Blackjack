#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "croupier.h"

class game {
public:
    void setUpGame(player &p);
    void start(player &p, croupier &c, deck &d);
    void displayState(player &p, croupier &c, bool hideDealer) const;
    std::string getHint(int pSum, int dVisible) const;
};

#endif
