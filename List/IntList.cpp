#include <iostream>
#include "IntList.h"


IntList::IntList(){
head = nullptr;
tail = nullptr;
}


IntList::~IntList(){
    IntNode* temp;
    while(head != nullptr){
        temp = head->next;
        delete head;
        head= temp;
    }
}

void IntList:: push_front(int value){
    IntNode* temp;
    temp = new IntNode(value);
    temp->next = head;
    head = temp;
    if( tail == nullptr){
        tail = head;
    }
    
}

void IntList::pop_front(){
    if( empty() == true){
        return;
    }
    else {
        if( head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else{
            IntNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
}

bool IntList::empty() const{
    if ((tail == nullptr && head == nullptr)  ){
        return true;
    }
    return false;
}

const int& IntList::front() const{
         return head->data;
}

const int& IntList::back() const{
        return tail->data;
    }


 ostream& operator << (ostream &out, const IntList& list){
     IntNode* temp = list.head;
    while(temp != nullptr){
        out << temp->data;
        temp = temp->next;
        if ( temp != nullptr){
        out << " ";
        }
    }
    
    return out;
}
  
