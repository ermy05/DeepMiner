#include "Column.h"

void Column::initialize(IRandomizer& heightRandomizer, IRandomizer& valueRandomizer){
	heightRandomizer.setRange(1, 9);
	//height of the blocks
	int blockCount = heightRandomizer.getValue();

	//include effects in the values
	valueRandomizer.setRange(-2, 9);
	for (int i = 0;i < blockCount;i++) {
		int scoreValue = valueRandomizer.getValue();
		blocks.push_back(scoreValue);
	}
}

int Column::mineTop(){
	if (blocks.empty()) return 0;

	int value = blocks.back();
	blocks.pop_back();
	
	return value;
}

int Column::removeBlockAt(int index) {
	if (index >= blocks.size()) return 0;

	int value = blocks.at(index);
	blocks.erase(blocks.begin() + index);
	return value;
}

int Column::getTop() const{
	if (blocks.empty()) return 0;

	return blocks.back();
}

int Column::getAt(int index) const{
	if (blocks.empty()) return 0;
	if (index >= blocks.size()) return 0;
	
	return blocks.at(index);
}

int Column::getColumnSize() const{
	return blocks.size();
}

void Column::sort(bool asc){
	if (blocks.empty()) return;
	if (asc) {
		std::sort(blocks.begin(), blocks.end());
	}
	else
	{
		std::sort(blocks.begin(), blocks.end(), std::greater());
	}
}

void Column::shuffle(IRandomizer& randomizer){
	if (blocks.size() < 2) {
		return;
	}
	for (int i = blocks.size() - 1; i > 0; --i) {
		randomizer.setRange(0, i);
		int j = randomizer.getValue();
		std::swap(blocks.at(i), blocks.at(j));
	}
}

int Column::ckeckForTrap(){
	for (size_t i = 0; i < blocks.size(); ++i) {
		if (blocks.at(i) < 0) {
			int trapValue = blocks.at(i);

			blocks.at(i) = 0;

			return trapValue;
		}
	}
	return 0;
}

void Column::print() const {
	for (int block : blocks) {
		std::cout << block << " ";
	}
	std::cout << std::endl;
}
