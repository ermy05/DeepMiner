#ifndef DOUBLEMINEROBOT_H
#define DOUBLEMINEROBOT_H

#include <vector>
#include "src/Core/World.h"
#include "src/Robots/IRobot.h"
#include "src/Robots/PlayerControllers/IMoveController.h"

class DoubleMineRobot : public IRobot {
public:
	DoubleMineRobot(int x, int y, IMoveController* controller);
	void action(World& world) override;

};

#endif