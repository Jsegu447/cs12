
#include <string>
#include <stdio.h>


using namespace std;
#include "User.h"

User::User(){
    username = "";
    password = "";
}
User::User(const string& uname, const string& pass){
    username = uname;
    password = pass;
}

string User::getUsername()const {
    return username;
}

bool User::check(const string &uname, const string &pass) const {
    if (uname == ""){
        return false;
    }
    if (username == uname && password == pass){
        return true;
    }

    else{
        return false;
    }
    
}

bool User::setPassword(const string &oldpass, const string &newpass){
    if ( username != ""){
        if (password == oldpass && password != newpass){
            password = newpass;
            return true;
        }
    }
    
    return false;
}
