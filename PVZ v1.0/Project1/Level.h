#pragma once
#include <string>
#include <vector>
#include "Zombie.h" 

class Level {
private:
    std::string levelName;
    int wave;
    std::vector<Zombie> zombies; 

public:
    Level();
    Level(const std::string& name);

    void addZombie(const Zombie& z);
    void printAllZombies() const;
    int countAliveZombies() const;
    bool isCleared() const;

    std::string getName() const;
    int getWave() const;
};