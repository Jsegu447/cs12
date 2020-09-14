//
//  main.cpp
//  CS labs
//
//  Created by Jonas Segundo on 1/22/20.
//  Copyright © 2020 Jonas Segundo. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "Distance.h"

using namespace std;

Distance::Distance(){
    feet = 0;
    inches = 0;
}
Distance::Distance(unsigned ft, double inch) {
    feet = ft;
    inches = inch;
    init ();
    while (inches >= 12){
        inches = inches - 12;
        feet += 1;
    }

}


Distance::Distance(double inch) {
    feet = 0;
    inches = inch;
    init();
    while (inches >= 12){
           inches = inches - 12;
        feet += 1;
    }
    
}
unsigned Distance::getFeet() const {
    return feet;
}

double Distance::getInches() const{
    return inches;
}

double Distance::distanceInInches() const{
double totalInches = 0;
    totalInches = (feet *  12) + inches;
    return totalInches;
}

double Distance::distanceInFeet() const {
    double totalFeet;
    double inchCopy = inches;
    double feetCopy = feet;
    while (inches >= 12){
              inchCopy = inchCopy - 12;
        feetCopy += 1;
    }
        totalFeet = feetCopy + (inchCopy/12);
        return totalFeet;
}
    
double Distance::distanceInMeters() const {
        double totalMeters = 0;
        double totalInches = 0;
        totalInches = (feet *  12) + inches;
        totalMeters = totalInches *  0.0254;
        
        return totalMeters;
}

Distance Distance::operator+(const Distance &rhs) const {
    Distance added;
    added.feet = feet + rhs.feet;
    added.inches = inches + rhs.inches;
    if (added.inches >= 12) {
        added.inches -= 12;
        added.feet += 1;
    }
    
    return added;
    
}

Distance Distance::operator-(const Distance &rhs) const {
    Distance subtracted;
   
    if( feet >= rhs.feet &&  inches > rhs.feet ){
        subtracted.feet = (feet - rhs.feet);
        subtracted.inches = (inches - rhs.inches);
    }
    else if ( feet > rhs.feet &&  inches < rhs.feet ){
             subtracted.feet = (feet - rhs.feet) - 1;
             subtracted.inches = (inches - rhs.inches) + 12;
    }
    else {
        subtracted.feet = (rhs.feet - feet);
        subtracted.inches = (rhs.inches - inches);
    }
   
    
    while ( subtracted.inches < 0){
        subtracted.feet -= 1;
        subtracted.inches += 12;
}
    subtracted.init ();
    
   
    return subtracted;
    
}

ostream & operator<<(ostream &out, const Distance &rhs){
    out << rhs.feet << "' " << rhs.inches << '"';

    return out;
}

void Distance::init() {
    if (feet < 0){
        feet = feet * -1;
    }
    if (inches < 0){
        inches = inches * -1;
    }
}
    
    

