#include "MersenneTwister.h"

MarsenneTwister::MarsenneTwister(int seed) : gen(seed) , distrib(1,5){
	this->seed = seed;
	
}

int MarsenneTwister::getValue() const{
	return distrib(gen);
}

void MarsenneTwister::setRange(int min,int max) {
	using param_t = std::uniform_int_distribution<int>::param_type;
	distrib.param(param_t(min, max));
}
