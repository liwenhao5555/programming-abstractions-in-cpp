/*
 * File: Snowflake.cpp
 * -------------------
 * This program draws a Koch fractal snowflake and saves it as an SVG file.
 */

#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

/* Constants */

const double SIZE = 200;         /* Size of the order 0 fractal in pixels */
const int ORDER = 4;             /* Order of the fractal snowflake        */

/* Local stand-ins for GPoint/GWindow that write an SVG file. */

class GPoint {
public:
   GPoint(double x = 0, double y = 0) : x(x), y(y) {
      /* Empty */
   }

   double getX() const {
      return x;
   }

   double getY() const {
      return y;
   }

private:
   double x;
   double y;
};

class GWindow {
public:
   GWindow() : width(500), height(300), out("Snowflake.svg") {
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

   GPoint drawPolarLine(GPoint pt, double r, double theta) {
      double radians = theta * 3.14159265358979323846 / 180.0;
      GPoint end(pt.getX() + r * cos(radians),
                 pt.getY() - r * sin(radians));
      out << "<line x1=\"" << pt.getX()
          << "\" y1=\"" << pt.getY()
          << "\" x2=\"" << end.getX()
          << "\" y2=\"" << end.getY()
          << "\" stroke=\"black\" stroke-width=\"1.5\" />\n";
      return end;
   }

private:
   double width;
   double height;
   ofstream out;
};

/* Function prototypes */

GPoint drawFractalLine(GWindow & gw, GPoint pt,
                       double r, double theta, int order);

/* Main program */

int main() {
   GWindow gw;
   cout << "Program to draw a snowflake fractal." << endl;
   double cx = gw.getWidth() / 2;
   double cy = gw.getHeight() / 2;
   GPoint pt(cx - SIZE / 2, cy - sqrt(3.0) * SIZE / 6);
   pt = drawFractalLine(gw, pt, SIZE, 0, ORDER);
   pt = drawFractalLine(gw, pt, SIZE, -120, ORDER);
   pt = drawFractalLine(gw, pt, SIZE, +120, ORDER);
   return 0;
}

/*
 * Function: drawFractalLine
 * Usage: GPoint end = drawFractalLine(gw, pt, r, theta, order);
 * -------------------------------------------------------------
 * Draws a fractal edge starting from pt and extending r units in direction
 * theta.  If order > 0, the edge is divided into four fractal edges of the
 * next lower order.  The function returns the endpoint of the line.
 */

GPoint drawFractalLine(GWindow & gw, GPoint pt,
                       double r, double theta, int order) {
   if (order == 0) {
      return gw.drawPolarLine(pt, r, theta);
   } else {
      pt = drawFractalLine(gw, pt, r / 3, theta, order - 1);
      pt = drawFractalLine(gw, pt, r / 3, theta + 60, order - 1);
      pt = drawFractalLine(gw, pt, r / 3, theta - 60, order - 1);
      return drawFractalLine(gw, pt, r / 3, theta, order - 1);
   }
}
