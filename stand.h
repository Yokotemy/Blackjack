#include "player_strat.h"

class StandStrategy : public playerStrategy {
public:
    int execute(game& g, int Bet) override;
};
