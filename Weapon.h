#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

using namespace std;

struct Weapon {   
    string name;                        // Ime Orožja
    int damage;                        // Koliko damage naredi
    int price;                        // Cena orožja
    bool own;                        // Ali že ima to orožje
};

extern Weapon weapon[];

#endif