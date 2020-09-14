#include <iostream>
#include <string>

using namespace std;


void flipString(string&);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}
void flipString(string& s){
    if(s.size() == 0 || s.size() == 1){
        return;
    }
     string cpy =  s.substr(0,s.size()-1);
    //cout << cpy << endl;
    flipString(cpy);
    s = s.at(s.size()-1) + cpy;

 
   
}
//Implement the flipString function here


