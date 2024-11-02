#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <string>

using namespace std;

struct Monster {   
    string name;                          // Ime pošasti
    int health;                          // Health pošasti
    int attect;                         // Attect power
    int money;                         // Gold gain
    int xp;                           // xp gain
};

extern Monster monster[];

#endif