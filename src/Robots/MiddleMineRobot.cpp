#include "MiddleMineRobot.h"

MiddleMineRobot::MiddleMineRobot(int x, int y, IMoveController* controller) : IRobot(x,y,controller){
}

void MiddleMineRobot::action(World& world){
	world.sortColumn(getX(), getY(), false);
	int columnMiddle = world.getColumnSize(getX(), getY()) / 2;
	int minedBlockValue = world.mineColumnAt(getX(), getY(), columnMiddle);
	addScore(minedBlockValue);
}
