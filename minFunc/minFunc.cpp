#include "minFunc.h"



#include <iostream>

using namespace std;
const int* min(const int arr[], int arrSize);


int main() {
   int arrSize;
   cin >> arrSize;
   if (arrSize > 0) {
      int arr[arrSize];
      for (int i = 0; i < arrSize; ++i) {
         cin >> arr[i];
      }
      const int *minLoc = min(arr, arrSize);
      cout << *minLoc << endl;
   }
   return 0;
}



const int * min(const int arr[], int arrSize) {
    if ( arrSize == 0){
        return nullptr;
    }
    if( arrSize == 1){
        return &arr[0];
    }
   if(arr[0] < arr[arrSize-1]) {
        return min((arr), arrSize - 1);
    }
     else if(arr[0] > arr[arrSize-1]){
         return min(arr+1, arrSize - 1);
    }
    return arr;
}
