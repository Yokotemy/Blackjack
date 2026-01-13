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
        hand& getHand(int index); //zeby moc sie dostac do karty krupiera i ja zakryc
        void clearHands();
        int is_busted();
};


#endif //BLACKJACK_PERSON_H