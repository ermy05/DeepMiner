#ifndef IRANDOMIZER_H
#define IRANDOMIZER_H

class IRandomizer {
public:
    virtual ~IRandomizer() = default;
    virtual int getValue() const = 0;
    virtual void setRange(int min, int max) = 0;

};

#endif