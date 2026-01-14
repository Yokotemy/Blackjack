#ifndef MOVE_STRATEGY_H
#define MOVE_STRATEGY_H

#include <string>

class MoveStrategy {
public:
    virtual std::string getMoveName() = 0;
    virtual ~MoveStrategy() = default;
};

class HitStrategy : public MoveStrategy {
public:
    std::string getMoveName() override { return "hit"; }
};

class StandStrategy : public MoveStrategy {
public:
    std::string getMoveName() override { return "stand"; }
};

class DoubleStrategy : public MoveStrategy {
public:
    std::string getMoveName() override { return "double"; }
};

#endif
