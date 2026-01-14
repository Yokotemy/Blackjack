#include "player_strat.h"

class HitStrategy : public playerStrategy {
public:
    int execute(game& g, int Bet) override;
};
