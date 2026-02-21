/*
 * File: SumIntegerFile.cpp
 * ------------------------
 * This program calculates and prints the sum of the integers in
 * a data file chosen by the user.  This program makes no attempt
 * to check that the file is formatted correctly and is therefore
 * not appropriate for use in practice.  It does, however, illustrate
 * the use of the extraction operator with files.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "error.h"
using namespace std;

/* Function prototypes */

string promptUserForFile(ifstream & infile, string prompt = "");
int stringToInteger(string str);
string integerToString(int n);

/* Main program */

int main() {
   ifstream infile;
   promptUserForFile(infile, "Input file: ");
   int total = 0;
   string line;
   while (getline(infile, line)) {
      if (line.empty()) continue;
      total += stringToInteger(line);
   }
   infile.close();
   cout << "The sum is " << integerToString(total) << endl;
   return 0;
}

/*
 * Function: promptUserForFile (local; avoids linking filelib/strlib)
 * Prompts for a filename until the file opens successfully.
 */
string promptUserForFile(ifstream & infile, string prompt) {
   while (true) {
      cout << prompt;
      string filename;
      getline(cin, filename);
      infile.open(filename);
      if (!infile.fail()) return filename;
      infile.clear();
      cout << "Unable to open that file.  Try again." << endl;
      if (prompt == "") prompt = "Input file: ";
   }
}

/*
 * Function: stringToInteger
 * Usage: int n = stringToInteger(str);
 * ------------------------------------
 * Converts a string of digits (possibly preceded or followed by whitespace)
 * into the corresponding integer.  If the conversion fails, the function
 * displays an error message and exits with a nonzero status.
 */

int stringToInteger(string str) {
   istringstream stream(str);
   int value;
   if (!(stream >> value)) error("Illegal integer format: " + str);
   return value;
}

/*
 * Function: integerToString
 * Usage: string str = integerToString(n);
 * ---------------------------------------
 * Converts an integer into the corresponding string of digits.
 */

string integerToString(int n) {
   ostringstream stream;
   stream << n;
   return stream.str();
}
