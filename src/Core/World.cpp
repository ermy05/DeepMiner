#include "World.h"

World::World(IRandomizer& heightRandomizer, IRandomizer& valueRandomizer, IRandomizer& reorganizeRandomizer) :
    heightRandomizer(heightRandomizer),
    valueRandomizer(valueRandomizer),
    reorganizeRandomizer(reorganizeRandomizer)
{
    generateWorld();
}

void World::generateWorld(){
    for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 5; ++y) {
            worldData.at(x).at(y).initialize(this->heightRandomizer, this->valueRandomizer);
        }
    }
}

void World::sortColumn(int x, int y, bool asc){
    if (isOutOfBounds(x,y)) {
        return;
    }

    Column& col = worldData.at(x).at(y);
    col.sort(asc);
}

int World::reorganize(){
    reorganizeRandomizer.setRange(1, 3);
    int choice = reorganizeRandomizer.getValue();

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            Column& col = worldData.at(i).at(j);
            switch (choice) {
            case 1:
                col.shuffle(this->reorganizeRandomizer);
                break;
            case 2:
                col.sort(true);
                break;
            case 3:
                col.sort(false);
                break;
            }
        }
    }
    return choice;
}

int World::mineColumnTop(int x, int y){
    if (isOutOfBounds(x,y)) {
        return 0;
    }

    Column& col = worldData.at(x).at(y);
    int value = col.mineTop();
    return value;
}

int World::mineColumnAt(int x, int y, int index){
    if (isOutOfBounds(x, y)) {
        return 0;
    }

    Column& col = worldData.at(x).at(y);
    int value = col.removeBlockAt(index);
    return value;
}

int World::getColumnValueTop(int x, int y){
    if (isOutOfBounds(x, y)) {
        return 0;
    }

    Column& col = worldData.at(x).at(y);
    int value = col.getTop();
    return value;
}

int World::getColumnValueAt(int x, int y, int index){
    if (isOutOfBounds(x, y)) {
        return 0;
    }

    Column& col = worldData.at(x).at(y);
    int value = col.getAt(index);
    return value;
}

int World::getColumnSize(int x, int y){
    if (isOutOfBounds(x, y)) {
        return 0;
    }

    Column& col = worldData.at(x).at(y);
    int size = col.getColumnSize();
    return size;
}

int World::checkForTrap(int x, int y){
    if (isOutOfBounds(x, y)) {
        return 0;
    }

    Column& col = worldData.at(x).at(y);
    int trap = col.ckeckForTrap();
    return trap;
}

void World::print() const{
    for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 5; ++y) {
            std::cout << "x:" << x << "y:" << y << " ";
            worldData.at(x).at(y).print();
        }
        std::cout << std::endl;
    }
}

bool World::isOutOfBounds(int x,int y) const {
    return x < 0 || x >= 5 || y < 0 || y >= 5;
}
