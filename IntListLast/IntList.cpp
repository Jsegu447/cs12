#include "IntList.h"
#include <iostream>
#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream& operator<<( ostream& out, const IntList& list){
    if(list.head == 0){
        out << "";
        return out;
    }
    operator<<(out, list.head);
    return out;
}



bool IntList::exists(IntNode* node, int i) const{
        if ( node == 0){
        return false;
        }
        if(node->data == i){
        return true;
        }
        else{
       return exists(node->next, i);
        }
}

bool IntList::exists(int j) const{
        if( head == 0){
        return false;
        }
        if (head->data == j){
        return true;
        }
        else{
        return exists(head, j);
        }
    }
       
ostream& operator<<(ostream& out, IntNode* node){
    if (node->next == 0){
        out << node->data;
        return out;
    }
    if(node->next != 0){
        out << node->data << " ";
        node = node->next;
        operator<<(out, node);
        return out;
    }
        return out;
}
