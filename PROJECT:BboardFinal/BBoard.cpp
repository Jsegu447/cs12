
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

#include "Message.h"
#include "User.h"
#include "BBoard.h"
#include "Topic.h"
#include "Reply.h"
 
BBoard::BBoard(){
    title = "";
    current_user = nullptr;
}
    
BBoard::BBoard(const string& str){
    title = str;
    current_user = nullptr;
}

BBoard::~BBoard(){
    for(unsigned i = 0; i < message_list.size(); i++){
        delete message_list.at(i);
    }
}
    
bool BBoard::loadUsers(const string& file){
    ifstream inFS;
    string pass;
    string uname;
    inFS.open(file);
    if(!inFS.is_open()){
        return false;
    }
    else{
        while( inFS >> uname >> pass){
            user_list.push_back(User(uname, pass));
        }
        return true;
    }
}

bool BBoard::loadMessages(const string& inFile){
    ifstream inFS;
    string message;
    vector <string> childID;
    string childs;
    inFS.open(inFile);
    if( !inFS.is_open()){
        cout << inFile << " failed to open" << endl;
        return false;
    }
    while(inFS >> message){
        if( message == "<begin_topic>"){
            string author;
            string body;
            string topic;
            unsigned num = 1;
            string subject;
            inFS.ignore();
            inFS >> message;
            
            if(message == ":id:"){
                inFS >> num;
            }
            inFS >> message;
               
            if(message == ":subject:"){
                getline(inFS,subject);
                subject = subject.substr(1,subject.size());
            }
            inFS >> message;
            
            if( message == ":from:"){
                inFS >> author;
            }
            inFS >> message;
            
            if(message == ":children:"){
                getline(inFS, childs);
                childID.push_back(childs);
                inFS >> message;
            }
            else{
                childs = "";
                childID.push_back(childs);
            }
            
            
            if( message == ":body:"){
                getline(inFS, message);
                while(message != "<end>"){
                    body += message;
                    body+= "\n";
                    getline(inFS, message);
                }
                body = body.substr(1,body.size()-2);
            }
            message_list.push_back(new Topic(author, subject, body, num));
        }
        
        if( message == "<begin_reply>"){
            inFS.ignore();
            string author;
            string body;
            string topic;
            unsigned num = 1;
            string subject;
            inFS >> message;
            if(message == ":id:"){
                inFS >> num;
            }
            inFS >> message;
            
            if(message == ":subject:"){
                inFS.ignore();
                getline(inFS, subject);
            }
            inFS >> message;
            
            if( message == ":from:"){
                inFS >> author;
            }
            inFS >> message;
            
            if(message == ":children:"){
                getline(inFS, childs);
                childID.push_back(childs);
                inFS >> message;
            }
            else{
                childs = "";
                childID.push_back(childs);
            }
            
            if( message == ":body:"){
                getline(inFS,message);
                while(message != "<end>"){
                    body += message;
                    body += '\n';
                    getline(inFS, message);
                }
                body = body.substr(1,body.size()-2);
            }
//            cout << subject << endl;
            message_list.push_back(new Reply(author, subject, body, num));
        }
    }
    
  // cout << message_list.size()<< endl << childID.size() << endl;
    for(unsigned i = 0; i < childID.size(); i++){
        unsigned id = 0;
        if(childID.at(i) != ""){
            stringstream nums(childID.at(i));
            while(nums >> id){
                message_list.at(i)->addChild(message_list.at(id-1));
            }
        }
    }

    return true;
    
}
    
bool BBoard::saveMessages(const string& outFile){
    ofstream outFS;
    outFS.open(outFile);
    if(!outFS.is_open()){
          return false;
    }
    
    outFS << message_list.size() << endl;
    for(unsigned i = 0; i < message_list.size(); i++){
        outFS << message_list.at(i)->toFormattedString();
    }
        
    return true;
}

void BBoard::login(){
    string userString;
    string userPass;
    bool loggedin = false;
    cout << "Welcome to " << title << endl;
    while (loggedin == false) {
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> userString;
            if (userString == "q" || userString == "Q"){
                cout << "Bye!" << endl;
                return;
            }
        cout << "Enter your password: ";
        cin >> userPass;
        for( unsigned i = 0; i < user_list.size(); i++){
            if ( user_list.at(i).check(userString, userPass) == true){
                current_user = &user_list.at(i);
                cout << endl;
                cout << "Welcome back " << userString << "!" << endl;
                cout << endl;
                return;
                    
            }
            else {
                loggedin = false;
            }
        }
        cout << "Invalid Username or Password!" << endl;
        cout << endl;

    }
           
}

void BBoard::run(){
    if(current_user == nullptr){
        return;
    }
   
    char userInput = '\0';
    while ( (userInput != 'q') || (userInput != 'Q') ){
        menuDisplay();
        cout << "Choose an action: ";
        cin >> userInput;
          
        if(userInput == 'N' || userInput == 'n'){
            newTopic();
        }
                 
             
        if (userInput == 'D' || userInput == 'd'){
            if ( message_list.size() == 0){
                cout << endl;
                cout << "Nothing to Display." << endl;
                cout << endl;
                      }
                   
            else {
                for (unsigned i = 0; i < message_list.size(); i++){
                      if( message_list.at(i)->isReply() == false ){
                    cout  << endl;
                    cout << "---------------------------------------------------------" << endl;
                  
                    message_list.at(i)->print(0);
                   }
                }
                cout << endl <<"---------------------------------------------------------" << endl;
                cout << endl;
            }
        }
        else if (userInput == 'r' || userInput ==  'R'){
            int numIn;
            string body;
            string input;
            string rSub;
            cout << "Enter message ID (-1 for Menu): ";
            cin >> numIn;
            if (numIn == -1) {
                return;
            }
            cout << "Enter body: ";
            cin.ignore();
            getline(cin, input);
            while(input != ""){
                body+=input;
                body+= '\n';
                getline(cin, input);
            }
            rSub =  "Re: " + message_list.at(numIn-1)->getSubject();
           
            Reply* userReply = new Reply(current_user->getUsername(), rSub, body, message_list.size()+1);
            message_list.push_back(userReply);
            message_list.at(numIn-1)->addChild(userReply);
        }
        
        
              
        else if (userInput == 'q' || userInput ==  'Q'){
            cout << "Bye!" << endl;
            break;
                
        }
          
    }
          
          
}

void BBoard::menuDisplay(){
    cout << "Menu" << endl;
    cout <<"- Display Messages ('D' or 'd')" << endl;
    cout <<"- Add New Topic ('N' or 'n')" << endl;
    cout <<"- Add Reply to a Topic ('R' or 'r')" << endl;
    cout <<"- Quit ('Q' or 'q')" << endl;
}

void BBoard::newTopic(){
    string umessage;
    string sub;
    string temp;
    string body;
    cout << "Enter Subject: ";
    cin.ignore();
                        
    getline(cin, umessage);
    sub += umessage;
    cout << "Enter Body: ";
                       
    cout << endl;
                         
    getline(cin, umessage);
    while(umessage != ""){
            body+= umessage;
            body+= '\n';
            getline(cin, umessage);
    }
    body = body.substr(0, body.size()-1);
    message_list.push_back(new Topic(current_user->getUsername(), sub, body, message_list.size()+1));
}

