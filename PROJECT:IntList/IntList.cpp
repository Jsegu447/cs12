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
//works
  IntList::IntList (const IntList& cpy){
      head = nullptr;
      tail = nullptr;
      if(this == &cpy){
          return;
          }
      else{
      for( IntNode* i = cpy.head; i != 0; i = i->next ){
              push_back(i->data);
        }
      }
}
//works
void IntList::push_back(int value){
    if(empty()==true){
        IntNode* temp;
        temp = new IntNode(value);
        head = temp;
        tail = temp;
        tail->next = nullptr;
    }
    else{
        IntNode* temp;
        temp = new IntNode(value);
        tail->next = temp;
        tail = temp;
        tail->next = nullptr;
        
    }
     
}

IntList& IntList::operator=(const IntList &rhs){
  if(this == &rhs){
          return *this;
    }
      else{
      clear();
      for( IntNode* i = rhs.head; i != 0; i = i->next ){
              push_back(i->data);
        }
     
    }
        return *this;
}
 

void IntList::clear(){
    IntNode* temp;
        if(empty()== true){
        return;
        }
        else{
       while(head != nullptr){
        temp = head->next;
              delete head;
              head= temp;
         }
        head = nullptr;
        tail = nullptr;
        }
}
void IntList::selection_sort(){
        int temp;
        for(IntNode* i = head; i != nullptr; i = i->next){
        for(IntNode* min = head; min != nullptr; min = min->next ){
        if( min->data > i->data){
        temp = min->data;
        min->data = i->data;
        i->data = temp;
        }
        
    }
     
}
        
        }
void IntList::insert_ordered(int value){
   
    if( empty() ){
        push_back(value);
        return;
    }
    if( value >= tail->data){
        push_back(value);
        return;
    }
    if( value <= head->data){
        push_front(value);
        return;
        }
    if( value < tail->data && value > head->data){
        
        IntNode* prev = head;
       for(IntNode* curr = head->next; curr != nullptr; curr = curr->next ){
           if( value <= curr->data && value > prev->data){
               IntNode* temp = new IntNode(value);
               temp->next = prev->next;
               prev->next = temp;
           }
           if (prev->next != nullptr){
           prev = prev->next;
   
    }
                   
 
}
    
}
}

    
     
        
void IntList::remove_duplicates(){
        if (empty() == true){
        return;
        }

         for(IntNode* curr = head; curr != 0; curr = curr->next){
        IntNode* prev = curr;
        IntNode* foll = curr->next;
        while( foll != nullptr){
        if(curr->data == foll->data){
        prev->next = foll->next;
        if(foll == tail){
               tail = prev;
               }
        delete foll;
        foll = prev->next;
       }
        else{
        prev = prev->next;
        foll = prev->next;
        }
        }
        }
        }
        
        
        
      
      
     
 
        

