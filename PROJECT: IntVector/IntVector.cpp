#include <iostream>
#include <stdexcept>
#include "IntVector.h"
using namespace std;


IntVector::IntVector() {
    sz = 0;
    cap = 0;
    data = nullptr;
}
IntVector::IntVector(unsigned size, int value){
    sz = size;
    cap = size;
    data = new int[size];
    for( unsigned i = 0; i < size; i++){
        data[i] = value;
    }
}

unsigned IntVector::size()const{
    return sz;
}

unsigned IntVector::capacity()const{
    return cap;
}

bool IntVector::empty() const{
    if( sz == 0){
           return true;
       }
       else{
           return false;
       }
}

const int& IntVector:: at(unsigned index) const{
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

IntVector :: ~IntVector(){
    delete[] data;
}

void IntVector::expand(){

    
    if( cap != 0){
    int* tempdata = new int[cap*2];
    for (unsigned i = 0; i <= sz-1; i++){
        tempdata[i] = data[i];
     }
        delete[] data;
        data = tempdata;
        cap *= 2;
    }
    else if (data == nullptr || cap == 0){
        delete[] data;
        data = new int[1];
        cap++;
    }
   
}
 int& IntVector::at(unsigned index){
    if( index >= sz){
        throw out_of_range("IntVector::at_range_check");
    }
    else{
    return data[index];
    }
}

void IntVector::expand(unsigned amount){
    cap = (cap + amount);
    int* tempdata = new int[cap];
          for (unsigned i = 0; i < sz; i++){
              tempdata[i] = data[i];
           }

    delete[] data;
    data = tempdata;
    
    }
    

 int& IntVector::front() {
    return data[0];
}

 int& IntVector::back() {
    return data[sz-1];
}
void IntVector::push_back(int value){
        
if( cap == sz){
    expand();
    sz++;
    data[sz-1] = value;
    }
    
    else{
        sz++;
        data[sz - 1] = value;
    }
   
}

void IntVector::insert(unsigned index, int value){
    if ( (sz+1) > cap){
        expand();
        sz++;
    }
    else {
        sz++;
    }
    if( index >= sz){
        throw out_of_range("IntVector::insert_range_check");
    }
    for( unsigned i = index; i < sz; i++){
        data[i+1] = data[i];
    }
    data[index] = value;
}

void IntVector::erase(unsigned index){
    if( index >= sz){
     throw out_of_range("IntVector::erase_range_check");
    }
    else{
        for(unsigned i = index; i < sz - 1; i++){
            data[i] = data[i+1];
        }
        sz--;
    }
    
}

void IntVector::pop_back(){
    sz--;
}

void IntVector::clear(){
    sz = 0;
}

void IntVector::resize(unsigned size, int value){
    if ( sz > size){
        sz = size;
        return;
    }
    if (size > sz && size < cap){
        int temp = sz;
        sz = size;
        for (unsigned i = temp; i < size ; i++) {
            data[i] = value;
        }
    }
    
    if(size > cap) {
        if (size > cap*2 ){
            expand(size-cap);
            int temp = sz;
            sz = size;
            for (unsigned i = temp; i < size ; i++) {
                data[i] = value;
            }
        }
            else{
                expand();
                int temp = sz;
                sz = size;
                for (unsigned i = temp; i < size ; i++) {
                data[i] = value;
            }
    }
        

}
}
void IntVector::reserve(unsigned n){
    if (n > cap){
        expand(n-cap);
    }
}



void IntVector::assign(unsigned n, int value){
    if ( n > cap){
        if (n > cap*2){
            expand(n-cap);
            sz = n;
            for (unsigned i = 0; i < n; i++){
                data[i] = value;
            }
        }
        else{
            expand();
            sz = n;
            for (unsigned i = 0; i < n; i++){
            data[i] = value;
            }
        }
    }
    else {
        sz = n;
        for (unsigned i = 0; i < n; i++){
        data[i] = value;
        }
    }
        

   
}
