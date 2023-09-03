// Programmer: Devin Thomeczek
// MST Username: djtpfr
// Section: 101
// Date: 4/2/2020
// File: rand_walk.h
// Purpose: To produce a randomly generated walking pattern for Willie

#include "rand_walk.h"

int main()
{
  srand(time(NULL));

  const int SEGMENT_AMOUNT = 51; // Set to 51 to account for the points
																 // necessary for 50 segments
  const int WALK_AMOUNT = 100; // The number of walks to be performed

  coords walked[SEGMENT_AMOUNT]; // Array for the coordinate values
  double walk_dist[WALK_AMOUNT]; // Array for the distances of each walk
  double avg_dist; // Used to hold the average distance value
  double med_dist; // Used to hold the median distance value
  
  walked[0].m_xcoord = 0; // Starting x-coordinate of 0
  walked[0].m_ycoord = 0; // starting y-coordinate of 0

  for (int i = 0; i < WALK_AMOUNT; i++)
  {
    randomSegment(walked, SEGMENT_AMOUNT);
    walk_dist[i] = distanceWalk(walked[50]);
  }

  arraySort(walk_dist, WALK_AMOUNT);

  avg_dist = distanceAverage(walk_dist, WALK_AMOUNT);

  med_dist = medianValue(walk_dist, WALK_AMOUNT);

  cout << endl << endl;
  cout << "The average distance is: " << avg_dist << " feet." << endl;
  cout << "The median distance is: " << med_dist << " feet." << endl;
  cout << "The shortest distance is: " << walk_dist[0] << " feet." << endl;
  cout << "The longest distance is: " << walk_dist[99] << " feet." << endl;

  return 0;
}