#include "Level.h"
#include <iostream>

Level::Level()
    : levelName("Untitled Level"), wave(1) {
}

Level::Level(const std::string& name)
    : levelName(name), wave(1) {
}

void Level::addZombie(const Zombie& z) {
    zombies.push_back(z);
    std::cout << "[Level] " << z.getName() << " added to "
        << levelName << "\n";
}

void Level::printAllZombies() const {
    std::cout << "===== Level: " << levelName
        << " | Wave: " << wave << " =====\n";

    if (zombies.empty()) {
        std::cout << "  (no zombies)\n";
        return;
    }

    for (size_t i = 0; i < zombies.size(); ++i) {
        std::cout << "  [" << i << "] ";
        zombies[i].printStatus();
    }
}

int Level::countAliveZombies() const {
    int count = 0;
    for (size_t i = 0; i < zombies.size(); ++i) {
        if (zombies[i].isAlive()) {
            ++count;
        }
    }
    return count;
}

bool Level::isCleared() const {
    return countAliveZombies() == 0 && !zombies.empty();
}

std::string Level::getName() const { return levelName; }
int Level::getWave() const { return wave; }