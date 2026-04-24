/*
 * File: Mondrian.cpp
 * ------------------
 * This program creates a Mondrian-style drawing and saves it as an SVG file.
 */

#include <fstream>
#include <iostream>
#include "random.h"
using namespace std;

/* Constants */

const double MIN_AREA = 10000;   /* Smallest square that will be split */
const double MIN_EDGE = 20;      /* Smallest edge length allowed       */

/* Local stand-in for GWindow that writes an SVG file. */

class GWindow {
public:
   GWindow() : width(500), height(300), out("Mondrian.svg") {
      out << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
          << "width=\"" << width << "\" "
          << "height=\"" << height << "\" "
          << "viewBox=\"0 0 " << width << " " << height << "\">\n";
      out << "<rect width=\"100%\" height=\"100%\" fill=\"white\" />\n";
   }

   ~GWindow() {
      out << "</svg>\n";
   }

   double getWidth() const {
      return width;
   }

   double getHeight() const {
      return height;
   }

   void drawLine(double x0, double y0, double x1, double y1) {
      out << "<line x1=\"" << x0
          << "\" y1=\"" << y0
          << "\" x2=\"" << x1
          << "\" y2=\"" << y1
          << "\" stroke=\"black\" stroke-width=\"2\" />\n";
   }

private:
   double width;
   double height;
   ofstream out;
};

/* Function prototypes */

void subdivideCanvas(GWindow & gw, double x, double y,
                                   double width, double height);

/* Main program */

int main() {
   GWindow gw;
   subdivideCanvas(gw, 0, 0, gw.getWidth(), gw.getHeight());
   return 0;
}

/*
 * Function: subdivideCanvas
 * Usage: subdivideCanvas(gw, x, y, width, height);
 * ------------------------------------------------
 * Decomposes the specified rectangular region on the canvas recursively
 * by splitting that rectangle randomly along its larger dimension.  The
 * recursion continues until the area falls below the constant MIN_AREA.
 */

void subdivideCanvas(GWindow & gw, double x, double y,
                                   double width, double height) {
   if (width * height >= MIN_AREA) {
      if (width > height) {
         double mid = randomReal(MIN_EDGE, width - MIN_EDGE);
         subdivideCanvas(gw, x, y, mid, height);
         subdivideCanvas(gw, x + mid, y, width - mid, height);
         gw.drawLine(x + mid, y, x + mid, y + height);
      } else {
         double mid = randomReal(MIN_EDGE, height - MIN_EDGE);
         subdivideCanvas(gw, x, y, width, mid);
         subdivideCanvas(gw, x, y + mid, width, height - mid);
         gw.drawLine(x, y + mid, x + width, y + mid);
      }
   }
}
