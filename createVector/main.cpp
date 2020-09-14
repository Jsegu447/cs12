#include <iostream>
#include "IntVector.h"
#include <stdexcept>
using namespace std;


int main(){
   IntVector myVector;
    myVector = IntVector();
    cout <<  myVector.empty() << endl;
   
     IntVector myVector2;
    myVector2 = IntVector(2, 4);
    if( myVector2.empty() == false){
        cout << " correct output" << endl;
    }
    else {
        cout << "wrong output" << endl;
    }
  
    cout << myVector2.size() << endl;
    cout << myVector2.capacity() << endl;
    cout << myVector2.at(0) << endl;
    cout << myVector2.at(1) << endl;

    
    IntVector myVector3;
    myVector3 = IntVector(10, 2);
    cout << myVector3.back() << endl;
    cout << myVector3.front() << endl;
    cout << myVector3.at(10) << endl;

    

    
    
    
    
    
    
    
    
    
    
    
    
    
}
