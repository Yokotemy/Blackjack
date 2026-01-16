#ifndef CROUPIER_H
#define CROUPIER_H

#include "person.h"

class croupier : public person {
public:
    void playTurn(deck &d) override;
};

#endif
