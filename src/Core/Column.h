#ifndef COLUMN_H
#define COLUMN_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "src/Utils/Randomizers/IRandomizer.h"

class Column {
public:
	void initialize(IRandomizer& heightRandomizer, IRandomizer& valueRandomizer);
	int mineTop();
	int removeBlockAt(int index);
	int getTop() const;
	int getAt(int index) const;
	int getColumnSize() const;
	void sort(bool asc);
	void shuffle(IRandomizer& randomizer);
	int ckeckForTrap();
	void print() const ;

private:
	std::vector<int> blocks;
};

#endif