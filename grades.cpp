// Name: Martha Ann Williams
// USC NetID: marthaan
// CSCI 455 PA5
// Fall 2023

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;


// handles 1-arg command-line arguments
void commandOnly(Table * grades, string command) {
   if (command == "print") {
      grades->printAll();
   }
   else if (command == "size") {
      cout << grades->numEntries() << endl;
   }
   else if (command == "stats") {
      grades->hashStats(cout);
   }
   else if (command == "help") {
      cout << "commands: insert name score, change name newscore, lookup name, remove name, print, size, stats, help, quit" << endl;
   }
   else {
      cout << "ERROR: invalid command" << endl;
      cout << "commands: insert name score, change name newscore, lookup name, remove name, print, size, stats, help, quit" << endl;
   }
}

// handles when command-line argument is "insert"
void commandInsert(Table * grades, string name, int score) {
   bool inserted = grades->insert(name, score);
         
   if (!inserted) {
      cout << "name is already present" << endl;
   }
}


// handles when command-line argument is "change"
void commandChange(Table * grades, string name, int score) {
   int * found = grades->lookup(name);
         
   if (found == 0) { 
      cout << "name is not present" << endl;
   }
   else {
      * found = score;
   }
}


// handles when command-line argument is "lookup"
void commandLookup(Table * grades, string name) {
   int * found = grades->lookup(name);
         
   if (found == 0) { 
      cout << "name is not present" << endl;
   }
   else {
      cout << * found << endl;
   }
}


// handles when command-line argument is "remove"
void commandRemove(Table * grades, string name) {
   bool removed = grades->remove(name);
         
   if (!removed) {
      cout << "name is not present" << endl;
   }
}


// takes input, handles more than 
//    one command-line argument, quits, or  
//    calls commandOnly to handle the rest
void commands(Table * grades) {
   while (true) {
      cout << "cmd> ";
      
      string line;
      getline(cin, line);
   
      istringstream iss(line);
   
      string command;
      string name;      // will always be a single word (won't contain whitespace)
      int score;
     
      iss >> command;
      
      if (command == "quit") {
         break;
      }
      else if (command == "insert") {
         iss >> name;
         iss >> score;
         
         commandInsert(grades, name, score);
      }
      else if (command == "change") {
         iss >> name;
         iss >> score;
         
         commandChange(grades, name, score);
      }
      else if (command == "lookup") {
         iss >> name;
         
         commandLookup(grades, name);
      }
      else if (command == "remove") {
         iss >> name;
         
         commandRemove(grades, name);
      }
      else {
         commandOnly(grades, command);
      }
   }
}

int main(int argc, char * argv[]) {


   Table * grades;  // Table is dynamically allocated below, so we can call
                     // different constructors depending on input from the user.
   
   // optionally gets the hash table size from the command line
   if (argc > 1) {
      int hashSize = atoi(argv[1]);  // atoi converts c-string to int
      
      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number" 
              << endl;
         return 1;
      }

      grades = new Table(hashSize);

   }
   else {   // no command line args given -- use default table size
      grades = new Table();
   }


   grades->hashStats(cout);
   
   // add more code here
   // Reminder: use -> when calling Table methods, since grades is type Table*
   
   commands(grades);
   
   return 0;
}
