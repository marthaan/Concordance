// Name: Martha Ann Williams
// USC NetID: marthaan
// CSCI 455 PA5
// Fall 2023


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to *not* put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include <string>
#include <list>
  

struct Node {
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

// insert a new pair into the list
// return false iff this key was already present 
//         (and no change made to list)
bool listInsert(ListType & list, const std::string & target, int value);

// returns the address of the value that goes with this key
// or NULL if key is not present.
//   Thus, this method can be used to either lookup the value or
//   update the value that goes with this key.
int * listLookup(ListType & list, const std::string & target);

// remove a pair given its key
// return false iff key wasn't present
//         (and no change made to table)
bool listRemove(ListType & list, const std::string & target);

// counts the number of nodes in the list
// returns the count
int listNumEntries(ListType & list);

// prints each pair for all elements of a list
void listPrintAll(ListType & list);

// keep the following line at the end of the file
#endif
