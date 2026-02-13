/*
 * File: ShowFileContents.cpp
 * --------------------------
 * This program displays the contents of a file chosen by the user.
 */

#include <iostream>
#include <fstream>
#include "filelib.h"
using namespace std;

/* Main program */

int main() {
   ifstream infile;
   promptUserForFile(infile, "Input file: ");
   string line;
   while (getline(infile, line)) {
      cout << line << endl;
   }
   infile.close();
   return 0;
}
