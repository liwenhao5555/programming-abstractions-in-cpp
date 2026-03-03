/*
 * File: ExtractWords.cpp
 * ----------------------
 * This program defines and tests the function extractWords, which
 * extracts all consecutive sequences of letters from a string and
 * stores them in a Vector<string>.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "vector.h"
using namespace std;

/* Function prototypes */

void extractWords(string str, Vector<string> & words);

/* Main program */

int main() {
   cout << "This program tests the extractWords function." << endl;
   while (true) {
      string line;
      cout << "Enter a line of text: ";
      getline(cin, line);
      if (line == "") break;
      Vector<string> words;
      extractWords(line, words);
      cout << "The words in that line are:" << endl;
      for (int i = 0; i < words.size(); i++) {
         cout << "  \"" << words[i] << "\"" << endl;
      }
   }
   return 0;
}

/*
 * Function: extractWords
 * Extracts all consecutive sequences of letters from str into words.
 */
void extractWords(string str, Vector<string> & words) {
   words.clear();
   int start = -1;
   for (int i = 0; i < str.length(); i++) {
      if (isalpha(str[i])) {
         if (start == -1) start = i;
      } else {
         if (start >= 0) {
            words.add(str.substr(start, i - start));
            start = -1;
         }
      }
   }
   if (start >= 0) words.add(str.substr(start));
}
