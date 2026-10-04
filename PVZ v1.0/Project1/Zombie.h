#pragma once
#include <string>

class Zombie {
private:
    std::string name;
    int hp;
    int maxHp;
    int attack;

    bool isValidHp(int value) const;

public:
    Zombie();
    Zombie(const std::string& n, int h, int a);

    void setHp(int value);
    void setAttack(int value);

    int getHp() const;
    int getMaxHp() const;
    int getAttack() const;
    std::string getName() const;

    void takeDamage(int damage);
    bool isDead() const;
    bool isAlive() const;
    void printStatus() const;
};