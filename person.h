#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "hand.h"
#include "deck.h"

class person {
protected:
    std::string name;
    hand myHand;
public:
    virtual ~person() = default;
    void setName(std::string n) { name = n; }
    std::string getName() const { return name; }
    hand& getHand() { return myHand; }
    virtual void playTurn(deck &d) = 0;
    void takeCard(deck &d) { myHand.takeCard(d.giveCard()); }
    bool isBusted() const { return myHand.calculateHand() > 21; }
    void clear() { myHand.clear(); }
};

#endif
