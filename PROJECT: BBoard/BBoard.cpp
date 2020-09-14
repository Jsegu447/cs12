#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;


#include "BBoard.h"

BBoard::BBoard() {
    title = "";
}

BBoard::BBoard(const string & str){
    title = str;
}

bool BBoard::loadUsers(const string & file){
    ifstream inFS;
    string pass;
    string uname;
    inFS.open(file);
    if(!inFS.is_open()){
        return false;
    }
    else{
        while( inFS >> uname >> pass){
               userList.push_back(User( uname, pass));
           }
        return true;
    }
}

bool BBoard::login(){
    string userString;
    string userPass;
    bool loggedin = false;
 
    cout << "Welcome to CS12 Bulletin Board" << endl;
    while (loggedin == false) {
    cout << "Enter your username ('Q' or 'q' to quit): " << endl;
    cin >> userString;
    if (userString == "q" || userString == "Q"){
        cout << "Bye!" << endl;
        return false;
    }
    cout << "Enter your password: " << endl;
    cin >> userPass;
        for( unsigned i = 0; i < userList.size(); i++){
            if ( userList.at(i).check(userString, userPass) == true){
                currentUser = userList.at(i);
                cout << "Welcome back " << userString << "!" << endl;
                cout << endl;
                return true;
        }
            else {
                loggedin = false;
            }
    }
        cout << "Invalid Username or Password!" << endl;
        cout << endl;

    }
    return true;
}

void BBoard::run(){
    char userInput = '\0';
    string umessage;
    string sub;
    while ( (userInput != 'q') || (userInput != 'Q') ){
        cout << "Menu" << endl;
        cout <<"- Display Messages ('D' or 'd')" << endl;
        cout <<"- Add New Message ('N' or 'n')" << endl;
        cout << "- Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: " << endl;
        cin >> userInput;
            if(userInput == 'N' || userInput == 'n'){
                cout << "Enter Subject: " << endl;
                cin.ignore();
                getline(cin, sub);
                cout << "Enter Body: " << endl;
                getline(cin, umessage);
                messageList.push_back(Message(currentUser.getUsername(), sub, umessage));
                cout << "Message Recorded!" << endl;
                cout << endl;
                
                
            }
            else if (userInput == 'D' || userInput == 'd'){
                if ( messageList.size() == 0){
                    cout << "Nothing to Display." << endl;
                    cout << endl;
                }
                else if (messageList.size() == 1){
                    for (unsigned i = 0; i < messageList.size(); i++){
                        cout << "---------------------------------------------------------" << endl;
                        cout << "Message #" << i+1 << ": ";
                        messageList.at(i).display();
                        cout << "---------------------------------------------------------" << endl;
                        cout << endl;
                        
                    }
                }
                else {
                    for (unsigned i = 0; i < messageList.size(); i++){
                    cout << "---------------------------------------------------------" << endl;
                    cout << "Message #" << i+1 << ": ";
                    messageList.at(i).display();
                    }
                    cout << "---------------------------------------------------------" << endl;
                    cout << endl;
                }
            }
        
            else if (userInput == 'q' || userInput ==  'Q'){
                cout << "Bye!" << endl;
                exit(1);
            }
    
    }
    
    
    
 }

