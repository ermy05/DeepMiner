#ifndef IROBOT_H
#define IROBOT_H

#include <vector>
#include "src/Core/World.h"
#include "src/Robots/PlayerControllers/IMoveController.h"


class IRobot {
public:
	IRobot(int x,int y,IMoveController* controler);
	virtual ~IRobot() = default;

	virtual void action(World& world) = 0;
	void move(World& world);

	int getScore() const;
	int getX() const;
	int getY() const;

	void addScore(int score);
	void setX(int x);
	void setY(int y);

protected:
	int x;
	int y;
	int score;
	IMoveController* controller;
};

#endif