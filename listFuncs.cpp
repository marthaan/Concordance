// Name: Martha Ann Williams
// USC NetID: marthaan
// CSCI 455 PA5
// Fall 2023


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}




//*************************************************************************
// put the function definitions for your list functions below


bool listInsert(ListType & list, const string & target, int value) {
   bool inserted = false;
   
   if (list == NULL) {
      list = new Node(target, value);
      inserted = true;
   }
   else {
      Node * p = list;
      
      bool done = false;
      
      while (!done) {
         if (p->key == target) {
            done = true;
         }
         else if (p->next == NULL) {
            p->next = new Node(target, value);
            inserted = true;
            done = true;
         }
         else {
            p = p->next;
         }
      }   
   }
   
   return inserted;
}


int * listLookup(ListType & list, const string & target) {
   Node * p = list;
   
   if (p == NULL) {
      return NULL;
   }
   
   while (p != NULL) {
      if (p->key == target) {
         int * valPtr = &p->value;
         return valPtr;
      }
      p = p->next;
   }
   
   return NULL;
}


bool listRemove(ListType & list, const string & target) {
   if (list == NULL) {
      return false;
   }
   
   if (list->key == target) {
      Node * first = list;
      list = list->next;
      delete first;
      return true;
   }
   
   Node * prev = list;
   Node * curr = list->next;
   
   while (prev->next != NULL) {
      if (curr->key == target) {
         prev->next = curr->next;
         delete curr;
         return true;
      }
      else {
         prev = curr;
         curr = curr->next;
      }
   }
   
   return false;
}


int listNumEntries(ListType & list) {
   Node * p = list; 
   
   int entries = 0;
   
   while (p != NULL) {
      entries += 1; 
      p = p->next;
   }
   
   return entries;
}


void listPrintAll(ListType & list) {
   Node * p = list;
   
   while (p != NULL) {
      cout << p->key << " " << p->value << endl;
      p = p->next;
   }
}