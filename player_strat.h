#ifndef PLAYER_STRATEGY_H
#define PLAYER_STRATEGY_H

class game;

class playerStrategy {
public:
    virtual int execute(game& g, int Bet) = 0;
    virtual ~playerStrategy() = default;
};

#endif
