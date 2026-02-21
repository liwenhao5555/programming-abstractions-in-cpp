/*
 * File: CopyFile.cpp
 * ------------------
 * This program creates a copy of an input file.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "filelib.h"
using namespace std;

void copyStream(istream & is, ostream & os) {
   char ch;
   while (is.get(ch)) os.put(ch);
}

int main() {
   ifstream infile;
   ofstream outfile;
   promptUserForFile(infile, "Input file:  ");
   promptUserForFile(outfile, "Output file: ");
   copyStream(infile, outfile);
   infile.close();
   outfile.close();
   return 0;
}
