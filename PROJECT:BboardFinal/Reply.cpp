#include <iostream>
#include <sstream>
#include "Message.h"
#include "Reply.h"



 
   //default constructor
    Reply::Reply():Message(){
    }

   /* Parameterized constructor - similar to Message's constructor except:
    * The subject should be initialized to "Re: <sbjct>" not <sbjct>.
    */
   Reply::Reply(const string& author,
      const string& subject,
      const string& body,
         unsigned sz): Message(author,subject, body , sz){
       
   }

 
    bool Reply::isReply() const{
        return true;
    }
 
   /* to_formatted_string writes the contents of the Reply to a string in the 
    * following format:
    
   <begin_reply>
   :id: 4
   :subject: single line
   :from: author
   :children: 5 6 [this line should not be printed if there are no children.]
   :body: multiple lines
   2nd line
   <end>

   * the line starting with :children: has the list of id's of all children 
   * (See file specs. for details)
   * This function should not assume the last character in body is a newline.
   * In other words, this function must manually add a newline after the last 
   * line of the body (line 3 in this example).
   * Also, the last character in the string must be a newline.
   */
    string Reply::toFormattedString() const{ // New !!
        string formated;
        ostringstream inOSS;
        inOSS << "<begin_reply>" << endl << ":id: " << id
        << endl << ":subject: " << subject << endl << ":from: " << author << endl;
        if(childList.size() != 0){
            inOSS << ":children: ";
                for(unsigned i = 0; i < childList.size(); i++){
                    inOSS << childList.at(i)->getID();
            }
            inOSS << endl;
        }
        inOSS<< ":body: " <<
        body << endl << "<end>" << endl;
        formated = inOSS.str();
        return formated;
    }

