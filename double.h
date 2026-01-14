#include "player_strat.h"

class DoubleStrategy : public playerStrategy {
public:
    int execute(game& g, int Bet) override;
};
