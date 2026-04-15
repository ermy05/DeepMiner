
#include "DeepMiner.h"

using namespace std;

int main()
{
	//screen class
	ScreenRenderer screen(40, 74);
	
	//randomizers
	int seed = 2;
	FixedRandomizer fixedRand(5);
	MarsenneTwister rand(seed);
	
	//player Controllers
	RandomPlayerController rndmController(rand);

	//robot types
	SortingRobot sorterRobot(0, 0, &rndmController);
	DoubleMineRobot doubleRobot(4, 4, &rndmController);
	MiddleMineRobot midleRobot(0, 4 , &rndmController);
	
	std::vector<IRobot*> robots;
	robots.push_back(&sorterRobot);
	robots.push_back(&doubleRobot);
	robots.push_back(&midleRobot);

	//world manager
	World world(rand,rand,rand);

	//ui manager
	UIManager uimanager(screen, world);

	//logic manager
	LogicManager manager(world, uimanager, robots);

	bool loop = true;
	manager.executeInput(' ');
	while (loop) {
		char input;
		std::cin >> input;
		loop = manager.executeInput(input);
	}

	return 0;
}
