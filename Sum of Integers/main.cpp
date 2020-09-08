#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string fileName){
    int sum = 0;
    int num;
    ifstream inFS;
    inFS.open(fileName);
     if (!inFS.is_open()){
        cout << "Error opening " << fileName << endl;
        return 1;
    }
    while (inFS >> num){
        sum += num;
       }
    inFS.close();
    
    
    
    
    return sum;
}


int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);
    if(sum > 1){
   cout << "Sum: " << sum << endl;
    }
   return 0;
}

// Place fileSum implementation here
