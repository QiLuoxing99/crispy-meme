#include "PeaShooter.h"
#include "Zombie.h"    
#include <iostream>

PeaShooter::PeaShooter()
    : name("PeaShooter"), hp(100), damage(25), attackRange(1) {
}

PeaShooter::PeaShooter(const std::string& n, int h, int a)
    : name(n), hp(h > 0 ? h : 100), damage(a > 0 ? a : 25), attackRange(1) {
}

void PeaShooter::attack(Zombie* target) {
    if (target == nullptr) {
        std::cout << "[Error] Target is null, attack failed.\n";
        return;
    }

    if (!target->isAlive()) {
        std::cout << "[Info] Target " << target->getName()
            << " is already dead.\n";
        return;
    }

    std::cout << name << " attacks " << target->getName() << "!\n";
    target->takeDamage(damage);
}

void PeaShooter::printStatus() const {
    std::cout << "Name: " << name
        << " | HP: " << hp
        << " | ATK: " << damage << "\n";
}