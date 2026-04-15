#ifndef MERSENNETWISTER_H
#define MERSENNETWISTER_H

#include "src/Utils/Randomizers/IRandomizer.h"
#include <random>

class MarsenneTwister : public IRandomizer {
public:
    MarsenneTwister(int seed);

    int getValue() const override;
    void setRange(int min,int max) override;
private:
    int seed;
    mutable std::mt19937 gen;
    mutable std::uniform_int_distribution<int> distrib;

};

#endif