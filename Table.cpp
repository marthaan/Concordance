// Name: Martha Ann Williams
// USC NetID: marthaan
// CSCI 455 PA5
// Fall 2023

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

// for hash function called in private hashCode method defined below
#include <functional>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
   hashSize = HASH_SIZE;
   table = new ListType[hashSize]();
}


Table::Table(unsigned int hSize) {
   hashSize = hSize;
   table = new ListType[hashSize]();
}


int * Table::lookup(const string &key) {
   unsigned int hCode = hashCode(key);
   
   ListType & list = table[hCode];
   
   return listLookup(list, key);
}


bool Table::remove(const string &key) {
   unsigned int hCode = hashCode(key);
   
   ListType & list = table[hCode];
   
   return listRemove(list, key);  
}


bool Table::insert(const string &key, int value) {
   unsigned int hCode = hashCode(key);
   
   ListType & list = table[hCode];
   
   return listInsert(list, key, value);
}


int Table::numEntries() const {
   int entries = 0; 
   
   for (int i = 0; i < hashSize; i++) {
      ListType & list = table[i];
      int listEntries = listNumEntries(list);
      entries += listEntries;
      
   }
   
   return entries;
}


void Table::printAll() const {
   for (int i = 0; i < hashSize; i++) {
      ListType & list = table[i];
      if (list != NULL) {
         listPrintAll(list);
      }
   }
}


void Table::hashStats(ostream &out) const {
   cout << "number of buckets: " << hashSize << endl;
   cout << "number of entries: " << numEntries() << endl;
   cout << "number of non-empty buckets: " << nonEmptyBuckets() << endl;
   cout << "longest chain: " << longestChain() << endl;
}


// hash function for a string
// (we defined it for you)
// returns a value in the range [0, hashSize)
unsigned int Table::hashCode(const string &word) const {

   // Note: calls a std library hash function for string (it uses the good hash
   //   algorithm for strings that we discussed in lecture).
   return hash<string>()(word) % hashSize;

}


// add definitions for your private methods here
/**
ListType & Table::getList(const string &key) const {
   unsigned int hCode = hashCode(key);
   
   list<ListType> & listRef = table[hCode];
   ListType & list = listRef.front();
   
   return list;
}
*/


int Table::nonEmptyBuckets() const {
   int emptyBuckets = 0; 
   
   for (int i = 0; i < hashSize; i++) {
      ListType & list = table[i];
      
      if (list != NULL) {
         emptyBuckets += 1;
      }
   }
   
   return emptyBuckets;
}

int Table::longestChain() const {
   int longest = 0;
   
   for (int i = 0; i < hashSize; i++) {
      ListType & list = table[i];
      
      int listEntries = listNumEntries(list);
      if (listEntries > longest) {
         longest = listEntries;
      }
   }
   
   return longest;
}