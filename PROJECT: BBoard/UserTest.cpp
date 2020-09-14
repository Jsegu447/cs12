#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#include "User.h"

int main() {
    string pass;
    string name;
    string tempass;
    User myUser;
    cout << "enter username n pass" << endl;
    cin >> name;
    cin >> pass;

    myUser = User(name, pass);
  
    
    cout << "ATTENTION: U ARE ABOUT TO BE VIBE CHECKED: PLEASE RE VERIFY PASSWORD" << endl;
    cin >> pass;
    if (myUser.check(name, pass) == false){
        cout << "VIBE CHECK FAILED * BONK *" << endl;
    }
    else{
        cout << "YOU HAVE PASSED THE VIBE CHECK. YOU MAY PROCEED" << endl;
    }
    cout << "ANYWHO TIME TO CHANGE UR PASSWORD SO UH, TYPE IN UR PASSWORD THEN A NEW ONE" << endl;
    cin >> pass;
    cin >> tempass;
    if (myUser.setPassword(pass, tempass)== true){
    cout << "OKAY UR NEW PASSWORD IS NOW SET SO GET REDI TO GET VIBED" << endl;
    cout << "ATTENTION: U ARE ABOUT TO BE VIBE CHECKED: PLEASE RE VERIFY PASSWORD" << endl;
       cin >> pass;
       if (myUser.check(name, pass) == false){
           cout << "VIBE CHECK FAILED * BONK *" << endl;
       }
       else{
           cout << "YOU HAVE PASSED THE VIBE CHECK. YOU MAY PROCEED" << endl;
       }
    }
    else{
        cout << "IT NO WORK" << endl;
    }
   return 0;
 
}
