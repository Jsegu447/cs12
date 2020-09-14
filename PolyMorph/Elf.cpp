#include "Character.h"
#include "Elf.h"
#include <iostream>
#include <string>
using namespace std;


Elf::Elf( const string& name, double health, double attackStrength, const string& familyName):
Character(ELF, name, health, attackStrength), familyName(familyName){
    }
void Elf::attack(Character& type){
    if( type.getType() == ELF){
        Elf &opp = dynamic_cast<Elf &>(type);
        if(opp.familyName == this->familyName){
        cout << "Elf " <<  this->name << " does not attack Elf " << opp.getName() <<"." << endl <<
        "They are both members of the " << this->familyName << " family." << endl;
        return;
        }
    }
    
    cout << "Elf " << this->name << " shoots an arrow at " << type.getName() << " --- TWANG!!" << endl << type.getName() << " takes " << (health/MAX_HEALTH)*attackStrength << " damage." << endl;
    type.damage((health/MAX_HEALTH)*attackStrength);

}
