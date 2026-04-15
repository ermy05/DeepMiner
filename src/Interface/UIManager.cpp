#include "UIManager.h"

UIManager::UIManager(ScreenRenderer& screen,World& world) : 
	screen(screen), 
	world(world), 
	cube(5, 9, RenderColor::white),
	rob(5, 9, RenderColor::white)
{
	cube.fillRow(0, "E.+-----+");
	cube.fillRow(1, "+-----+'|");
	cube.fillRow(2, "|#####|#|");
	cube.fillRow(3, "|#####|#+");
	cube.fillRow(4, "+-----+'E");

	rob.fillRow(0, "EEEEEEEEE");
	rob.fillRow(1, "E.-----+E");
	rob.fillRow(2, "+-----+|E");
	rob.fillRow(3, "|o   o|+E");
	rob.fillRow(4, "+-----+'E");
}

void UIManager::render2D(int heightLayer){
	int startX = 1;
	int startY = 30;
	screen.addStringToScreen("2DMap",RenderColor::bold_magenta, startX + 11, startY);
	screen.addStringToScreen(std::string(21, '-'), RenderColor::bold_cyan, startX + 3, startY + 1);
	for (int i = 0;i < 5;i++) {
		std::string output = "| ";
		for (int j = 0; j < 5;j++) {
			output += std::to_string(world.getColumnValueAt(i,j,heightLayer));
			output += " | ";
		}
		screen.addStringToScreen(output, RenderColor::bold_cyan, startX + 3, startY + 2 + (i * 1));
	}
	screen.addStringToScreen(std::string(21, '-'), RenderColor::bold_cyan, startX + 3, startY + 7);
	screen.addStringToScreen("Current shown layer:" + std::to_string(heightLayer), RenderColor::bold_magenta, startX + 3, startY + 8);
}

void UIManager::render3D(int rotation, std::vector<IRobot*> robots){
	int startX = 39;
	int startY = 29;
	int offsetX = 0;
	int offsetY = 0;
	for (int i = 0;i < 5;i++) {
		offsetX = startX - (i * 2);
		for (int j = 0;j < 5;j++) {
			offsetY = startY + i;
			switch (rotation) {
			case 1:
				for (int k = 0; k < world.getColumnSize(j,4 - i); k++) {
					int blockValue = world.getColumnValueAt(j, 4 - i, k);
					screen.addTextureToScreen(&cube, offsetX, offsetY, intToColor(j));
					screen.addStringToScreen(std::to_string(blockValue), RenderColor::green, offsetX + 3, offsetY + 2);
					screen.addStringToScreen(std::to_string(blockValue), RenderColor::green, offsetX + 7, offsetY + 2);
					offsetY -= 3;
				}
				for (int k = 0;k < robots.size();k++) {
					if (robots.at(k)->getX() == j && robots.at(k)->getY() == 4 - i) {
						screen.addTextureToScreen(&rob, offsetX, offsetY);
						screen.addStringToScreen(std::to_string(k + 1), RenderColor::white, offsetX + 3, offsetY + 3);
					}
				}
				break;
			case 2:
				for (int k = 0; k < world.getColumnSize(4 - i,4 - j); k++) {
					int blockValue = world.getColumnValueAt(4 - i, 4 - j, k);
					screen.addTextureToScreen(&cube, offsetX, offsetY, intToColor(4 - i));
					screen.addStringToScreen(std::to_string(blockValue), RenderColor::green, offsetX + 3, offsetY + 2);
					screen.addStringToScreen(std::to_string(blockValue), RenderColor::green, offsetX + 7, offsetY + 2);
					offsetY -= 3;
				}
				for (int k = 0;k < robots.size();k++) {
					if (robots.at(k)->getX() == 4 - i && robots.at(k)->getY() == 4 - j) {
						screen.addTextureToScreen(&rob, offsetX, offsetY);
						screen.addStringToScreen(std::to_string(k + 1), RenderColor::white, offsetX + 3, offsetY + 3);
					}	
				}
				break;
			case 3:
				for (int k = 0; k < world.getColumnSize(4 - j, i); k++) {
					int blockValue = world.getColumnValueAt(4 - j, i, k);
					screen.addTextureToScreen(&cube, offsetX, offsetY, intToColor(4 - j));
					screen.addStringToScreen(std::to_string(blockValue), RenderColor::green, offsetX + 3, offsetY + 2);
					screen.addStringToScreen(std::to_string(blockValue), RenderColor::green, offsetX + 7, offsetY + 2);
					offsetY -= 3;
				}
				for (int k = 0;k < robots.size();k++) {
					if (robots.at(k)->getX() == 4 - j && robots.at(k)->getY() == i) {
						screen.addTextureToScreen(&rob, offsetX, offsetY);
						screen.addStringToScreen(std::to_string(k + 1), RenderColor::white, offsetX + 3, offsetY + 3);
					}
				}
				break;
			default:
				for (int k = 0; k < world.getColumnSize(i, j); k++) {
					int blockValue = world.getColumnValueAt(i, j, k);
					screen.addTextureToScreen(&cube, offsetX, offsetY, intToColor(i));
					screen.addStringToScreen(std::to_string(blockValue), RenderColor::green, offsetX + 3, offsetY + 2);
					screen.addStringToScreen(std::to_string(blockValue), RenderColor::green, offsetX + 7, offsetY + 2);
					offsetY -= 3;
				}
				for (int k = 0;k < robots.size();k++) {
					if (robots.at(k)->getX() == i && robots.at(k)->getY() == j) {
						screen.addTextureToScreen(&rob, offsetX, offsetY);
						screen.addStringToScreen(std::to_string(k + 1), RenderColor::white, offsetX + 3, offsetY + 3);
					}
				}
			}
			offsetX += 6;
		}
	}
}

