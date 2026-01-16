#ifndef MOVE_H
#define MOVE_H

#include <string>

class MoveStrategy {
public:
    virtual ~MoveStrategy() = default;
    virtual std::string getMoveName() const = 0;
};

class HitStrategy : public MoveStrategy {
public:
    std::string getMoveName() const override { return "hit"; }
};

class StandStrategy : public MoveStrategy {
public:
    std::string getMoveName() const override { return "stand"; }
};

class DoubleStrategy : public MoveStrategy {
public:
    std::string getMoveName() const override { return "double"; }
};

#endif
