/*
 * File: Mondrian.cpp
 * ------------------
 * This program prints the recursive split lines for a Mondrian-style
 * drawing so it can run without graphics.
 */

#include <iostream>
#include "random.h"
using namespace std;

/* Constants */

const double MIN_AREA = 10000;   /* Smallest square that will be split */
const double MIN_EDGE = 20;      /* Smallest edge length allowed       */
const double CANVAS_WIDTH = 500;
const double CANVAS_HEIGHT = 300;

/* Function prototypes */

void subdivideCanvas(double x, double y, double width, double height);

/* Main program */

int main() {
   subdivideCanvas(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
   return 0;
}

/*
 * Function: subdivideCanvas
 * Usage: subdivideCanvas(x, y, width, height);
 * -------------------------------------------
 * Decomposes the specified rectangular region recursively
 * by splitting that rectangle randomly along its larger dimension.  The
 * recursion continues until the area falls below the constant MIN_AREA.
 */

void subdivideCanvas(double x, double y, double width, double height) {
   if (width * height >= MIN_AREA) {
      if (width > height) {
         double mid = randomReal(MIN_EDGE, width - MIN_EDGE);
         subdivideCanvas(x, y, mid, height);
         subdivideCanvas(x + mid, y, width - mid, height);
         cout << "vertical line at x=" << x + mid
              << " from y=" << y
              << " to y=" << y + height
              << endl;
      } else {
         double mid = randomReal(MIN_EDGE, height - MIN_EDGE);
         subdivideCanvas(x, y, width, mid);
         subdivideCanvas(x, y + mid, width, height - mid);
         cout << "horizontal line at y=" << y + mid
              << " from x=" << x
              << " to x=" << x + width
              << endl;
      }
   }
}
