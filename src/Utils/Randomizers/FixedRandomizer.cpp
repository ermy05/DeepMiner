#include "FixedRandomizer.h"

FixedRandomizer::FixedRandomizer(int number){
	this->number = number;
}

int FixedRandomizer::getValue() const{

	return this->number;
}

void FixedRandomizer::setRange(int min, int max){
	return;
}
