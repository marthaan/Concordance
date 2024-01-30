// Name: Martha Ann Williams
// USC NetID: marthaan
// CS 455 PA5
// Fall 2023

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {
   cout << "---INITIAL LIST---" << endl;
   ListType list = new Node("martha", 100);
   listPrintAll(list);
   cout << endl;
   
   cout << "---TEST REMOVE---" << endl;
   cout << listRemove(list, "martha") << endl;
   cout << "Expected: 1 = true" << endl;
   cout << "List should now be empty: " << endl;
   listPrintAll(list);
   listInsert(list, "martha", 100);
   cout << "Adding 'martha' back, list is again: " << endl;
   listPrintAll(list);
   cout << endl;
   
   cout << "---TEST INSERTING A DUPLICATE---" << endl;
   cout << "Actual: " << listInsert(list, "martha", 100) << endl;
   cout << "Expected: 0 = false" << endl;
   listPrintAll(list);
   cout << endl;
   
   cout << "---TEST ADDING NEW UNIQUE NODE---" << endl;
   cout << "Actual: " << listInsert(list, "max", 2) << endl;
   cout << "Expected: 1 = true" << endl;
   listPrintAll(list);
   cout << endl;
   
   cout << "---TEST NUMENTRIES---" << endl;
   cout << "Current number of entries: " << listNumEntries(list) << endl;
   cout << "Expected: 2" << endl; 
   cout << endl;

   cout << "---TEST LOOKUP---" << endl;
   listPrintAll(list);
   int * lookupRef = listLookup(list, "martha");
   cout << lookupRef << endl;
   cout << * lookupRef << endl;
   cout << endl;
   
   cout << "---TEST REMOVE---" << endl;
   listPrintAll(list);
   cout << listRemove(list, "adam") << endl;
   cout << "Expected: 0 = true" << endl;
   cout << listRemove(list, "max") << endl;
   cout << "Expected: 1 = true" << endl;
   listPrintAll(list);
   cout << endl;
   
   
   cout << "---TEST PRINT (new)---" << endl;
   listInsert(list, "weldon", 99);
   listInsert(list, "anna", 20);
   listPrintAll(list);
   
   
   
   return 0;
}
