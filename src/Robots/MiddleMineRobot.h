#ifndef MIDDLEMINEROBOT_H
#define MIDDLEMINEROBOT_H

#include <vector>
#include "src/Core/World.h"
#include "src/Robots/IRobot.h"
#include "src/Robots/PlayerControllers/IMoveController.h"

class MiddleMineRobot : public IRobot {
public:
	MiddleMineRobot(int x, int y, IMoveController* controller);
	void action(World& world) override;

};

#endif