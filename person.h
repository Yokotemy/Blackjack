#ifndef BLACKJACK_PERSON_H
#define BLACKJACK_PERSON_H

#include<vector>
#include<string>
#include "hand.h"
#include "deck.h"

class person {
     protected:
        std::string name;
        std::vector<hand> hands;
    public:
        person();
        person(std::string& name, std::vector<hand> hands);
        void setName(std::string& Name);
        void showDeck();
        void takeCard(deck &D);
};


#endif //BLACKJACK_PERSON_H