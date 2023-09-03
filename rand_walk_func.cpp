// Programmer: Devin Thomeczek
// MST Username: djtpfr
// Section: 101
// Date: 4/2/2020
// File: rand_walk_func.cpp
// Purpose: Function definitions

#include "rand_walk.h"

double angleRads()
{
  const int VAL_RANGE = 360; // The max degrees in a circle

  double radians; // Used for the radian value
  int degrees; // Used for the degree value

  degrees = rand() % VAL_RANGE;
  radians = degrees * (M_PI / 180);

  return radians;
}

void randomSegment(coords arr[], const int arr_size)
{
  const int VAL_RANGE = 21; // The size of the range of values for distances

  double radians; // Used for the radian value
  int distance; // Used for the distance value
  
  for (int i = 1; i < arr_size; i++)
  {
    radians = angleRads();
    distance = (rand() % VAL_RANGE);

    // Sets the next x and y coordinate to continue calculations throughout
    // the rest of the array
    arr[i].m_xcoord = distance * cos(radians) + arr[i - 1].m_xcoord;
    arr[i].m_ycoord = distance * sin(radians) + arr[i - 1].m_ycoord;
  }

  return;
}

double distanceWalk(const coords last_point)
{
  double total_distance = 0; // Used for the total of all added distances

  total_distance = sqrt(pow(last_point.m_xcoord, 2) + 
  pow(last_point.m_ycoord, 2));

  return total_distance;
}

void arraySort(double arr[], const int arr_size)
{
  double temp; // Temporary variable for swapping

  for (int i = 0; i < arr_size - 1; i++)
  {
    for (int j = i + 1; j < arr_size; j++)
    {
      temp = 0;
      if (arr[i] > arr[j])
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  return;
}

double distanceAverage(const double arr[], const int arr_size)
{
  double overall_distance = 0; // Used for holding the overall distance
  double average_distance = 0; // Used for holding the average distance

  for (int i = 0; i < arr_size; i++)
  {
    overall_distance += arr[i];  
  }
  
  average_distance = overall_distance / arr_size;
  
  return average_distance;
}

double medianValue(const double arr[], const int arr_size)
{
  const int FIND_MEDIAN = 2; // Used to check whether the index is even or odd

  int mid_index; // Used for the middle index value
  double median_val; // Used for the median value

  mid_index = arr_size / FIND_MEDIAN;

  if (arr_size % FIND_MEDIAN == 0)
  {
    median_val = (arr[mid_index] + arr[mid_index - 1]) / 
    static_cast<double>(FIND_MEDIAN);
  }
  else
  {
    median_val = arr[mid_index];
  }
  return median_val;
}