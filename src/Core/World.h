#ifndef WORLD_H
#define WORLD_H

#include <array>
#include <vector>
#include "Column.h"
#include "src/Utils/Randomizers/IRandomizer.h"

class World {
public:
	World(IRandomizer& heightRandomizer, IRandomizer& valueRandomizer, IRandomizer& reorganizeRandomizer);
	void generateWorld();
	void sortColumn(int x, int y, bool asc);
	int reorganize();
	int mineColumnTop(int x, int y);
	int mineColumnAt(int x, int y, int index);
	int getColumnValueTop(int x, int y);
	int getColumnValueAt(int x, int y, int index);
	int getColumnSize(int x,int y);
	int checkForTrap(int x, int y);
	bool isOutOfBounds(int x, int y) const;
	void print() const;

private:
	std::array<std::array<Column, 5>, 5> worldData;
	IRandomizer& valueRandomizer;
	IRandomizer& reorganizeRandomizer;
	IRandomizer& heightRandomizer;

};

#endif