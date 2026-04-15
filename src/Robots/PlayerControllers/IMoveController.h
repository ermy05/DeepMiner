#ifndef PLAYERCONTROLER_H
#define PLAYERCONTROLER_H

#include <vector>
#include "src/Core/World.h"
#include "src/Utils/Randomizers/IRandomizer.h"

class IMoveController {
public:
	virtual ~IMoveController() = default;
	virtual void move(int& x, int& y, World& world) = 0;
};

#endif