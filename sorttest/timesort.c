#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "sort.h"

/** Program which takes an array of integers, prints it,
 * sorts it, prints it again, and reports how long the sorting took.
 * @param a Array of integers.
 * @param count Number of integers in the array.
 * @param which number to determine which sort function to use
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

void timesort (int a[], int count, int which) {

  struct timeval start_time; // time stamps for start and end of sorting
  struct timeval end_time;
  struct timeval sort_time; // Elapsed time while sorting

  printf("Unsorted array:\n");
  print_int_array(a, count);

  //if which is 2, use sortPointer to sort
  gettimeofday(&start_time, NULL); // Get timestamp
  if (which == 2){
	  sortPointer(a,count);
  }
  //if which is 3, use sortIcremPointer to sort
  if (which == 3) {
	  sortIcremPointer(a,count);
  }
  //if which is any other number, use sort_descending to sort
  else{
  	  sort_descending(a, count);
  }
  gettimeofday(&end_time, NULL); // Get timestamp

  printf("Sorted array (descending order):\n");
  print_int_array(a, count);

  printf("Timestamp before sorting: ");
  print_timeval(start_time); 
  printf("Timestamp after sorting: ");
  print_timeval(end_time);
  sort_time = timediff(start_time, end_time);
  printf("Time spent sorting: ");
  print_timeval(sort_time); 

  return; // nothing to return
}
