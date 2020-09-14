#ifndef  ELF_H
#define ELF_H
#include "Character.h"
#include <string>
#include <iostream>
using namespace std;

class Elf : public Character{
public:
    Elf( const string& name, double health, double attackStrength, const string& familyName);
    void attack(Character& type);
    
    
private:
    string familyName;
};
#endif
