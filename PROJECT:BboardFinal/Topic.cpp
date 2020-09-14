#include "Message.h"
#include "Topic.h"
#include <iostream>



	//default constructor
   Topic::Topic(): Message() {
        
    }
	
	//Parameterized constructor
	Topic::Topic(const string& author,
	      const string& subject,
	      const string& body,
          unsigned sz): Message(author, subject, body , sz){
    }
	
    bool Topic::isReply() const{
        return false;
    }
	  
	/* to_formatted_string writes the contents of the Topic to a 
	* string in the following format:
	
	<begin_topic>
	:id: 4
	:subject: single line
	:from: author
	:children: 5 6 [this line should not be printed if there are no children.]
	:body: multiple lines - line 1
	line 2
	line 3
	<end>
	
	* line starting with :children: has the id's of all children 
	* (See file specifcations for details)
	* This function should not assume the last character in body is a newline.
	* In other words, this function must manually add a newline after the last    
	* line of the body (line 3 in the above example).
	* Also, the last character in the string must be a newline.
	*/
    string Topic::toFormattedString() const{
        string formated;
        ostringstream inOSS;
        inOSS << "<begin_topic>" << endl << ":id: " << id
        << endl << ":subject: " << subject << endl << ":from: " << author << endl;
        if(childList.size() != 0){
            inOSS << ":children: ";
            for(unsigned i = 0; i < childList.size(); i++){
                 inOSS << childList.at(i)->getID();
            }
            inOSS << endl;
        }
        inOSS << ":body: " << body << endl << "<end>" << endl;
        formated = inOSS.str();
        return formated;
    }

