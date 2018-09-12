/**
 *  File:     ed.cpp
 *
 *  Author:   Kevin Mendoza <kpmendoza@yahoo.com>
 *
 *  Purpose:  Simple program to calculate Euclidean Distance in a 2D plane. Will
 *            add more functionality as time passes. As of 09/12/2018, program
 *            will be put on hiatus to focus on other projects.
 *
 *  Version:  3.0.0
 *
 *  Version History:
 *      - 1.0.0 -   Basic code and calculations
 *      - 1.0.1 -   Formatting fixes and documentation
 *      - 2.0.0 -   Emphasizing functional decomposition and added support for
 *                  multiple point calculations
 *      - 2.0.1 -   More functional decomposition. Fixed errors in description.
 *                  Added doccumentation to functions. Changes to functionality.
 *      - 3.0.0 -   Added Menu for user choices as well as code to calculate
 *                  distances touching all points
 *
 *  Future Plans:
 *  -   Find longest/shortest distance between all points in
 *      descending/ascending order?
 *  -   Add to readme
 *  -   More functions/purpose
 **/

 /**
  * Included libraries, definitions, and function declarations.
  **/

#include <iostream>
#include <stdlib.h>
#include <float.h>
#include <vector>
#include <math.h>

using namespace std;

#define MAX DBL_MAX

/* Function Declarations */
int menu();
void userInput(int&);
void coordinates(int, vector<double>&, vector<double>&);
void compare(int, int, vector<double>, vector<double>, int&, int&, double&);
double calculation(double, double, double, double);
bool inputValidation(int);
void output(int, int, int, double);

int main(void)
{
    /* Local Variable Declarations */
    int numPoints = 0;
    int pt1, pt2;
    int choice = menu();
    double distance;
    vector<double> x;
    vector<double> y;

    switch ( choice )
    {
        case 1: {
            userInput(numPoints);
            coordinates(numPoints, x, y);
            compare(numPoints, choice, x, y, pt1, pt2, distance);
            output(choice, pt1, pt2, distance);
            break;
        }
        case 2: {
            userInput(numPoints);
            coordinates(numPoints, x, y);
            compare(numPoints, choice, x, y, pt1, pt2, distance);
            output(choice, pt1, pt2, distance);
            break;
        }
        case 0: {
            cout << "\nClosing Program..." << endl;
            break;
        }
    }

    return 0;
}

/**
 *  Function that outputs tasks for user to choose from
 *
 *  @return -   Operation choice (integer)
 **/
int menu()
{
    int choice = 0;

    cout << endl;
    cout << "Please enter your choice of task: " << endl;
    cout << "1) Shortest Distance Calculator (Direct)" << endl;
    cout << "2) Longest Distance Calculator (Direct)" << endl;
    cout << "0) Exit Program" << endl;
    cout << endl;
    cout << "Choice:" << endl;
    cin >> choice;

    return choice;
}

/**
 *  Function that retrieves any user input
 *
 *  @param  -   numPoints: number of coordinates to calculate
 *
 *  @return -   None. Pass by reference
 **/
void userInput(int &numPoints)
{
    cout << "\nPlease enter number of points: " << endl;
    cin >> numPoints;

    if (!inputValidation(numPoints))
    {
        exit(0);
        cout << "NULL" << endl; // Makes Sure of Full Exit
    }
}

/**
 *  Function to retrieve coordinates for points on 2D plane
 *
 *  @param  -   numPoints: number of coordinates to calculate
 *              point: pointer to the description of the coordinate (point #)
 *              x: pointer to a vector of X-coordinates
 *              y: pointer to a vector of Y-Coordinates
 *
 *  @return -   None. Pass by reference
 **/
void coordinates(int numPoints, vector<double> &x, vector<double> &y)
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
 *  @return -   Returns points of shortest/longest distance and distance value
 **/
void compare(int numPoints, int choice, vector<double> x, vector<double> y,
    int &pt1, int &pt2, double &distance)
{
    double prevCalc = 0;
    double temp = 0;

    if (choice == 1)
    {
        prevCalc = MAX;
    }

    for (int i = 0; i < numPoints; i++)
    {
        for (int j = i + 1; j < numPoints; j++)
        {
            temp = calculation( x.at(i), y.at(i), x.at(j), y.at(j) );
            cout << "Distance from point " << i + 1 << " to point " << j + 1 <<
                ": " << temp << endl;

            /* Shortest Distance */
            if (temp < prevCalc && choice == 1)
            {
                prevCalc = temp;
                pt1 = i;
                pt2 = j;
                distance = temp;
            }

            /* Longest Distance */
            if (temp > prevCalc && choice == 2)
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

/**
 *  Function that determines if user input is valid
 *
 *  @param  -   numPoints: number of points
 *
 *  @return -   Returns true if input is valid, otherwase returns false
 **/
bool inputValidation(int numPoints)
{
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

    return 1;
}

/**
 *  Function that outputs results
 *
 *  @param  -   pt1:        first point in pair
 *              pt2:        second point in pair
 *              distance:   distance from point 1 to point 2
 *
 *  @return -   VOID
 **/
void output(int choice, int pt1, int pt2, double distance)
{
    if ( choice == 1 )
    {
        cout << "The shortest distance between two points is from point " <<
            pt1 + 1 << " to point " << pt2 + 1 << " with a distance of " <<
            distance << endl;
    }
    else
    {
        cout << "The longest distance between two points is from point " <<
            pt1 + 1 << " to point " << pt2 + 1 << " with a distance of " <<
            distance << endl;
    }
}
