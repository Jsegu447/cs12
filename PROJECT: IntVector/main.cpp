#include <iostream>
#include <stdexcept>
#include "IntVector.h"
using namespace std;

int main(){
    
    IntVector myvector1;
    IntVector myvector2;
    IntVector myvector3;
    
    myvector1 = IntVector(); // empty vec
    myvector2 = IntVector(20); // using default val 0
    myvector3 = IntVector(10,100); // both vals
   
    // .size()
    if (myvector1.size() == 0){
        cout << "size test empty vec passed :D" << endl;
    }
    if (myvector2.size() == 20){
        cout << "size test default val passed :D" << endl;
    }
    if (myvector3.size() == 10){
        cout << "size test both val passed :D" << endl;
    }
    
    // .capacity()
    if (myvector1.capacity() == 0){
           cout << "capacity test empty vec passed :D" << endl;
    }
    if (myvector2.capacity() == 20){
           cout << "capacity test default val passed :D" << endl;
    }
    if (myvector3.capacity() == 10){
           cout << "capacity test both val passed :D" << endl;
    }
    
    // .empty()
    if (myvector1.empty() == true){
            cout << "empty test for empty vec passed :D" << endl;
    }
     if (myvector2.empty() == false){
            cout << "empty test default val passed :D" << endl;
    }
     if (myvector3.empty() == false){
            cout << "empty test both val passed :D" << endl;
    }
      
    //.at()  ( read only)
    
    if (myvector2.at(0) == 0){
               cout << "at read test default val passed :D" << endl;
    }
    if (myvector3.at(0) == 100){
               cout << "at read test both val passed :D" << endl;
    }
         
    // at() mutator
    myvector2.at(0) = 20;
    myvector3.at(0) = 2;
    
    if (myvector2.at(0) == 20){
                cout << "at mutator test default val passed :D" << endl;
    }
    if (myvector3.at(0) == 2){
                cout << "at mutator test both val passed :D" << endl;
    }
    
    
    // erase()
    myvector2.erase(1);
    myvector3.erase(2);
    if (myvector2.size() == 19){
                    cout << "erase test default val passed :D" << endl;
    }
    if (myvector3.size() == 9){
                    cout << "erase test both val passed :D" << endl;
    }
  
    
    // back()
  if (myvector2.back() == 20){
                       cout << "back test default val passed :D" << endl;
   }
  if (myvector3.back() == 100){
                       cout << "back test both val passed :D" << endl;
   }
    
    //front()
    if (myvector2.front() == 0){
                         cout << "front test default val passed :D" << endl;
     }
    if (myvector3.front() == 2){
                         cout << "front test both val passed :D" << endl;
     }
      
    
    
    
    //push_back()
    myvector1.push_back(1);
    myvector2.push_back(1);
    myvector3.push_back(1);
    
    if (myvector1.size() == 1 ){
                          cout << "push_back test default val passed :D" << endl;
    }
    
    if (myvector2.size() == 20){
                         cout << "push_back test default val passed :D" << endl;
     }
    if (myvector3.size() == 10){
                         cout << "push_back test both val passed :D" << endl;
     }
    
    //pop_back()
      myvector1.pop_back();
      myvector2.pop_back();
      myvector3.pop_back();
      
      if (myvector1.size() == 0 ){
                            cout << "pop_back test default val passed :D" << endl;
      }
      
      if (myvector2.size() == 19){
                           cout << "pop_back test default val passed :D" << endl;
       }
      if (myvector3.size() == 9){
                           cout << "pop_back test both val passed :D" << endl;
       }
    
    
    //clear()
    myvector1.clear();
    myvector2.clear();
    myvector3.clear();
    if (myvector1.size() == 0 ){
                             cout << "clear test default val passed :D" << endl;
    }
    
    if (myvector2.size() == 0){
                        cout << "clear test default val passed :D" << endl;
    }
    if (myvector3.size() == 0){
                            cout << "clear test both val passed :D" << endl;
    }
    
    
    //resize()
    myvector1.resize(2);
    myvector2.resize(2);
    myvector3.resize(2);
    if (myvector1.size() == 2 ){
                            cout << "reserve test default val passed :D" << endl;
    }
       
    if (myvector2.size() == 2){
                        cout << "reserve test default val passed :D" << endl;
    }
    if (myvector3.size() == 2){
                            cout << "reserve test both val passed :D" << endl;
    }
       
    
    
    //reserve()
    myvector1.reserve(2);
       myvector2.reserve(2);
       myvector3.reserve(2);
       if (myvector1.capacity() == 2 ){
                               cout << "reserve test default val passed :D" << endl;
       }
          
       if (myvector2.capacity() == 2){
                           cout << "reserve test default val passed :D" << endl;
       }
       if (myvector3.capacity() == 2){
                               cout << "reserve test both val passed :D" << endl;
       }
    
    
      // insert()
      myvector2.insert(1,20);
      myvector3.insert(2,40);
      if (myvector2.at(1) == 20){
                   cout << "insert test default val passed :D" << endl;
      }
      if (myvector3.at(2) == 40){
                   cout << "insert test both val passed :D" << endl;
      }
      
    
    
    //assign()
      myvector2.assign(3,2);
      myvector3.assign(3,2);
      if (myvector2.at(3) == 2){
                           cout << "assign test default val passed :D" << endl;
       }
      if (myvector3.at(1) == 2){
                           cout << "assign test both val passed :D" << endl;
       }
    
}
