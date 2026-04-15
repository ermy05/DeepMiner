#ifndef LOGICMANAGER_H
#define LOGICMANAGER_H

#include <vector>
#include <memory>
#include "World.h"
#include "src/Interface/UIManager.h"
#include "src/Utils/Randomizers/IRandomizer.h"
#include "src/Robots/IRobot.h"

class LogicManager {
public:
	LogicManager(World& world, UIManager& uiManager, std::vector<IRobot*> robots);
	bool executeInput(char input);

private:
	World& world;
	UIManager& uiManager;
	int rotation3D;
	int currentShownLayer;
	std::vector<IRobot*> robots;
	int scoreMilestone = 50;
	int currentRobotIndex;

	bool applyTrapEffect(int trapType, IRobot* robot);
	void nextRobotTurn();

};

#endif