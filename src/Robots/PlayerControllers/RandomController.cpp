#include "RandomController.h"

RandomPlayerController::RandomPlayerController(IRandomizer& randomizer) :
	randomizer(randomizer)
{

}

void RandomPlayerController::move(int& x, int& y, World& world){
	randomizer.setRange(1, 4);
	
	int tempX = 0;
	int tempY = 0;
	do {
		int moveDir = randomizer.getValue();
		tempX = x;
		tempY = y;
		switch (moveDir) {
		case 2:
			tempX++;
			break;
		case 3:
			tempY++;
			break;
		case 4:
			tempX--;
			break;
		default:
			tempY--;
			break;
		}
	} while (world.isOutOfBounds(tempX,tempY));
	x = tempX;
	y = tempY;
	
}
