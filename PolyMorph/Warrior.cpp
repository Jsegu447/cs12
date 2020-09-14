#include "Character.h"
#include "Warrior.h"
#include <iostream>
#include <string>
using namespace std;



Warrior::Warrior( const string& name, double health, double attackStrength, const string& alligence):
Character(WARRIOR, name, health, attackStrength), alligence(alligence){
    }

void Warrior::attack(Character& type){
    if( type.getType() == WARRIOR){
    Warrior &opp = dynamic_cast<Warrior &>(type);
        if(opp.alligence == this->alligence && opp.getType() == WARRIOR){
        cout << "Warrior " <<  this->name << " does not attack Warrior " << opp.getName() <<"." << endl <<
        "They share an allegiance with " << this->alligence << "." << endl;
        return;
        }
    }
    
     cout << "Warrior " << this->name << " attacks " << type.getName() << " --- SLASH!!" << endl << type.getName() << " takes " << (health/MAX_HEALTH)*attackStrength << " damage." << endl;
    type.damage((health/MAX_HEALTH)*attackStrength);
}
