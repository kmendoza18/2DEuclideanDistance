/**
 *  File:     ed.cpp
 *
 *  Author:   Kevin Mendoza <kpmendoza@yahoo.com>
 *
 *  Purpose:  Simple program to calculate Euclidean Distance in a 2D plane
 *
 *  Version:  0.0.0
 **/

 /**
  * Included libraries, definitions, and function declarations
  **/

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

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

double calculation(double x1, double y1, double x2, double y2)
{
    return sqrt( pow( (x1 - x2), 2 ) + pow( (y1 - y2), 2 ) );
}
