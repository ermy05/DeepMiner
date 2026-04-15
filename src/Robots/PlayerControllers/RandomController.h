#ifndef RANDOMCONTROLLER_H
#define RANDOMCONTROLLER_H

#include <vector>
#include "src/Robots/PlayerControllers/IMoveController.h"
#include "src/Utils/Randomizers/IRandomizer.h"

class RandomPlayerController : public IMoveController{
public:
	RandomPlayerController(IRandomizer& randomizer);
	void move(int& x, int& y, World& world) override;

private:
	IRandomizer& randomizer;
};

#endif