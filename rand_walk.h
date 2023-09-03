#ifndef RAND_WALK_H
#define RAND_WALK_H

// Programmer: Devin Thomeczek
// MST Username: djtpfr
// Section: 101
// Date: 4/2/2020
// File: rand_walk.h
// Purpose: Function prototypes

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

struct coords
{
  double m_xcoord;
  double m_ycoord;
};

// The angleRads() generates a random degree value and converts it to radians
// Pre: None
// Post: Returns a radian value for an angle
double angleRads();

// The randomSegment() generates the coordinate values for each point in a
// given walk
// Pre: arr_size must be a positive value
// Post: Generates a random segment based on a random angle and distance 50
// times
void randomSegment(coords arr[], const int arr_size);

// The distanceWalk() calculates the distance in a straight line from the
// start point to the end point
// Pre: last_point must consist of positive coordinate values
// Post: Returns the total distance walked
double distanceWalk(const coords last_point);

// The arraySort() takes in the array of distances and sorts them from least
// to greatest
// Pre: arr_size must be a positive value
// Post: Passes back a sorted array of values
void arraySort(double arr[], const int arr_size);

// The distanceAverage() takes in the sorted array of values and determines
// the average of the distances
// Pre: arr_size must be a positive value
// Post: Returns the average value of the distances
double distanceAverage(const double arr[], const int arr_size);

// The medianValue() takes in the sorted array of values and determines the
// average of the distances
// Pre: arr_size must be a positive value
// Post: Returns the median value of the distances
double medianValue(const double arr[], const int arr_size);

#endif
