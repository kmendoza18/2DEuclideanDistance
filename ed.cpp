/**
 *  File:     ed.cpp
 *
 *  Author:   Kevin Mendoza <kpmendoza@yahoo.com>
 *
 *  Purpose:  Simple program to calculate Euclidean Distance in a 2D plane
 *
 *  Version:  1.0.0
 *
 *  Version History:
 *      - 1.0.0 - Basic code and calculations
 *      - 1.0.1 - Formatting fixes and documentation
 **/

 /**
  * Included libraries, definitions, and function declarations
  **/

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

/* Function Declarations */
double calculation(double, double, double, double);

int main(void)
{
    double x1, x2, y1, y2;

    cout << "\nPlease enter coordiantes for point 1 (x1 y1): " << endl;
    cin >> x1 >> y1;

    cout << "\nPlease enter coordinates for point 2 (x2 y2): " << endl;
    cin >> x2 >> y2;

    cout << "\nEuclidean Distance: " << endl;
    cout << calculation(x1, y1, x2, y2) << endl;
}

/**
 *  Function that calculates distance between two points
 *
 *  @param  -   x1: x coordinate for first point
 *              y1: y coordinate for first point
 *              x2: x coordinate for second point
 *              y2: y coordinate for second point
 *
 *  @return -   Returns value of distance between point one and point two
 **/
double calculation(double x1, double y1, double x2, double y2)
{
    return sqrt( pow( (x1 - x2), 2 ) + pow( (y1 - y2), 2 ) );
}
