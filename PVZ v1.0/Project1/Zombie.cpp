#include "Zombie.h"
#include <iostream>

Zombie::Zombie()
    : name("Normal Zombie"), hp(100), maxHp(100), attack(10) {
}

Zombie::Zombie(const std::string& n, int h, int a)
    : name(n), maxHp(h > 0 ? h : 100), attack(a > 0 ? a : 10) {
    hp = maxHp;
}

bool Zombie::isValidHp(int value) const {
    return value >= 0 && value <= maxHp;
}

void Zombie::setHp(int value) {
    if (isValidHp(value)) {
        hp = value;
    }
    else {
        std::cout << "[Warning] Invalid HP value: " << value << ", rejected.\n";
    }
}

void Zombie::setAttack(int value) {
    if (value > 0) {
        attack = value;
    }
    else {
        std::cout << "[Warning] Invalid attack value: " << value << ", rejected.\n";
    }
}

int Zombie::getHp() const { return hp; }
int Zombie::getMaxHp() const { return maxHp; }
int Zombie::getAttack() const { return attack; }
std::string Zombie::getName() const { return name; }

void Zombie::takeDamage(int damage) {
    if (damage <= 0) {
        std::cout << "[Error] Damage must be positive.\n";
        return;
    }
    hp -= damage;
    if (hp < 0) hp = 0;
    std::cout << name << " took " << damage
        << " damage, HP left: " << hp << "\n";
}

bool Zombie::isDead() const { return hp <= 0; }
bool Zombie::isAlive() const { return hp > 0; }

void Zombie::printStatus() const {
    std::cout << "Name: " << name
        << " | HP: " << hp << "/" << maxHp
        << " | ATK: " << attack << "\n";
}