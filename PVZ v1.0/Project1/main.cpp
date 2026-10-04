#include "Zombie.h"
#include "PeaShooter.h"
#include "Level.h"
#include <iostream>

int main() {
    Level level("Level 1-1");

    Zombie z1("Normal Zombie", 100, 10);
    Zombie z2("Cone Zombie", 200, 15);

    level.addZombie(z1);
    level.addZombie(z2);

    level.printAllZombies();
    std::cout << "Alive zombies: " << level.countAliveZombies() << "\n\n";

    PeaShooter shooter("PeaShooter", 100, 60);
    shooter.printStatus();
    std::cout << "\n";

    shooter.attack(&z1);
    shooter.attack(&z1);
    shooter.attack(&z1);
    shooter.attack(nullptr); 

    shooter.attack(&z2);
    shooter.attack(&z2);
    shooter.attack(&z2);
    shooter.attack(&z2);

    std::cout << "\n";
    std::cout << "z2 alive? " << (z2.isAlive() ? "Yes" : "No") << "\n";
    std::cout << "z1 alive? " << (z1.isAlive() ? "Yes" : "No") << "\n";

    std::cout << "\n--- Level status (unaffected by attacks above) ---\n";
    level.printAllZombies();

    return 0;
}