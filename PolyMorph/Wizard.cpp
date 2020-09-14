 #include "Character.h"
#include "Wizard.h"
#include <iostream>
#include <string>
using namespace std;

Wizard::Wizard( const string& name, double health, double attackStrength, const int& rank):
Character(WIZARD, name, health, attackStrength), rank(rank)
{

    }

void Wizard::attack(Character& type){
    if(type.getType() == WIZARD){
        Wizard &opp = dynamic_cast<Wizard&>(type);
        cout << "Wizard " << name << " attacks " << opp.getName() << " --- POOF!!" << endl << opp.getName() << " takes " << (static_cast<double>(rank)/opp.rank)*attackStrength << " damage." << endl;
        opp.damage( (static_cast<double>(rank)/opp.rank)*attackStrength);
        return;
        }
    
    
    cout << "Wizard " << this->name << " attacks " << type.getName() << " --- POOF!!" << endl << type.getName() << " takes " << attackStrength << " damage." << endl;
    type.damage(this->attackStrength);
    
}



