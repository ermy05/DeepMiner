#ifndef SORTINGROBOT_H
#define SORTINGROBOT_H

#include <vector>
#include "src/Core/World.h"
#include "src/Robots/IRobot.h"
#include "src/Robots/PlayerControllers/IMoveController.h"

class SortingRobot : public IRobot{
public:
	SortingRobot(int x, int y, IMoveController* controller);
	void action(World& world) override;

};

#endif