#ifndef IFIXEDRANDOMIZER_H
#define IFIXEDRANDOMIZER_H

#include "src/Utils/Randomizers/IRandomizer.h"

class FixedRandomizer : public IRandomizer {
public:
    FixedRandomizer(int number);

    int getValue() const override;
    void setRange(int min, int max) override;
private:
    int number;
};

#endif