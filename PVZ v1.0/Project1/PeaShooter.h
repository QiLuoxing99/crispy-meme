#pragma once
#include <string>

class Zombie;

class PeaShooter {
private:
    std::string name;
    int hp;
    int damage;     
    int attackRange;

public:
    PeaShooter();
    PeaShooter(const std::string& n, int h, int a);
    void attack(Zombie*target);

    void printStatus() const;
};
