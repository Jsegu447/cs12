 
#include "Message.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "BBoard.h"
#include <fstream>

using namespace std;


	// default constructor
   Message::Message(): author(""), subject(""), body(""), id(0){
    }
	
	// Parameterized constructor; 
	// id will be the size of current BBoard's message_list
	Message::Message(const string& author,
	        const string& subject,
	        const string& body,
            unsigned sz): author(author), subject(subject), body(body), id(sz){
        
    }

	// Be very careful here: some Messages will have two pointers to 
	// them, stored in very different places!
	// Where are they, and who should be responsible for deleting 
	// them?
Message::~Message(){
}
	
	// returns true if the object is a Reply.
	

	
	/* This function is responsible for printing the Message 
	* (whether Topic or Reply), and and all of the Message's 
	* "subtree" recursively:
	* After printing the Message with indentation n and appropriate 
	* format (see output details), it will invoke itself 
	* recursively on all of the Replies in its child_list,
	* incrementing the indentation value at each new level.
	*
	* Note: Each indentation increment represents 2 spaces. e.g. if 
	* indentation == 1, the reply should be indented 2 spaces, if 
	* it's 2, indent by 4 spaces, etc.
	*/       
void Message::print(unsigned indent) const{
    string spaces;
    if (childList.size() == 0){
        for (unsigned i = 0; i < indent; i++){
            spaces += "  ";
        }
        if( isReply() == true){
        cout << endl;
        }
        cout << spaces << "Message #" << getID() << ": " << subject << endl <<
              spaces << "from " << author << ": ";// << body << endl;
              string sbody = body;
              stringstream wbody(sbody);
              string singline;
              getline(wbody, singline);
              cout << singline;
              while(getline(wbody, singline)){
            cout << endl << spaces << singline;
              }
    
    }
    else if (childList.size() > 0){
             for (unsigned i = 0; i < indent; i++){
            spaces += "  ";
            }
        if( isReply() == true){
        cout << endl;
        }
        cout << spaces << "Message #" << getID() << ": " << subject << endl <<
        spaces << "from " << author << ": ";// << body << endl;
        string sbody = body;
        stringstream wbody(sbody);
        string singline;
        getline(wbody, singline);
        cout << singline;
        while(getline(wbody, singline)){
            cout << endl << spaces << singline;
        }
        
            for( unsigned i = 0; i < childList.size(); i++){
                cout << endl;
                childList.at(i)->print(indent + 1);
    

            }
      }
    }


	
	//returns the subject string.
    const string& Message::getSubject() const{
        return subject;
    }
	
	// returns the id.
    unsigned Message::getID() const{
        return id;
    }
	
	// Adds a pointer to the child to the parent's child_list. 
    void Message::addChild(Message* newMess){
        childList.push_back(newMess);
    }


//void parseForChildren(vector<int> &childList, const string &filename) {
//    ifstream infile;
//    infile.open(filename);
//    string discard;
//    int childID;
//    string childIdString;
//
//    // discard <begin_?????> and :children:
//    infile >> discard >> discard;
//
//    // WARNING: this function is just a HINT - in your actual program you
//    // will need to know when you are dealing with a reply or a topic
//
//    getline(infile, childIdString); // get string containing all child ids
//
//    stringstream iss(childIdString);
//    while (iss >> childID) {
//        childList.push_back(childID);
//    }
//}



