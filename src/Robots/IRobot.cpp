#include "IRobot.h"

IRobot::IRobot(int x, int y, IMoveController* controller){
	this->x = x;
	this->y = y;
	this->score = 0;
	this->controller = controller;
}

void IRobot::move(World& world){
	controller->move(this->x, this->y, world);
}

int IRobot::getScore() const{
	return this->score;
}

int IRobot::getX() const{
	return this->x;
}

int IRobot::getY() const{
	return this->y;
}

void IRobot::addScore(int score){
	this->score += score;
}

void IRobot::setX(int x){
	this->x = x;
}

void IRobot::setY(int y){
	this->y = y;
}
