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
void userInput(int, vector<double>&, vector<double>&);
void compare(int, vector<double>, vector<double>, int&, int&, double&);
double calculation(double, double, double, double);

int main(void)
{
    int numPoints = 0;
    int pt1, pt2;
    double distance;
    vector<double> x;
    vector<double> y;

    cout << "\nPlease enter number of points: " << endl;
    cin >> numPoints;

    switch (numPoints)
    {
        case 0: {
            cout << "No points? No distance." << endl;
            return 0;
        }
        case 1: {
            cout << "One point? Distance is 0." << endl;
            return 0;
        }
    }

    userInput(numPoints, x, y);

    compare(numPoints, x, y, pt1, pt2, distance);

    cout << "The greatest distance between two points is from point " << pt1 + 1
        << " to point " << pt2 + 1 << " with a distance of " << distance
        << endl;

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
void userInput(int numPoints, vector<double> &x, vector<double> &y)
{
    double tempX = 0;
    double tempY = 0;

    for (int i = 0; i < numPoints; i++)
    {
        cout << "\nPlease enter coordiantes for point " << i + 1 << " (x y): "
            << endl;
        cin >> tempX >> tempY;
        x.push_back(tempX);
        y.push_back(tempY);
    }

    cout << endl;
}

/**
 *  Function that compares distances between sets of points
 *
 *  @param  -   numPoints: number of points
 *              x: vector containing x coords for all points
 *              y: vector containing y coords for all points
 *              pt1: first point in longest distance pair
 *              pt2: second point in longest distance pair
 *              distance: distance between pt1 & pt2
 *
 *  @return -   Returns points of greatest distance and distance value
 **/
void compare(int numPoints, vector<double> x, vector<double> y, int &pt1,
    int &pt2, double &distance)
{
    double prevCalc = 0;
    double temp = 0;

    for (int i = 0; i < numPoints; i++)
    {
        for (int j = i + 1; j < numPoints; j++)
        {
            temp = calculation( x.at(i), y.at(i), x.at(j), y.at(j) );
            cout << "Distance from point " << i + 1 << " to point " << j + 1 <<
                ": " << temp << endl;

            if (temp > prevCalc)
            {
                prevCalc = temp;
                pt1 = i;
                pt2 = j;
                distance = temp;
            }
        }
    }

    cout << endl;
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
