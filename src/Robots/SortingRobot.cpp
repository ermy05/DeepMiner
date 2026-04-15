#include "SortingRobot.h"

SortingRobot::SortingRobot(int x, int y, IMoveController* controller) : IRobot(x,y,controller){

}

void SortingRobot::action(World& world){
	world.sortColumn(getX(),getY(),true);
	int minedBlockValue = world.mineColumnTop(getX(), getY());
	addScore(minedBlockValue);
}