void UIManager::renderMenu(){
	screen.addStringToScreen(std::string(28, '-'), RenderColor::bold_red, 1, 1);
	screen.addStringToScreen(std::string(28, '-'), RenderColor::bold_red, 1, 10);
	screen.addStringToScreenVertically(std::string(8, '|'), RenderColor::bold_red, 1, 2);
	screen.addStringToScreenVertically(std::string(8, '|'), RenderColor::bold_red, 28, 2);

	screen.addStringToScreen("Game Options:", RenderColor::bold_blue, 2, 2);
	screen.addStringToScreen("1. c (continue/next move)", RenderColor::bold_yellow, 2, 3);
	screen.addStringToScreen("2. q (quit)", RenderColor::bold_yellow, 2, 4);

	screen.addStringToScreen("Map Options:", RenderColor::bold_blue, 2, 6);
	screen.addStringToScreen("1. w (layer down 2DMap)", RenderColor::bold_yellow, 2, 7);
	screen.addStringToScreen("2. e (layer up 2DMap)", RenderColor::bold_yellow, 2, 8);
	screen.addStringToScreen("3. r (rotate 3DMap 90 deg)", RenderColor::bold_yellow, 2, 9);

	screen.addStringToScreenVertically(std::string(38, '|'), RenderColor::green, 29, 1);
}

void UIManager::renderScores(std::vector<IRobot*> robots, int currentRobot){
	int startX = 1;
	int startY = 11;
	screen.addStringToScreen(std::string(28, '-'), RenderColor::bold_magenta, startX, startY);
	screen.addStringToScreen(std::string(28, '-'), RenderColor::bold_magenta, startX, startY + (robots.size() * 2) + 2);
	screen.addStringToScreen("Robots info:", RenderColor::bold_white, startX + 1, startY + 1);
	for (int i = 0;i < robots.size(); i++) {
		int robotX = robots.at(i)->getX();
		int robotY = robots.at(i)->getY();
		int robotScore = robots.at(i)->getScore();
		std::string output;
		output += "Robot " + std::to_string(i + 1) + ":";
		output += "(" + std::to_string(robotX) + "," + std::to_string(robotY) + ")";
		if (i == currentRobot) {
			output += "<";
		}
		screen.addStringToScreen(output, RenderColor::bold_cyan, startX + 1, startY + 2 + (i * 2));
		output = "";
		output += "Score: " + std::to_string(robotScore);
		screen.addStringToScreen(output, RenderColor::bold_cyan, startX + 1, startY + 2 + (i * 2) + 1);
	}
}

void UIManager::reorganizeLog(int type){
	switch (type) {
	case 2:
		screen.addStringToScreen("World was sorted asc", RenderColor::bold_white, 1, 29);
		break;
	case 3:
		screen.addStringToScreen("World was sorted dec", RenderColor::bold_white, 1, 29);
		break;
	default:
		screen.addStringToScreen("World was shuffled", RenderColor::bold_white, 1,29);
		break;
	}
}

void UIManager::effectLog(std::string message){
	screen.addStringToScreen(message, RenderColor::yellow, 1, 20);
}

void UIManager::printScreen() {
	system("cls");
	screen.printScreen();
	screen.clearScreen();
}

RenderColor UIManager::intToColor(int a) {
	switch (a) {
	case 0:
		return RenderColor::magenta;
		break;
	case 1:
		return RenderColor::blue;
		break;
	case 2:
		return RenderColor::cyan;
		break;
	case 3:
		return RenderColor::red;
		break;
	case 4:
		return RenderColor::yellow;
		break;
	default:
		return RenderColor::white;
	}
}