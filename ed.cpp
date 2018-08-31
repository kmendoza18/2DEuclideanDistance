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
 *      - 1.0.0 -   Basic code and calculations
 *      - 1.0.1 -   Formatting fixes and documentation
 *      - 2.0.0 -   Emphasizing functional decomposition and added support for
 *                  multiple point calculations
 **/

 /**
  * Included libraries, definitions, and function declarations
  **/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

/* Function Declarations */
void userInput(int, vector<int>&, vector<double>&, vector<double>&);
double calculation(double, double, double, double);

int main(void)
{
    int numPoints = 0;
    vector<int> point;
    vector<double> x;
    vector<double> y;

    cout << "\nPlease enter number of points: " << endl;
    cin >> numPoints;

    userInput(numPoints, point, x, y);

    return 0;
}

/**
 *  Function to retrieve user input
 *
 *  @param  -   numPoints: number of coordinates to calculate
 *              point: pointer to the description of the coordinate (point #)
 *              x: pointer to a vector of X-coordinates
 *              y: pointer to a vector of Y-Coordinates
 *
 *  @return -   None. Pass by reference
 **/
void userInput(int numPoints, vector<int> &point, vector<double> &x,
    vector<double> &y)
{
    double tempX = 0;
    double tempY = 0;

    for (int i = 0; i < numPoints; i++)
    {
        cout << "\nPlease enter coordiantes for point " << i + 1 << " (x y): "
            << endl;
        cin >> tempX >> tempY;
        point.push_back(i);
        x.push_back(tempX);
        y.push_back(tempY);
    }
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
