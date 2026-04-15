#include "LogicManager.h"

LogicManager::LogicManager(World& world, UIManager& uiManager , std::vector<IRobot*> robots) 
	: world(world), uiManager(uiManager) , robots(std::move(robots))
{
	rotation3D = 0;
	currentShownLayer = 0;
	currentRobotIndex = 0;
}

bool LogicManager::executeInput(char input){
	int layerCheck;
	switch (input) {
	case 'q':
		return false;
		break;
	case 'e':
		layerCheck = currentShownLayer + 1;
		if (layerCheck <= 9) {
			currentShownLayer++;
		}
		break;
	case 'w':
		layerCheck = currentShownLayer - 1;
		if (layerCheck >= 0) {
			currentShownLayer--;
		}
		break;
	case 'r':
		rotation3D++;
		if (rotation3D == 4) rotation3D = 0;
		break;
	case 'c': {
		int i = currentRobotIndex;
		robots.at(i)->move(world);

		int trapValue = world.checkForTrap(robots.at(i)->getX(), robots.at(i)->getY());
		bool canMine = applyTrapEffect(trapValue, robots.at(i));

		if (canMine) {
			robots.at(i)->action(world);
		}

		if (robots.at(i)->getScore() > scoreMilestone) {
			scoreMilestone += 50;
			int reorganizeType = world.reorganize();
			uiManager.reorganizeLog(reorganizeType);
		}
		nextRobotTurn();
		break;
	}
	default:
		break;
	}
	uiManager.renderScores(robots, currentRobotIndex);
	uiManager.render2D(currentShownLayer);
	uiManager.render3D(rotation3D, robots);
	uiManager.renderMenu();
	uiManager.printScreen();
	return true;
}

bool LogicManager::applyTrapEffect(int trapType, IRobot* robot){
	if (trapType == 0) return true;

	std::string message = "Robot " + std::to_string(currentRobotIndex + 1);
	if (trapType == -1) {
		message += " lost its turn.";
	}
	else if (trapType == -2) {
		int minVal = world.getColumnValueTop(0, 0);
		int targetX = robot->getX();
		int targetY = robot->getY();

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				int val = world.getColumnValueTop(i,j);
				if (val < minVal) {
					minVal = val;
					targetX = i;
					targetY = j;
				}
			}
		}
		robot->setX(targetX);
		robot->setY(targetY);

		message += " was teleported.";
	}

	uiManager.effectLog(message);
	return false;
}

void LogicManager::nextRobotTurn(){
	currentRobotIndex++;
	if (currentRobotIndex >= robots.size()) {
		currentRobotIndex = 0;
	}
}
