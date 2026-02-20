/*
 * File: ShowFileContents.cpp
 * --------------------------
 * This program displays the contents of a file chosen by the user.
 */

#include <iostream>
#include <fstream>
#include "filelib.h"
using namespace std;

void copyStream(istream & is, ostream & os) {
   char ch;
   while (is.get(ch)) os.put(ch);
}

int main() {
   ifstream infile;
   promptUserForFile(infile, "Input file: ");
   copyStream(infile, cout);
   infile.close();
   return 0;
}
