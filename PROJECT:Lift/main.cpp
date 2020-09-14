#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int getLowerIndex(const vector<double>& angle, double userAngle){
    double min = angle.at(0);
    int index = 0;
    for (unsigned int i = 0; i < angle.size() - 1; i++){
        if( angle.at(i + 1) > min && angle.at(i + 1) < userAngle){
            min = angle.at(i+1);
            index = (i + 1);
        }
    }
    return index;
}
int getUpperIndex(const vector<double>& angle, double userAngle ){
    int index;
    for( unsigned int i = 0; i < angle.size(); i++){
        if( angle.at(i) > userAngle){
            index = i;
            i = angle.size();
        }
    }
    return index;
}





void readData(const string& inFile, vector<double>& angle, vector<double>& lift){
    ifstream inFS;
    double angleNum;
    double liftNum;
    
    inFS.open(inFile);
    if (!inFS.is_open()){
        cout <<"Error opening " <<inFile << endl;
        exit(1);
    }
    while(inFS >> angleNum >> liftNum){
        angle.push_back(angleNum);
        lift.push_back(liftNum);
    }
    
}
double interpolation(double userAngle, const vector<double>& angle, const vector<double>& lift){
    double fB;
    int upperIndex;
    int lowerIndex;
   lowerIndex = getLowerIndex( angle, userAngle);
   upperIndex = getUpperIndex( angle, userAngle);
    
    for( unsigned int i  = 0; i < angle.size(); i++ ){
        if(userAngle == angle.at(i)){
            return lift.at(i);
        }
    }
    fB = lift.at(lowerIndex) + ((userAngle - angle.at(lowerIndex))/(angle.at(upperIndex) - angle.at(lowerIndex)))*(lift.at(upperIndex) - lift.at(lowerIndex));
    return fB;
}



bool isOrdered(const vector<double>& list){
if( list.size() > 1){
    for (int unsigned i = 0; i < list.size()-1; i++){
    if ( list.at(i) > list.at(i+1)){
        return false;
    }
  }
}
    return true;
}

void reorder(vector<double>& angle, vector<double>& lift){
    for (unsigned int i = 0; i < angle.size(); i++){
          for (unsigned int j = 0; j < angle.size(); j++){
             if( angle.at(i) <= angle.at(j)){
                swap(angle.at(i), angle.at(j));
                swap(lift.at(i), lift.at(j));
             }
            }
          }

    
}



int main (int argc, char* argv[]) {
    string inputFile;
    int userAngle;
    vector <double> angle;
    vector <double> lift;
    double fB;
    inputFile = argv[1];
    
    readData(inputFile, angle, lift);
    if ( isOrdered(angle) == false){
           reorder(angle,lift);
       }
    
    cout << "Please input flight-path angle: " << endl;
    cin >> userAngle;
    
    if ( userAngle <= angle.at(0) || userAngle >= angle.at(angle.size()-1)){
        cout << "Error. Please enter another angle" << endl;
        cin >> userAngle;
    }
    while (cin.fail()){
        cout << "Error. Please enter another angle" << endl;
        cin.clear();
        cin.ignore();
        cin >> userAngle;
        }
    
    
    
   fB = interpolation(userAngle, angle, lift);
    
    cout << fB << " is the coefficient of lift for angle " << userAngle << endl;
    
    
    
   
    
 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
