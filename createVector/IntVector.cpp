#include "IntVector.h"
#include <iostream>
#include <stdexcept>
using namespace std;

IntVector::IntVector(){
    sz = 0;
    cap = 0;
    data = nullptr;
}

bool IntVector::empty()const{
    if( sz == 0){
        return true;
    }
    else{
        return false;
    }
    
}
IntVector :: ~IntVector(){
    delete[] data;
}

IntVector::IntVector(unsigned size,int value ){
sz = size;
cap = size;
data = new int[size];
for (unsigned i = 0; i < size; i++){
    data[i] = value;
  }
 
}
unsigned IntVector::size() const {
    return sz;
}

unsigned IntVector::capacity() const {
    return cap;
}
const int& IntVector::at(unsigned index) const{
    if( index >= sz){
        throw out_of_range("IntVector::at_range_check");
    }
    else{
    return data[index];
    }
}
const int& IntVector::front() const{
    return data[0];
}

const int& IntVector::back() const{
    return data[sz-1];
}


