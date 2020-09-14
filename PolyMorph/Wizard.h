#ifndef WIZARD_H
#define WIZARD_H
#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

class Wizard : public Character{
public:
    Wizard( const string& name, double health, double attackStrength, const int& rank);
  
    void attack(Character& type);
private:
    int rank;
};
#endif
