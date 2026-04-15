#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <string>
#include "ScreenRenderer.h"
#include "src/Core/World.h"
#include "src/Core/Column.h"
#include "src/Robots/IRobot.h"

class UIManager {
public:
	UIManager(ScreenRenderer& screen,World& world);
	void render2D(int heightLayer);
	//0:no rotation, 1:90, 2:180, 3:270
	void render3D(int rotation, std::vector<IRobot*> robots);
	void renderMenu();
	void renderScores(std::vector<IRobot*> robots, int currentRobot);
	void reorganizeLog(int type);
	void effectLog(std::string message);
	void printScreen();
	
private:
	
	ScreenRenderer& screen;
	World& world;

	RenderColor intToColor(int a);
	AsciiTexture cube;
	AsciiTexture rob;
};

#endif