#include "DoubleMineRobot.h"

DoubleMineRobot::DoubleMineRobot(int x, int y, IMoveController* controller) : IRobot(x, y, controller){
}

void DoubleMineRobot::action(World& world){
	int minedBlockValue = world.mineColumnTop(getX(), getY());
	int minedBlockValue2 = world.mineColumnTop(getX(), getY());
	addScore(minedBlockValue);
	addScore(minedBlockValue2);
}
