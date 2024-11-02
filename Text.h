#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <string>

using namespace std;

struct Texti {   
    string name;                          // Ime lokacije
    string btext[3];                     // Texti na Gumbah
    string text;                        // Opis lokacije
};

extern Texti lokacije[];

#endif