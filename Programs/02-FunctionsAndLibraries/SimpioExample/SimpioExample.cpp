/*
 * File: SimpioExample.cpp
 * -----------------------
 * This program is used to illustrate error-recovery in the simpio.h
 * library.
 *
 * NOTE (Linux): getInteger() has a known bug on Linux systems where
 * it incorrectly rejects all input. The validation logic fails due to
 * EOF checking issues. This is a Stanford library bug, not a C++ issue.
 * Use standard cin >> n for input instead, or skip this example.
 */

#include <iostream>
#include "simpio.h"
using namespace std;

int main() {
   int n = getInteger("Enter an integer: ");  // BUG: Rejects all input on Linux
   cout << "You entered the integer " << n << endl;
   return 0;
}
